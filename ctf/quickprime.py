#!/usr/local/bin/python3

from secrets import randbits
from Crypto.Util.number import isPrime
def gen():
    class LCG:
        def __init__(self, a: int, c: int, m: int, seed: int):
            self.a = a
            self.c = c
            self.m = m
            self.state = seed

        def next(self):
            self.state = (self.a * self.state + self.c) % self.m
            return self.state

    while True:
        a = randbits(512)
        c = randbits(512)
        m = 1 << 512
        seed = randbits(512) # unknown
        initial_iters = randbits(16) # unknown but possible to bruteforce
        # https://en.wikipedia.org/wiki/Linear_congruential_generator#m_a_power_of_2,_c_%E2%89%A0_0
        if (c != 0 and c % 2 == 1) and (a % 4 == 1):
            print(f"LCG coefficients:\n\ta = {a}\n\tc = {c}\n\tm = {m}")
            break

    # Skip initial_iters iterations => we need to know the skip value
    L = LCG(a, c, m, seed)
    for _ in range(initial_iters):
        L.next()

    # After skip initial_iters iterations, we continue .next() till we get 2 primes
    P = []
    while len(P) < 2:
        test = L.next()
        if isPrime(test):
            P.append(test)

    p, q = P
    
    n = p * q # Pulbic modulus
    phi = (p - 1) * (q - 1) # phi
    e = 65537 # Public exponent
    d = pow(e, -1, phi) # Private exponent, why unused?
    message = int.from_bytes(open("flag.txt", "rb").read(), "big")
    ct = pow(message, e, n)
    print(f"\tn = {n}")
    print(f"\tct = {ct}")
    print(f"\n|=> Guess these:\n\tp = {p}\n\tq = {q}\n\tphi = {phi}\n\td = {d}")
    return a, c, m, n, ct

a, c, m, n, ct = gen()
print("=================== Solving =========================")
# ==================== Solve part ====================
from Crypto.Util.number import inverse, long_to_bytes, isPrime