/*
 * Counting with for loops.
 *
 * Printing 1 to 30 by hand would mean thirty printf lines, and 1 to 1000
 * would be hopeless. A loop writes the line once and says how many times
 * to run it. This is the second new power of the chapter: after
 * choosing, repeating.
 */

#include <stdio.h>

int main(){
    int i;      /* the counter. It is declared outside both loops, so
                 * the second loop below can reuse the same box. */

    /* A for header has three parts separated by semicolons:
     *
     *     for ( i=1        ; i<=10             ; i++              )
     *           start here   keep going while    do this each round
     *
     * The order of events: set i to 1; check i<=10; if true run the
     * body; then i++; check again. The last check, with i = 11, fails,
     * and the loop stops without printing anything for that round.
     *
     * i<=10 and not i<10, so 10 itself is printed and the body runs ten
     * times. Getting <= and < the wrong way round is the commonest loop
     * bug there is; it costs you exactly one round, at one end. */
    for (i=1; i<=10; i++){
        printf("%d\n", i);
    }

    /* The same shape again, counting further. The first part of the
     * header puts i back to 1, so the leftover 11 from the loop above
     * makes no difference at all. Thirty more lines, forty in total,
     * and the numbers on screen appear to restart at 1. */
    for(i=1; i <= 30; i++){
        printf("%d\n", i);
    }

    return 0;
}
