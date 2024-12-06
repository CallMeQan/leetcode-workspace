#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; // Optional: Modular arithmetic for large Fibonacci numbers.

struct Matrix {
    long long mat[2][2];

    // Constructor to initialize the matrix
    Matrix(long long a = 1, long long b = 1, long long c = 1, long long d = 0) {
        mat[0][0] = a; mat[0][1] = b;
        mat[1][0] = c; mat[1][1] = d;
    }

    // Overload the multiplication operator for matrix multiplication
    Matrix operator*(const Matrix &other) const {
        Matrix result;
        result.mat[0][0] = (mat[0][0] * other.mat[0][0] + mat[0][1] * other.mat[1][0]) % MOD;
        result.mat[0][1] = (mat[0][0] * other.mat[0][1] + mat[0][1] * other.mat[1][1]) % MOD;
        result.mat[1][0] = (mat[1][0] * other.mat[0][0] + mat[1][1] * other.mat[1][0]) % MOD;
        result.mat[1][1] = (mat[1][0] * other.mat[0][1] + mat[1][1] * other.mat[1][1]) % MOD;
        return result;
    }
};

// Function to perform matrix exponentiation
Matrix matrixExpo(Matrix base, long long exp) {
    Matrix result(1, 0, 0, 1); // Identity matrix
    while (exp > 0) {
        if (exp % 2 == 1) {    // If the exponent is odd
            result = result * base;
        }
        base = base * base;    // Square the base
        exp /= 2;
    }
    return result;
}

// Function to calculate the nth Fibonacci number
long long fibonacci(long long n) {
    if (n == 0) return 0;  // Base case
    if (n == 1) return 1;  // Base case

    Matrix fibMatrix(1, 1, 1, 0);
    Matrix result = matrixExpo(fibMatrix, n - 1);

    return result.mat[0][0]; // The top-left element gives F(n)
}

int main() {
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "F(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}
