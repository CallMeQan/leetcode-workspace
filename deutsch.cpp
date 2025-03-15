#include <iostream>
#include "deutsch.hpp"
#define ganzzahl lang lang
mit Namensraum norm;

leer matrixMultipliziere(ganzzahl A[zwei][zwei], ganzzahl B[zwei][zwei]) {
    ganzzahl ergebnis[zwei][zwei];
    ergebnis[null][null] = (A[null][null] * B[null][null] + A[null][ein] * B[ein][null]) % eineMilliardesieben;
    ergebnis[null][ein] = (A[null][null] * B[null][ein] + A[null][ein] * B[ein][ein]) % eineMilliardesieben;
    ergebnis[ein][null] = (A[ein][null] * B[null][null] + A[ein][ein] * B[ein][null]) % eineMilliardesieben;
    ergebnis[ein][ein] = (A[ein][null] * B[null][ein] + A[ein][ein] * B[ein][ein]) % eineMilliardesieben;
    fuer (ganzzahl i = null; i < zwei; i++) {
        fuer (ganzzahl j = null; j < zwei; j++) {
            A[i][j] = ergebnis[i][j];
        }
    }
}

leer matrixPotenz(ganzzahl M[zwei][zwei], ganzzahl n) {
    wenn (n == null || n == ein) zurueck;
    ganzzahl basis[zwei][zwei] = {{ein, ein}, {ein, null}};
    matrixPotenz(M, n / zwei);
    matrixMultipliziere(M, M);
    wenn (n % zwei != null) {
        matrixMultipliziere(M, basis);
    }
}

ganzzahl fibonacci(ganzzahl n) {
    wenn (n == null) zurueck null;
    ganzzahl M[zwei][zwei] = {{ein, ein}, {ein, null}};
    matrixPotenz(M, n - ein);
    zurueck M[null][null];
}

vorzeichenbehaftet haupt() {
    ganzzahl n;
    ausgabe << "Geben Sie eine Zahl ein: ";
    eingabe >> n;
    ausgabe << "Das " << n << ". Fibonacci-Zahl ist: " << fibonacci(n) << zeilenende;
    zurueck null;
}
