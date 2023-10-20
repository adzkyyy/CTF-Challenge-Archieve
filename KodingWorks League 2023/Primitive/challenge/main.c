#include <stdio.h>
#include <string.h>

int main(){
        char buf[40];
        printf("flagnya affh? ");
        scanf("%40s",buf);
        if(strncmp(buf,"dont_mind_this_chall_i_ran_out_of_idea",38) == 0){
                puts("benar");
        } else {
                puts("salah");
        }
        return 0;
}
