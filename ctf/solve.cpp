#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>

using namespace std;

// Function to find the GCD (greatest common divisor)
uint64_t gcd(uint64_t a, uint64_t b) {
    while (b) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find modular inverse (Extended Euclidean Algorithm)
uint64_t modInverse(uint64_t e, uint64_t phi) {
    uint64_t t = 0, newT = 1, r = phi, newR = e;
    while (newR != 0) {
        uint64_t quotient = r / newR;
        t -= quotient * newT;
        swap(t, newT);
        r -= quotient * newR;
        swap(r, newR);
    }
    if (r > 1) {
        cerr << "e is not invertible" << endl;
        exit(1);
    }
    return (t < 0) ? t + phi : t;
}

// Function to perform fast modular exponentiation (for decryption)
uint64_t modExp(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)  // If exponent is odd, multiply base with result
            result = (result * base) % mod;
        base = (base * base) % mod;  // Square the base
        exp /= 2;
    }
    return result;
}

// Function to factorize n (brute-force for small numbers)
pair<uint64_t, uint64_t> factorize(uint64_t n) {
    for (uint64_t i = sqrt(n); i > 1; --i) {
        if (n % i == 0) {
            return {i, n / i};
        }
    }
    cerr << "Factorization failed!" << endl;
    exit(1);
}

int main() {
    // Given values (replace with actual challenge values)
    uint64_t n = 30971533301817251554661303445938819750869315107481566288752993922257846531064965673423303586325520196020578469913979296434496542507826890508483867035370042726276008147072697812855533638380598976315875199329578901865230252128592959710565683745366110329450947549969156932570487357988996496056218838631484500141;   // Replace with given `n`
    uint64_t ct = 6925302027244822694568308975832237070423485024070949327561492868535808296720270380289703766299432187118784920284193935728895756846635116574691758876544664711530557122703694409850646274682872579198853413063560890914020985336969337187384743672157688198934321045960978751937610804484002224903547209871187338262;  // Replace with given `ct`
    uint64_t e = 65537;

    cout << "[*] Attempting to factor n..." << endl;
    auto [p, q] = factorize(n);
    cout << "[*] Found primes:\n p = " << p << "\n q = " << q << endl;

    uint64_t phi = (p - 1) * (q - 1);
    uint64_t d = modInverse(e, phi);

    cout << "[*] Decrypting..." << endl;
    uint64_t message = modExp(ct, d, n);

    cout << "[*] Flag: " << message << endl;
    return 0;
}
