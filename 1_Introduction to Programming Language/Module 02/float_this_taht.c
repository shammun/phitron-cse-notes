/*
 * float_this_taht.c - the % operator, and multiplying two ints whose
 * answer is too big for an int.
 *
 * An int holds whole numbers only up to about 2,147,483,647 (2.1e9).
 * 100000 * 100000 = 10,000,000,000 (1e10) is bigger than that. If you
 * multiply two ints, C does the sum in int and the answer "overflows"
 * (wraps around to a wrong number) BEFORE it is ever stored anywhere.
 * The fix is to make C do the multiplication in long long (8 bytes,
 * up to about 9.2e18) - this file shows several ways to do that.
 *
 * Output:
 *     2
 *     10000000000
 */

/* stdio.h ("standard input output") declares printf. */
#include <stdio.h>
/* math.h declares maths functions (sqrt, pow, ...). Nothing from it is
 * actually used in this file; the line is harmless. */
#include <math.h>

int main() {    /* the program starts here */
    /* % is the remainder operator: 5 % 3 = 2, because 5 = 1*3 + 2.
     * %d in the format is a placeholder for an int (different meaning of
     * the same % sign - inside the quotes it starts a format specifier).
     * \n = newline. Prints 2. */
    printf("%d\n", 5%3);

    // (Way 1, switched off with // so it does not clash with the
    //  a and b declared below. (long long) a is a "cast": it turns a
    //  copy of a into a long long, so a * b is then done in long long.)
    // int a = 100000;
    // int b = 100000;
    // // int a = 100000, b = 100000;
    // long long result = (long long) a * b;
    // printf("%lld", result);

    // Another way to do the same thing
    // Two int variables declared and given values in one line.
    int a = 100000, b = 100000;
    /* 1LL is the number 1 written as a long long (LL suffix). C works
     * left to right: 1LL * a is done in long long, and that long long
     * result times b is also long long. So no overflow: 10000000000.
     * Writing just a * b would multiply in int and give a wrong value. */
    long long result = 1LL * a * b;
    /* %lld = placeholder for a long long ("long long decimal"). */
    printf("%lld", result);

    // Another way to do the same thing
    // (Way 3, switched off: if even one of the two is long long, the
    //  other is converted to long long before multiplying.)

    // int a = 100000;
    // long long b = 100000;
    // long long result = a * b;
    // printf("%lld", result);

    // Another way to do the same thing
    // (Way 4, switched off: make both variables long long from the start.)
    // long long a = 100000;
    // long long b = 100000;
    // long long result = a * b;
    // printf("%lld", result);

    return 0;   /* 0 = finished normally */
}