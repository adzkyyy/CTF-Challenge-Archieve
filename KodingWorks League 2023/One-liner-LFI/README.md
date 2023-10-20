# One Liner LFI

**Author**: kiya

**Difficulty**: Easy

Flag: `KWCTF{congratss_kamu_akan_diberi_hadiah_yaitu_kecupan_emuachh_dari_zakir_karena_telah_berhasil_menyelesaikan_soal_ini}`

## Description
This is the next challenge after [**One Liner Crypto**](http://178.128.101.5/challenges#One%20Liner%20Crypto-36) from TCP1P

http://20.205.238.7:10762

## Hint
1. [LFI2RCE](https://book.hacktricks.xyz/pentesting-web/file-inclusion/lfi2rce-via-php-filters)
2. php filter chain

## Solve

Challenge dengan 1 baris kode php yang terdapat fungsi `include` didalamnya, hal ini menimbulkan celah [LFI](https://www.acunetix.com/blog/articles/local-file-inclusion-lfi/)

Target peserta yaitu mendapatkan RCE karena minimnya info dimana letak flag

Untuk mendapat RCE, dapat menggunakan teknik [LFI2RCE via PHP Filter](https://book.hacktricks.xyz/pentesting-web/file-inclusion/lfi2rce-via-php-filters) yang sampai saat ini masih relevan

Sudah banyak bacaan mengenai teknik LFI2RCE ini salah satunya pada video youtue berikut [here](https://youtu.be/TnLELBtmZ24)

Solver script [solve.py](solver/solve.py)
