# hanacaraka

**Category:** Reverse Engineering

## Description
> Ayo lestarikan aksara jawa sebagai warisan budaya Indonesia

- [chall.zip](chall.zip)

## Poc

Sebuah challenge reverse menggunakan aksara jawa

### Overview
Ini merupakan soal obfuscated python code menggunakan sawa language https://github.com/lantip/sawa

### Solve

Untuk mendapatkan clean python codenya kita dapat memparsing dari https://github.com/lantip/sawa/blob/main/sawa/main.py (cukup dibalik pada dictionarynya) yang nantinya menjadi seperti 

```python
from libnum import n2s as e393789, s2n as e939733
from random import randint as e806217, randbytes as e204915
from secret import flag as e5025951
e511911 = lambda e704706: e704706 if e704706 <= 1 else e511911(e704706 - 1) + e511911(e704706 - 2)
e812342 = lambda e688213,e348921: int(str(e511911(int(str(e688213))) + e511911(int(str(e348921)))) + str(e511911(int(str(e348921))) + e511911(int(str(e688213))))) * int(str(e511911(int(str(e348921))) + e511911(int(str(e688213)))) + str(e511911(int(str(e688213))) + e511911(int(str(e348921)))))
e9991283 = lambda e663482,e112418,e199700,e142985,e334657,e475658,e105148,e400880,e545848,e718936:e663482*e112418+e199700//e142985-e334657^e718936+e475658//e105148^e400880*e545848
e123851 = e939733(e5025951) << sum([e965916 for e965916 in range(e806217(e806217(0,50),e806217(50,100)))])
e843915 = e9991283(6969696969,e511911(500),e123851,13,-323129992199354,e511911(100),pow(e939733('63848936301258'),e939733(b'993912942412'),e939733('1029385868923')),37,e812342(100,120),e939733(b'TECHCOMPFEST2023{reversing_aksara_jawa_is_too_ezpz_for_u}'))
with open('aksara.java','w') as f:
    print(e843915, file=f)
```
Terlihat masih jelek dan susah dibaca untuk sebuah python code karena variable"nya terobfuscated dengan

coba gunakan teknik find and replace

```python
from libnum import n2s, s2n
from random import randint , randbytes 
from secret import flag

func1 = lambda x: x if x <= 1 else func1(x - 1) + func1(x - 2)

func2 = lambda x,y: int(str(func1(int(str(x))) + func1(int(str(y)))) + str(func1(int(str(y))) + func1(int(str(x))))) * int(str(func1(int(str(y))) + func1(int(str(x)))) + str(func1(int(str(x))) + func1(int(str(y)))))

func3 = lambda a,b,c,d,e,f,g,h,i,j:a*b+c//d-e^f+g//h^i*j

enc = s2n(flag) << sum([i for i in range(randint(randint(0,50),randint(50,100)))])

output = func3(6969696969,func1(500),enc,13,-323129992199354,func1(100),pow(s2n('63848936301258'),s2n(b'993912942412'),s2n('1029385868923')),37,func2(100,120),s2n(b'TECHCOMPFEST2023{reversing_aksara_jawa_is_too_ezpz_for_u}'))

with open('aksara.java','w') as f:
    print(output, file=f)
```

`func1` merupakan fungsi fibonacci tetapi menggunakan recursion yang saat dieksekusi akan sangat lama

`func2` bergantung pada `func1` 

`func3` hanya fungsi matematika dasar (tambah, kurang, kali, bagi, dan xor)

Untuk merekonstruksi fungsi fibonacci tanpa recursion menjadi
```python
def fib(n, c = {0:0,1:1}):
    if n not in c:
        c[n] = fib(n-1,c) + fib(n-2,c)
    return c[n]
```
Reverse aritmatika tersebut dengan berdasar pada prioritas operator python

1) `* / % //`
2) `+ -`
3) `^`

Karena nilai yang digunakan static semua (tanpa random), kita dapat mereverse perhitungan dari variable `out`

`x = func2(100,120) *  s2n(b'TECHCOMPFEST2023{reversing_aksara_jawa_is_too_ezpz_for_u}')`

`y = func1(100) + pow(s2n('63848936301258'),s2n('993912942412'),s2n('1029385868923')) // 37`

`enc = (out ^ x ^ y - 6969696969 * func2(100) - 323129992199354) * 13`

Setelah itu, tinggal bruteforce variable enc yang di right shift `<<` dari sum range `n` number dengan membaliknya menggunakan left shift `>>`

Full solver [solver.py](solver.py)

### Flag
```
TECHCOMFEST23{Nicee_:P_rev_aksara_is_actually_just_matematika_dasar}
```
