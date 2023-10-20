from pwn import *
from sage.all import *
import random,hashlib,string

roger = [12407953253235233563, 3098214620796127593, 18025934049184131586, 14516706192923330501, 13439587873423175563, 17668371729629097289, 4983820371965098250, 1941436363223653079, 15491407246309500298, 8746935775477023498, 911995915798699052, 16286652540519392376, 13788248038504935294, 18140313902119960073, 11357802109616441330, 2498891881524249135, 9088680937359588259, 14593377776851675952, 2870989617629497346, 18249696351449250369, 2029516247978285970, 14734352605587851872, 8485311572815839186, 8263508188473851570, 14727305307661336083, 6229129263537323513, 17136745747103828990, 8565837800438907855, 17019788193812566822, 9527005534132814755, 1469762980661997658, 16549643443520875622, 9455193414123931504, 12209676511763563786, 271051473986116907, 17058641684143308429, 13420564135579638218, 7599871345247004229]
sumatra = 35605255015866358705679
#p = remote('localhost', 5000)
#p.recvuntil(b'rahasianya\n')
#roger = p.recvuntil(b']').strip()
#exec(roger)
#p.recvline()
#sumatra = p.recvline().strip()
#exec(sumatra)
#char = string.ascii_letters + string.digits

class CJLOSS:
    def __init__(self, array, target_sum):
        self.array = array
        self.n = len(self.array)
        self.target_sum = target_sum

    def _check_ans(self, ans):
        calc_sum = sum(map(lambda x: x[0] * x[1], zip(self.array,ans)))
        return self.target_sum == calc_sum
    
    def solve(self):
        L = Matrix(ZZ, self.n + 1, self.n + 1)
        N = ceil(self.n ** 0.5 / 2)
        for i in range(self.n + 1):
            for j in range(self.n + 1):
                if j == self.n and i < self.n:
                    L[i,j] = 2 * N * self.array[i]
                elif j == self.n:
                    L[i,j] = 2 * N * self.target_sum
                elif i == j:
                    L[i,j] = 2
                elif i == self.n:
                    L[i,j] = 1
                else:
                    L[i,j] = 0
        B = L.LLL()
        for i in range(self.n + 1):
            if B[i, self.n] != 0:
                continue
            if all(v == -1 or v == 1 for v in B[i][:self.n]):
                ans = [(-B[i,j] + 1) // 2 for j in range(self.n)]
                if self._check_ans(ans):
                    return ans
        return None

def aku_mau_flag_dong(rahasia):
    w0w = ""
    i = 0
    while i < len(rahasia)*2:
        w0w += char[i] if rahasia[i % len(rahasia)] else ""
        i += 1
    return w0w

test = CJLOSS(roger,sumatra)
rahasia = aku_mau_flag_dong(test.solve())
print(rahasia)
p.sendlineafter(b'= ', rahasia.encode())

print(p.recvline())
'''
$ python3 solver.py
[+] Opening connection to localhost on port 5000: Done
adhjqrsvxyzABCEFIMOVWX02345679
b'hadehhh TECHCOMFEST23{https://shorturl.at/cjkE0}\n'
[*] Closed connection to localhost port 5000
'''
