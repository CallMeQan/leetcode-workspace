# Crypto is outdated. Use Cryptodome instead (bruh)
from Crypto.Util.number import *
from Crypto.Cipher import AES

import random, sys

def mod_exp(x, n, m):
    result = 1
    x %= m 
    while n > 0:
        if n % 2 == 1:
            result = (result * x) % m
        x = (x * x) % m
        n //= 2
    return result

a1 = 721919140332708275664160621428853988653441049264644517303176376909
a2 = 762740838008948738628397951381835990843814483667554565638672490531

k1 = 762740838008948738628397951381835990843814483667554465638672490531
k2 = 721919140332708275664160621428853988653441049264544517303176376909
k3 = 100000000000000000
k4 = 100000000000000

sys.set_int_max_str_digits(100000000)
# print(a1 + k2 + k3)
# print(a2 + k1 + k4)
tmp = GCD(a1 + k2 + k3, a2 + k1 + k4)
k = 2024 ** tmp - 1

# b1 = mod_exp(2024, (a1 + k2 + k3), 2**256 - 1) - 1
# b2 = mod_exp(2024, (a2 + k1 + k4), 2**256 - 1) - 1

# k = GCD(b1, b2)

random.seed(k)
k = random.randbytes(16)
iv = b"S\x0f\xac'\xd0\x18\xfb\xe3\x92\xfdoc\x93\x7fJ\xfc"
ciphertext = b"\x98\xd0\x8f;\xaa\x07\x1dJ\x9d#\\>\xa6\x14\x97$\xd7\xfb^1\xc2\x9f6\x04i\xb08\x85\x03=\xd5)"

cipher = AES.new(key=k, iv=iv, mode=AES.MODE_CBC)
flag = cipher.decrypt(ciphertext)
print(flag)
