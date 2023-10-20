# CryptGPT

**Category:** Reverse Engineering

## Description
> Vestia Zeta just build a custom binary packer called bazo_packer, then she packed CryptGPT binary for no reason. Oiya flagny diencrypt pake CryptGPT

> fyi: Pembuatan soal ini 63.8% dibantu oleh ChatGPT dan nonton Vestia Zeta 😍🥰

- [CryptGPT.zeta](public/CryptGPT.zeta)
- [bazopacker](public/bazo_packer)
- [flag.enc](public/flag.enc)

## Solver

1. Jika diamati, elf dipack dengan xor yang keynya diambil dari sha256 dari nama file sebelum dipack yaitu "CryptGPT". Jadi keynya adalah SHA256("CryptGPT")
2. Karena selain fungsi pack, juga terdapat fungsi unpack dengan nama get_upk()
3. Patch fungsi packed dengan get_upk untuk decrypt file CryptGPT.zeta
4. Setelah itu didapatkan file elf CryptGPT yang digunakan untuk mengenkripsi string dengan menggunakan algoritma El-gamal
5. Lanjut pada script [solver.py](solver.py)

### Flag
```
TECHCOMFEST23{p4ck3r+3lg4m4l???....wait_that's_illegal}
```
