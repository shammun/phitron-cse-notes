/*
 * The smallest and the largest of three numbers.
 *
 * The idea: do not try to sort anything. Ask of each number in turn,
 * "is this one small enough to beat both of the others?". The first one
 * that passes is the answer, and if the first two both fail there is
 * only one candidate left.
 */

#include<stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);  /* three boxes, three values, one line */

    // minimum
    /* && means "and": both sides must be true for the whole test to be
     * true. So a<=b && a<=c says exactly "a is not bigger than either
     * of the other two", which is what being the smallest means.
     *
     * C reads an if / else-if chain from the top and stops at the first
     * test that is true, so at most one of these three lines can print.
     *
     * <= and not < : with 5 5 9 the first test still passes and a is
     * called the minimum. With a strict < both a and b would fail their
     * own tests on a tie and the chain would wrongly fall through and
     * print c. Ties are the case a range test usually gets wrong. */
    if(a<=b && a<=c){
        printf("%d\n", a);
    } else if (b<=a && b<=c) {
        printf("%d\n", b);
    } else {
        /* No test needed here. If neither a nor b is the smallest, the
         * only one left is c. A final else is the "everything else"
         * case, and it can never be skipped. */
        printf("%d\n", c);
    }

    // maximum
    /* The same three questions with every comparison turned round. This
     * is a second, separate chain: the one above has already finished,
     * so both answers get printed, one per line. */
    if(a>=b && a>=c){
        printf("%d\n", a);
    } else if (b>=a && b>=c) {
        printf("%d\n", b);
    } else {
        printf("%d\n", c);
    }
}
