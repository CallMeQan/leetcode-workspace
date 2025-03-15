from sys import exit
from Crypto.Util.number import long_to_bytes, bytes_to_long, inverse
from Crypto.Util.number import getPrime

def get_primes(k):
    """
    Generates two primes of k bits
    """
    p = getPrime(k)
    q = getPrime(k)
    return p,q

e = 65537

def gen_key(k):
    """
    Generates RSA key with k bits
    """
    p, q = get_primes(k//2)
    N = p*q
    d = inverse(e, (p-1)*(q-1))

    return ((N,e), d) # For some reason, I'm returning the private key too

def encrypt(pubkey, m: str):
    N, e = pubkey
    m_encrypt = bytes_to_long(m.encode())
    c = pow(m_encrypt, e, N)
    return c

def main(flag: str):
    pubkey, _privkey = gen_key(1024) # Why private key not used?
    encrypted = encrypt(pubkey, flag) 
    return (pubkey[0], encrypted)

if __name__ == "__main__":
    #flag = open('flag.txt', 'r').read()
    flag = 'picoCTF{testing}'
    N, cypher  = main(flag)
    print("N:", N)
    print("e:", e)
    print("cyphertext:", cypher)
    exit()

from sympy import mod_inverse


p = 12558842283187327600406717653575563914298399964020828022272560923768346916896018376767923571766086196342038649655540114673794581057996445656830798724093737
q = 2
e = 65537
c = 7075225952781707745991162108844628478828451535138603682943331561821623853634455421225125028270430308364419298331540959201700281643953207185083819390051871
def rsa_decrypt():
    n = p * q
    phi = (p - 1) * (q - 1)
    d = mod_inverse(e, phi)
    m = pow(c, d, n)
    return m

decrypted_message = rsa_decrypt()
print("Decrypted message:", long_to_bytes(decrypted_message))