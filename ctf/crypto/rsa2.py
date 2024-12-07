from math import gcd
import random

def pollards_rho(n):
    """
    Pollard's Rho algorithm for integer factorization.
    """
    if n % 2 == 0:
        return 2  # Handle even numbers directly
    x = random.randint(2, n - 1)
    y = x
    c = random.randint(1, n - 1)
    d = 1

    while d == 1:
        x = (pow(x, 2, n) + c) % n
        y = (pow(y, 2, n) + c) % n
        y = (pow(y, 2, n) + c) % n
        d = gcd(abs(x - y), n)

        if d == n:  # Failure, retry with new values
            return None
    return d

def find_prime_factors(n):
    """
    Attempt to find the prime factors of n.
    """
    factor = pollards_rho(n)
    if factor is None or factor == n:
        return None, None  # Failed to factorize
    return factor, n // factor

if __name__ == "__main__":
    # Original n from user
    n = int("117378567124716236236044558241107806605736253057406303459584977215087315697749662980445901987640185615597015856640181841784590874624712744033616578986059075120813449396552360882943977036587199937478038256465488814670708953070327618634265180619676128267728587071877304192349209279829117836107480980367456989279")
    
    # Attempt to find p and q
    print("Factoring n...")
    p, q = find_prime_factors(n)
    if p and q:
        print(f"Found factors:\np = {p}\nq = {q}")
    else:
        print("Failed to factorize n.")
