/*
 * A nested if: an if/else placed inside another if.
 *
 * Worth tracing on paper before you run it, because the answer is a
 * little surprising - the inner if/else is never reached at all.
 *
 * Output:
 *     inside else
 */

/* stdio.h ("standard input output") declares printf. */
#include <stdio.h>

int main() {    /* the program starts here */

    /* int = a whole number. x gets the value 0 right away. */
    int x = 0;

    /* x is 0, so x == 1 is false. (== asks "are these equal?"; a single
     * = would instead PUT a value into x.) The entire block below - the
     * inner if, its else, and both of their printf lines - is jumped over
     * in one go. A false if does not peek inside itself to see what is
     * there; it skips straight past the closing brace. */
    if (x == 1)
    {
        /* Dead code. To reach this line x would have to be 1 (the outer
         * test) and 0 (this one) at the same instant, and nothing
         * between the two tests changes x. "inside if if" can never be
         * printed by this program. */
        if (x == 0)
        {
            printf("inside if if\n");       /* \n = newline */
        }
        else
        {
            /* Just as unreachable, for the same reason. */
            printf("inside if else\n");
        }
    }
    else
    {
        /* This else pairs with the OUTER if - the braces make that plain
         * at a glance, which is exactly why they are worth writing even
         * around a single line. It is the only thing the program prints. */
        printf("inside else\n");
    }
    return 0;   /* 0 = finished normally */
}
