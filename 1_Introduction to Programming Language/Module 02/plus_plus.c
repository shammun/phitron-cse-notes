/*
 * plus_plus.c - the four forms of ++ and --.
 *
 *   a++   post-increment: use the OLD value of a here, then add 1 to a
 *   ++b   pre-increment:  add 1 to b first, then use the NEW value
 *   c--   post-decrement: use the OLD value of c, then subtract 1
 *   --d   pre-decrement:  subtract 1 first, then use the NEW value
 *
 * On a line by itself (a++; or ++a;) both forms do the same thing - add
 * 1. The difference only shows when the value is used in the same
 * statement, as inside the printf calls below.
 *
 * Output:
 *     Post-increment: a++
 *     Value of a during print: 15
 *     Value of a after increment: 16
 *
 *     Pre-increment: ++b
 *     Value of b after increment: 31
 *     Value of b in next statement: 31
 *
 *     Post-decrement: c--
 *     Value of c during print: 40
 *     Value of c after decrement: 39
 *
 *     Pre-decrement: --d
 *     Value of d after decrement: 39
 *     Value of d in next statement: 39
 */

/* stdio.h ("standard input output") declares printf. */
#include <stdio.h>

int main() {    /* the program starts here */
    // Demonstrating post-increment (a++)
    int a = 15;     /* a whole-number (int) box holding 15 */
    printf("Post-increment: a++ \n");   /* just a heading; \n = newline */
    /* %d is replaced by the value of a++. a++ hands over the OLD value,
     * 15, and only then does a become 16. So this prints 15. */
    printf("Value of a during print: %d\n", a++);
    /* Now a really is 16. \n\n = end this line and leave a blank one. */
    printf("Value of a after increment: %d\n\n", a);

    // Demonstrating pre-increment (++b)
    int b = 30;     /* starts at 30 */
    printf("Pre-increment: ++b \n");
    /* ++b adds 1 FIRST (b becomes 31) and hands over the new value: 31. */
    printf("Value of b after increment: %d\n", ++b);
    printf("Value of b in next statement: %d\n\n", b);  /* still 31 */

    // Demonstrating post-decrement (c--)
    int c = 40;     /* starts at 40 */
    printf("Post-decrement: c-- \n");
    /* c-- hands over the OLD value 40, then c becomes 39. Prints 40. */
    printf("Value of c during print: %d\n", c--);
    printf("Value of c after decrement: %d\n\n", c);    /* now 39 */

    // Demonstrating pre-decrement (--d)
    int d = 40;     /* starts at 40 */
    printf("Pre-decrement: --d \n");
    /* --d subtracts 1 FIRST (d becomes 39) and hands over 39. */
    printf("Value of d after decrement: %d\n", --d);
    printf("Value of d in next statement: %d\n", d);    /* still 39 */

    return 0;   /* 0 = finished normally */
}