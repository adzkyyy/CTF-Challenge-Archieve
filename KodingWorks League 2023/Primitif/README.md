# Primitif

**Author**: kiya

**Difficulty**: Easy

Flag: `KWCTF{udah_2023_masih_pake_ltrace_gan?}`

## Description
yet another reversing Flag Checker challenge

## Solve
Just ltrace

```bash
$ ltrace ./primitif
printf("passwordnya affh? ")                                                                    = 18
__isoc99_scanf(0x561902c00947, 0x7ffccefad910, 0, 0x561902c00946passwordnya affh? asd
)                               = 1
strncmp("udah_2023_masih_pake_ltrace_gan?"..., "asd", 32)                                       = 20
puts("salah"salah
)                                                                                   = 6
+++ exited (status 0) +++
$ ./primitif
passwordnya affh? udah_2023_masih_pake_ltrace_gan?
benar
$
```
