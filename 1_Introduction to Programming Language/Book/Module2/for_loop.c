/*
 * Counting with for loops.
 *
 * Printing 1 to 30 by hand would mean thirty printf lines, and 1 to 1000
 * would be hopeless. A loop writes the line once and says how many times
 * to run it. This is the second new power of the chapter: after
 * choosing, repeating.
 *
 * Output: the numbers 1 to 10, one per line, then 1 to 30, one per line.
 */

/* stdio.h ("standard input output") declares printf; #include copies it
 * in before compiling so the name printf is known. */
#include <stdio.h>

int main(){     /* the program begins here; int = it returns a whole number */
    int i;      /* the counter, a whole number (int). It is declared
                 * outside both loops, so the second loop below can reuse
                 * the same box. */

    /* A for header has three parts separated by semicolons:
     *
     *     for ( i=1        ; i<=10             ; i++              )
     *           start here   keep going while    do this each round
     *
     * i++ means "add 1 to i" (the same as i = i + 1).
     *
     * The order of events: set i to 1; check i<=10; if true run the
     * body; then i++; check again. The last check, with i = 11, fails,
     * and the loop stops without printing anything for that round.
     *
     * i<=10 and not i<10, so 10 itself is printed and the body runs ten
     * times. Getting <= and < the wrong way round is the commonest loop
     * bug there is; it costs you exactly one round, at one end. */
    for (i=1; i<=10; i++){
        /* %d is replaced by the current value of i as a whole number;
         * \n moves to a new line so each number sits on its own line. */
        printf("%d\n", i);
    }

    /* The same shape again, counting further. The first part of the
     * header puts i back to 1, so the leftover 11 from the loop above
     * makes no difference at all. Thirty more lines, forty in total,
     * and the numbers on screen appear to restart at 1. */
    for(i=1; i <= 30; i++){
        printf("%d\n", i);      /* print i, then a newline */
    }

    return 0;   /* the program finished normally */
}
