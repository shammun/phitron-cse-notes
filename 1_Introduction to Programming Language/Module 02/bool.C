/*
 * A comparison has a value.
 *
 * That is the whole lesson. When you write a == b, C does not simply
 * jump somewhere: it works out a number - 1 when the two sides are
 * equal, 0 when they are not - and you may keep that number in a
 * variable like any other. An if is nothing more than a block that runs
 * when such a number turns out not to be 0.
 */

#include <stdio.h>
#include <stdbool.h>   /* adds the type bool and the words true and
                        * false. Plain C has no bool of its own; under
                        * the surface it is still a small integer that
                        * holds 1 or 0. */

int main() {
    int a = 5, b = 7;   /* two boxes declared and filled on one line */

    /* 5 == 7 is false, so result ends up holding 0.
     * Again, note the doubled = : a single = would copy b into a
     * instead of comparing them, and the file would still compile. */
    bool result = a == b;

    /* There is no %b in C. A bool is printed with %d, the int code, and
     * shows up as 0 or 1 - which is exactly what it is. */
    printf("%d\n", result);

    return 0;
}

/* Watch out: this file's name ends in a capital .C. On Windows that
 * makes no difference, but on Linux and macOS gcc reads a lowercase .c
 * as C and a capital .C as C++, so the same file would be compiled as
 * two different languages depending on the machine. Name C files .c. */
