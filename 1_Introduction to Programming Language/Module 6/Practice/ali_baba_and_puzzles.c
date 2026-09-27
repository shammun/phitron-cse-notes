// stdio.h ("standard input output") declares scanf and printf; #include
// pastes it in before compiling so the compiler knows those names.
#include<stdio.h>

// Find if d can be achieved by either addition, subtraction or multiplication
// between a, b and c
//
// There are two operator slots, a ? b ? c, and three operators to choose
// from, so 3 * 3 = 9 combinations in all. With only nine of them, the
// simplest honest answer is to write them all out and join them with ||,
// which is true as soon as any one of them is true.
//
// long long rather than int: a, b and c can each be large, and a product of
// three of them grows fast enough to pass what a 32-bit int can hold.
// (int stops at about 2.1e9; long long goes to about 9.2e18.)
//
// C's usual precedence applies inside each expression, so `a + b * c` means
// a + (b * c) - the multiplication is done first. That is exactly what the
// problem asks for, so no brackets are needed.
//
// Example: input 2 3 4 24 -> YES (2 * 3 * 4 = 24);  input 1 1 1 100 -> NO.

int main(){                 // the program starts running here
    long long a, b, c, d;   // four 8-byte whole numbers
    // %lld = read a long long; & gives each variable's address so scanf
    // can store the value in it. Spaces between the %lld let the numbers
    // be separated by spaces or new lines.
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    // The nine checks, one line per first operator (+, - and *). Keep an
    // eye on the last line: it must end with `a * b * c`, the "multiply,
    // multiply" case. An earlier version repeated `a - b * c` there and
    // never tried `a * b * c`, so `2 3 4 24` printed NO even though
    // 2 * 3 * 4 = 24. Listing the cases in a fixed order (+ + , + - , + *,
    // then - ..., then * ...) is the easy way to see that none is missing.
    // == asks "are these equal?"; || means "or".

    if(a + b + c == d || a + b - c == d || a + b * c == d ||
    a - b + c == d || a - b - c == d || a - b * c == d ||
    a * b + c == d || a * b - c == d || a * b * c == d) {
        printf("YES");      // at least one combination gives d
    } else {
        printf("NO");       // none of the nine does
    }

    return 0;               // 0 = the program finished normally
}