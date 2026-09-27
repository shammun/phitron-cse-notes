#include <iostream>  // For standard input and output streams (cin, cout)
#include <iomanip>   // For I/O manipulators like 'fixed' and 'setprecision'
// #include <stdio.h> // Required in C for printf; also available in C++ via <cstdio>

using namespace std; // Allows using cout, endl, etc., without 'std::' prefix

int main() {
    double d = 23.45676;

    /* -------------------------------------------------------------
     * HOW THIS IS DONE IN C:
     * -------------------------------------------------------------
     * In C, floating-point formatting is handled by 'printf' format specifiers:
     * 
     *   printf("%.5f\n", d);
     * 
     * - "%f" prints a floating-point number.
     * - ".5" specifies precision: exactly 5 digits after the decimal point.
     * ------------------------------------------------------------- */

    /* -------------------------------------------------------------
     * HOW THIS IS DONE IN C++:
     * -------------------------------------------------------------
     * 1. Without 'fixed':
     *    cout << setprecision(5) << d << endl;
     *    -> Sets TOTAL significant digits across the entire number.
     *    -> Output: 23.457 (2 digits before dot + 3 digits after = 5 total)
     * 
     * 2. With 'fixed':
     *    cout << fixed << setprecision(5) << d << endl;
     *    -> Forces fixed-point notation (not scientific e.g., 2.34e+01).
     *    -> Changes 'setprecision(N)' to count digits AFTER the decimal point.
     *    -> Matches the behavior of C's 'printf("%.5f", d)'.
     *    -> Output: 23.45676
     * ------------------------------------------------------------- */

    // C++ formatted output:
    cout << fixed << setprecision(5) << d << endl;

    // Equivalent C code running inside C++ (if <cstdio> is included):
    // printf("%.5f\n", d);

    return 0;
}