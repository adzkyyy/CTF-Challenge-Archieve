# Roger Sumatra

**Category:** Cryptography

## Description
> I'm being tired with roger sumatra these days, but yeah here we go the absurd meme

- [chall.py](public/chall.py)

## Poc

Sebuah challenge yang mengimplementasikan knapsack problem dimana diberikan array `A = {a_0, a_1 . . . a_n}` dan sebuah bilangan `s = sum{i=0}^n {a_i.e_i}`. Menentukan ada atau tidaknya subset dari `A` yang akan di`sum` menjadi sebuah bilangan `s`, `e = {e_0, e_1 . . . e_n} ∈ {0, 1}^n`

### Overview

Fungsi `generate()` menghasilkan 3 return variable `what, rahasia, res` yang masing" memliki fungsi
- what : generate bilangan random dari `max` value sebanyak `n`
- rahasia : generate bilangan basis 2 sebanyak `n`
- res : `sum` dari index `what` berdasarkan dari value `rahasia`

Fungsi `aku_mau_flag_dong()` menggunakan `rahasia` untuk menggenerate `char` berdasarkan index

### Problem
menebak variable rahasia yang merupakan random number basis 2 

### Solve

Challenge ini merefer pada `Low Density Attack` karena variable `d` (density) yang digunakan tergolong kecil hanya `0.6` yang dapat di crack menggunakan algoritma Coster, Joux, LaMacchia, Odlyzko, Schnorr, and Stern (CJLOSS) untuk mencari variable `rahasia`

Referensi dari salah satu repository milik dewa crypto 

https://github.com/hyunsikjeong/LLL/blob/master/low-density-attack/LowDensityAttack.sage

Mencari vektor untuk sebuah `e = (e_0, e_1 . . . , e_n) ∈ {0, 1}^n` dengan membuat Lattice dan menggunakan algoritma LLL

dapat dilihat pada [solver.py](solver.py)

### Flag
```
TECHCOMFEST23{https://shorturl.at/cjkE0}
```
