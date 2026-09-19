/*
 * Is the character a digit, a small letter or a capital?
 *
 * New here: an if / else with a second if / else inside one of its
 * blocks - a "nested" if. The inner question is only asked once the
 * outer one has been answered, which is how a choice is narrowed down in
 * steps: first "digit or not", then, for the ones that are not, "small
 * or capital".
 */

#include <stdio.h>

int main() {
    char x;
    scanf("%c", &x);

    /* The digit characters sit together at codes 48 ('0') to 57 ('9'),
     * so a single range test covers all ten of them. Note the quotes:
     * '0' is the character, whose code is 48, not the number zero. */
    if (x >= '0' && x <= '9') {
        printf("IS DIGIT\n");
    } else {
        /* Anything that is not a digit is assumed to be a letter, so the
         * ALPHA label is printed before the finer question is asked.
         * Two lines therefore come out for a letter, one for a digit. */
        printf("ALPHA\n");

        /* Bug, left in on purpose: this test uses > and < instead of
         * >= and <=, so it really means codes 98..121 and leaves out
         * 'a' (97) and 'z' (122) themselves. Type a and the program
         * answers IS CAPITAL. The fix is x >= 'a' && x <= 'z';
         * Module 5 has the corrected version.
         *
         * It is kept here because a range test that fails only at its
         * two ends is the hardest kind of mistake to catch: 24 of the
         * 26 letters behave perfectly. */
        if (x > 'a' && x < 'z'){
            printf("IS SMALL\n");
        } else {
            printf("IS CAPITAL\n");
        }
    }

    return 0;
}
