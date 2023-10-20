#ifndef __elf_packer_h__
#define __elf_packer_h__ 1

#include <elf.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <malloc.h>

typedef struct _section {
    size_t plt_got;
    size_t plt_sec;
    size_t text;
} t_section;

typedef struct _elf64 {
    Elf64_Ehdr *eheader;
    Elf64_Phdr *pheader;
    uint8_t    **sdata;
    Elf64_Shdr *sheader;
} elf64;

// map_elf.c
int section(elf64 *elf, void *pa);
int sheader(elf64 *elf, void *pa);
int eheader(elf64 *elf, void *pa);
int pheader(elf64 *elf, void *pa);
void *map_elf(void *pa);

// pack_elf.c
char *get_section(elf64 *elf, uint16_t idx);
size_t get_section_by_name(elf64 *elf, char *section_name);
int packed_and_mapped_then_write_to_memory(elf64 *elf, size_t fsize, t_section target, char *fname);

// main.c
void *map_file(char *fileame, size_t *ptr_fsize);

#endif