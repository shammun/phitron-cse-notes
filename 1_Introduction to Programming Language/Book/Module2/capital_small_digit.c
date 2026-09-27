/*
 * Is the character a digit, a small letter or a capital?
 *
 * New here: an if / else with a second if / else inside one of its
 * blocks - a "nested" if. The inner question is only asked once the
 * outer one has been answered, which is how a choice is narrowed down in
 * steps: first "digit or not", then, for the ones that are not, "small
 * or capital".
 *
 * Example runs:
 *     input 7  ->  IS DIGIT
 *     input g  ->  ALPHA  then  IS SMALL
 *     input G  ->  ALPHA  then  IS CAPITAL
 */

/* stdio.h = "standard input output" header; it declares scanf and
 * printf, so the compiler knows those names. */
#include <stdio.h>

int main() {            /* execution starts here */
    /* char holds one character. Inside the computer a character is
     * stored as a small number, its ASCII code ('A' = 65, 'a' = 97,
     * '0' = 48), so characters can be compared with < and >. */
    char x;
    /* %c = read exactly one character. &x = address of x, so scanf can
     * write the character into it. */
    scanf("%c", &x);

    /* The digit characters sit together at codes 48 ('0') to 57 ('9'),
     * so a single range test covers all ten of them. Note the quotes:
     * '0' is the character, whose code is 48, not the number zero.
     * && = "and": both comparisons must be true. */
    if (x >= '0' && x <= '9') {
        printf("IS DIGIT\n");   /* \n = newline, move to the next line */
    } else {
        /* Anything that is not a digit is assumed to be a letter, so the
         * ALPHA label is printed before the finer question is asked.
         * Two lines therefore come out for a letter, one for a digit. */
        printf("ALPHA\n");

        /* BUG (left in on purpose): this test uses > and < instead of
         * >= and <=, so it really means codes 98..121 and leaves out
         * 'a' (97) and 'z' (122) themselves. Type a and the program
         * answers IS CAPITAL. The fix is x >= 'a' && x <= 'z';
         * Module 5 has the corrected version.
         *
         * It is kept here because a range test that fails only at its
         * two ends is the hardest kind of mistake to catch: 24 of the
         * 26 letters behave perfectly. */
        if (x > 'a' && x < 'z'){
            printf("IS SMALL\n");       /* code strictly between a and z */
        } else {
            printf("IS CAPITAL\n");     /* everything else, including a and z */
        }
    }

    return 0;           /* 0 = the program finished without problems */
}
