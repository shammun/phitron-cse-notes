// Topic: printing a decimal number with an exact number of digits after the point,
// using 'fixed' and 'setprecision' (the C++ version of printf("%.5f")).
// Output: 23.45676

#include <iostream>  // For standard input and output streams (cin, cout)
#include <iomanip>   // For I/O manipulators like 'fixed' and 'setprecision'
// #include <stdio.h> // Required in C for printf; also available in C++ via <cstdio>

using namespace std; // Allows using cout, endl, etc., without 'std::' prefix

// main() is where the program starts running.
int main() {
    double d = 23.45676; // A double (decimal number) with 5 digits after the point

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
     * 0. With nothing:
     *    cout << d << endl;
     *    -> cout shows at most 6 significant digits by default: 23.4568
     *
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
     *
     * Both 'fixed' and 'setprecision' are "sticky": once sent to cout they stay
     * in effect for every later number printed, until changed again.
     * ------------------------------------------------------------- */

    // C++ formatted output:
    // fixed -> count digits after the point; setprecision(5) -> 5 of them; then print d and a newline.
    cout << fixed << setprecision(5) << d << endl;

    // Equivalent C code running inside C++ (if <cstdio> is included):
    // printf("%.5f\n", d);

    return 0; // Program ended successfully
}