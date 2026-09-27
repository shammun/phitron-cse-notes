/*
 * The smallest and the largest of three numbers.
 *
 * The idea: do not try to sort anything. Ask of each number in turn,
 * "is this one small enough to beat both of the others?". The first one
 * that passes is the answer, and if the first two both fail there is
 * only one candidate left.
 *
 * Example run:
 *     input   4 9 2
 *     output  2      (the minimum)
 *             9      (the maximum)
 */

/* stdio.h ("standard input output") declares scanf and printf. */
#include<stdio.h>

int main() {                        /* execution starts here */
    int a, b, c;                    /* three whole-number boxes in one line */
    /* %d %d %d = read three whole numbers. The spaces between them in
     * the format let the user separate the numbers by spaces or Enter.
     * &a, &b, &c are the addresses scanf fills, in that order. */
    scanf("%d %d %d", &a, &b, &c);

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
     * print c. Ties are the case a comparison usually gets wrong.
     *
     * Trace with 4 9 2: is 4<=9 and 4<=2? no. Is 9<=4 and 9<=2? no.
     * So the else prints c = 2. */
    if(a<=b && a<=c){
        printf("%d\n", a);          /* %d is replaced by a; \n = newline */
    } else if (b<=a && b<=c) {      /* only tried when the first test failed */
        printf("%d\n", b);
    } else {
        /* No test needed here. If neither a nor b is the smallest, the
         * only one left is c. A final else is the "everything else"
         * case, and it runs whenever every test above failed. */
        printf("%d\n", c);
    }

    // maximum
    /* The same three questions with every comparison turned round. This
     * is a second, separate chain: the one above has already finished,
     * so both answers get printed, one per line.
     * Trace with 4 9 2: is 4>=9 ...? no. Is 9>=4 and 9>=2? yes -> 9. */
    if(a>=b && a>=c){
        printf("%d\n", a);          /* a is at least as big as b and c */
    } else if (b>=a && b>=c) {
        printf("%d\n", b);          /* b is at least as big as a and c */
    } else {
        printf("%d\n", c);          /* neither a nor b, so c is the largest */
    }
}   /* no return 0: reaching the end of main counts as returning 0 */
