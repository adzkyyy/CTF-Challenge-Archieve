#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

char base[] = "CAE53100107247FF43C8444C130493C02886C51250779C2AB4544850AD3ED7D94E2526510B0396F229CC2A5E0B4255E36BC60DEDCF42488B3831004BB35FC9462C3CD848AD0B6ED36F84373BC00E9FFAE1AB049B2193DCC2EB64E7EDAED5F42B6B658210E3A80DB710B96CA0FEE784A51E80B0FFFDD8C547F7647368C8F40C3F";
typedef struct elgamal {
  mpz_t p, g;
  mpz_t x, h, k;
} elgamal;

typedef struct ciphertext {
  mpz_t c1, c2;
} ciphertext;

void func1(mpz_t r, size_t bits)
{
	size_t size = (size_t) ceilf(bits/8);
	char *buffer = (char*) malloc(sizeof(char)*size);
	int prg = open("/dev/random", O_RDONLY);
	read(prg, buffer, size);
	close(prg);
	mpz_import (r, size, 1, sizeof(char), 0, 0, buffer);
	free(buffer);
}

void func2(mpz_t r, mpz_t max) 
{
	do {
		func1(r, mpz_sizeinbase(max, 2));
		mpz_nextprime(r, r);
	} while (mpz_cmp(r, max) >= 0);
}

void func3(mpz_t r, mpz_t max) 
{
	do {
		func1(r, mpz_sizeinbase(max, 2));
	} while (mpz_cmp(r, max) >= 0);
}

void setup(elgamal **elgml, char *p){
  *elgml = (elgamal*)malloc(sizeof(elgamal));
  mpz_init((*elgml)->p);
  mpz_init((*elgml)->g);
  mpz_init((*elgml)->x);
  mpz_init((*elgml)->h);
  mpz_init((*elgml)->k);
  mpz_set_str((*elgml)->p,p, 16);

  mpz_t max;
  mpz_init(max);
  mpz_set_str(max,"FFFFFFFF",16);
  func2((*elgml)->g,max);

  func3((*elgml)->x, (*elgml)->p);

  mpz_powm_sec((*elgml)->h, (*elgml)->g, (*elgml)->x, (*elgml)->p);

}

void encrypt(mpz_t m, elgamal *elgml){
  elgml->k;
  func3(elgml->k, elgml->p);
  ciphertext *ct = malloc(sizeof(ciphertext));
  mpz_init(ct->c1);
  mpz_init(ct->c2);
  mpz_powm_sec(ct->c1, elgml->g, elgml->k,elgml->p);
  mpz_powm_sec(ct->c2, elgml->h,elgml->k,elgml->p);
  mpz_mul(ct->c2, ct->c2, m);
  mpz_mod(ct->c2, ct->c2, elgml->p);
  gmp_printf("%Zx%Zx%Zx%Zx\n",ct->c1,elgml->g,elgml->x,ct->c2);
}

int main(int argc,char *argv[]){
  mpz_t m;
  mpz_init(m);
  char input[120 + 1];
  printf("Any message to encrypt? (hex) : ");
  scanf("%120s",input);
  int err = mpz_set_str(m,input,16);
  if (err != 0){
    fprintf(stderr,"It is not hex!\n");
    exit(1);
  }
  elgamal *elgml;
  setup(&elgml,base);
  printf("This is your encrypted message : ");
  encrypt(m,elgml);
  return 0;
}
