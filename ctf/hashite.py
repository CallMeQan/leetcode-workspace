from Crypto.Util.number import GCD
from Crypto.Cipher import AES
import random

def modular_exponentiation(base, exp, mod):
    result = 1
    base %= mod
    while exp > 0:
        if exp % 2 == 1:  # If exp is odd
            result = (result * base) % mod
        exp //= 2
        base = (base * base) % mod
    return result

# Inputs
a1 = 721919140332708275664160621428853988653441049264644517303176376909
a2 = 762740838008948738628397951381835990843814483667554565638672490531
k1 = 762740838008948738628397951381835990843814483667554465638672490531
k2 = 721919140332708275664160621428853988653441049264544517303176376909
k3 = 100000000000000000
k4 = 100000000000000
mod = 10^9+7  # Use a large prime modulus

# Simplify exponents
e1 = a1 + k2 + k3
e2 = a2 + k1 + k4

# Modular exponentiation
b1_mod = modular_exponentiation(2024, e1, mod) - 1
b2_mod = modular_exponentiation(2024, e2, mod) - 1

# Handle negative results
b1_mod = (b1_mod + mod) % mod
b2_mod = (b2_mod + mod) % mod

# Compute GCD
k = GCD(b1_mod, b2_mod)

# Use GCD as seed to generate AES key
random.seed(k)
key = random.randbytes(16)

# AES decryption
iv = b"S\x0f\xac'\xd0\x18\xfb\xe3\x92\xfdoc\x93\x7fJ\xfc"
ciphertext = b"\x98\xd0\x8f;\xaa\x07\x1dJ\x9d#\\>\xa6\x14\x97$\xd7\xfb^1\xc2\x9f6\x04i\xb08\x85\x03=\xd5)"
cipher = AES.new(key=key, iv=iv, mode=AES.MODE_CBC)

flag = cipher.decrypt(ciphertext)
print(flag)
