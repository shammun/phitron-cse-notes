/*
 * Even or odd.
 *
 * Read one whole number and say whether it divides evenly by 2.
 *
 * This is the first program in the chapter that makes a decision. Until
 * now every line you wrote ran exactly once, in the order it appeared.
 * From here a block of lines can be skipped altogether, and which block
 * runs is decided while the program is running, from a value you typed a
 * moment earlier.
 */

#include<stdio.h>   /* printf and scanf live here */

int main() {
    int n;              /* a box for the number you are about to type */
    scanf("%d", &n);    /* wait for it; &n says where to put it */

    /* n % 2 is the remainder after dividing n by 2. It is 0 when n
     * splits into pairs exactly and 1 when one is left over, so
     * "remainder is 0" is another way of asking "is n even".
     *
     * Note the doubled = sign. A single = would put 2 into n; == asks
     * whether the two sides are equal. Mixing the two up is the classic
     * first-week bug, and it does not always look like an error.
     *
     * Negative numbers still work: -7 % 2 is -1 in C, not 1, but the
     * test only checks against 0, so -7 is correctly called odd. */
    if (n % 2 == 0){
        printf("Even number \n");   /* runs only when the test is true */
    } else {
        printf("Odd number \n");    /* runs only when it is false */
    }

    /* Exactly one of those two lines printed - never both, never
     * neither. That is the whole of if / else.
     *
     * There is no return 0; at the end. Modern C allows main to run off
     * its closing brace and treats that as return 0, so the program
     * still reports success; writing it out, as the other files in this
     * chapter do, is the better habit. */
}
