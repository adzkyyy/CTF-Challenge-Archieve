# Rust

**Author**: kiya

**Difficulty**: Easy

Flag: `KWCTF{semoga_nilai_kita_semua_diatas_kkm,semoga_kita_semua_bisa_naik_kelas,libur_3_minggu_yuhuu}`

## Description
Hi, Im new at Rust pls be kind, any suggest? Feel free to leave a comment
```bash
nc 20.205.238.7 10197
```

## Solve

Buffer Overflow in Rust, just input 500++ bytes to fill buffer till overwrite Feedback.win struct variable. 

If Feedback.win > 0 then it will call /bin/sh

Solver script [solve.py](solver/solve.py)
