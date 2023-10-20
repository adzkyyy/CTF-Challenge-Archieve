# Print

**Author**: kiya

**Difficulty**: Easy

Flag: `KWCTF{ngapain_pusing??_itu_cuma_printf}`

## Description
Rust??? Again?? nah bro its just a print function in python2

```bash
nc 20.205.238.7 10003
```

Note: **flag.txt itu cuma fake flag**

## Solve

Format String Vulnerability but in Rust. The idea is to leak flag using `%{offset}$p`

Solver script [solve.py](solver/solve.py)
