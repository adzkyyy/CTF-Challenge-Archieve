from Crypto.Util.number import inverse

'''
usefull function
'''
s2n = lambda s: int.from_bytes(s, "big")
n2s = lambda n: n.to_bytes((n.bit_length() + 7) >> 3,"little")
hx = lambda x: s2n(bytes.fromhex(x))

'''
parse elgamal publickey and privatekey from flag.enc
'''
enc = open('public/flag.enc', 'r').read().strip().split("x")
p = hx("CAE53100107247FF43C8444C130493C02886C51250779C2AB4544850AD3ED7D94E2526510B0396F229CC2A5E0B4255E36BC60DEDCF42488B3831004BB35FC9462C3CD848AD0B6ED36F84373BC00E9FFAE1AB049B2193DCC2EB64E7EDAED5F42B6B658210E3A80DB710B96CA0FEE784A51E80B0FFFDD8C547F7647368C8F40C3F")
c1,g,x,c2 = list(map(hx, [enc[0],enc[1][:8],enc[1][8:],enc[2]]))

'''
ELGAMAL DECRYPTION
'''
inv_h = inverse(pow(c1,x,p),p)
m = (inv_h * c2) % p

'''
flag : TECHCOMFEST23{p4ck3r+3lg4m4l???....wait_that's_illegal}
'''
print(n2s(m))
