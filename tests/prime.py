def sieve_of_eratosthenes(n):
    primes = [True] * (n + 1)
    p = 2
    while p * p <= n:
        if primes[p]:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    return [p for p in range(2, n + 1) if primes[p]]

# Example usage:
n = 1000
print(sieve_of_eratosthenes(n))  # Output: [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]