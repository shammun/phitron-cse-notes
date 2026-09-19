/*
 * A letter grade from a mark, using an else-if ladder.
 *
 * The mark is fixed in the code instead of being read in, so the program
 * always walks the same path. The point here is the shape of the ladder
 * and the order of its tests, not the input.
 */

#include <stdio.h>

int main() {
    int marks = 76;

    /* C checks the tests from the top and stops at the first true one,
     * so the ORDER is part of the logic and not a matter of taste.
     * Strictest first: >= 80 before >= 70. Swap them and an 85 would
     * meet >= 70 first and be given A, so A+ could never be printed at
     * all.
     *
     * With 76: the first test fails, the second passes, A is printed,
     * and everything below is skipped without being looked at. */
    if(marks >= 80){
        printf("A+");
    } else if(marks >= 70) {
        printf("A");
    } else if(marks >= 70) {
        /* Bug, left in on purpose: this repeats the test on the line
         * above. Any mark that reaches here has already failed >= 70 one
         * step earlier, so this test can never be true and A- can never
         * be printed. It was surely meant to read marks >= 60.
         *
         * A condition repeated inside one ladder is always dead code,
         * and the compiler will not warn you about it - the program
         * runs perfectly, it just quietly never does this. */
        printf("A-");
    }

    /* There is no final else either, so a mark below 70 prints nothing
     * at all rather than a failing grade. */
    return 0;
}
