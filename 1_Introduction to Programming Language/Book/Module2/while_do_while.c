/*
 * while and do-while, side by side.
 *
 * A for loop keeps its three parts - start, test, change - packed into
 * one header. while and do-while take the same three jobs and spread
 * them out: you set the counter before the loop and change it yourself
 * inside the body. The only real difference between the two is WHEN the
 * condition is checked.
 *
 * Output:
 *     i = 1 ... i = 5     (five lines from the while loop)
 *     j = 10 ... j = 1    (ten lines from the do-while loop)
 */

/* stdio.h ("standard input output") declares printf. */
#include <stdio.h>

int main() {    /* execution starts here */
    int i;      /* counter for the while loop (a whole number) */
    int j;      /* counter for the do-while loop */
    i = 1;      /* set up by hand; a for header would have done this */
    j = 10;     /* the do-while loop counts down from 10 */

    /* while checks BEFORE each round. i is 1, so 1 <= 5 is true and the
     * body runs; after i += 1 the check happens again. When i reaches 6
     * the check fails and the body is skipped.
     * Because the check comes first, a while loop can run zero times:
     * had i started at 99, nothing at all would be printed. */
    while(i <= 5) {
        /* "i = " is printed as text, %d is replaced by the value of i,
         * \n ends the line. */
        printf("i = %d\n", i);
        i+=1;   /* i += 1 is short for i = i + 1. Forget this line and
                 * the condition never changes - the loop runs forever. */
    }

    /* do-while checks AFTER each round, so the body always runs at
     * least once, even when the condition was false from the start.
     * Here j counts down: print, subtract one, then ask whether j is
     * still above 0. The last line printed is j = 1, because after that
     * j is 0 and 0 > 0 is false.
     *
     * That one guaranteed round is the whole difference between the two
     * forms: start j at 0 and the while shape prints nothing while this
     * shape still prints j = 0.
     *
     * Note the semicolon after while(j > 0) - this form needs it, and
     * it is easy to leave out. */
    do {
        printf("j = %d\n", j);  /* print the current j */
        j -= 1;                 /* j -= 1 is short for j = j - 1 */
    } while(j > 0);             /* go round again while j is still positive */

    return 0;   /* the program finished normally */
}
