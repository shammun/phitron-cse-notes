/*
 * Swap the case of one letter.
 *
 * The idea behind it: a char is not some special kind of thing, it is a
 * small number. The computer stores 'A' as 65, 'B' as 66, on up to 'Z'
 * as 90; then 'a' is 97, 'b' is 98, on up to 'z' as 122. Both alphabets
 * are laid out in the same order, so every small letter sits exactly 32
 * above its capital:
 *
 *     'g' is 103,   103 - 32 = 71,   and 71 is 'G'
 *
 * So changing case is plain arithmetic. No library function is needed.
 */

#include <stdio.h>

int main() {
    char a;             /* one character, one byte */
    scanf("%c", &a);    /* %c reads a single character, whatever it is */

    /* Because a letter is really a number, this is an ordinary
     * comparison of numbers: it asks whether a's code falls inside the
     * block 97..122. Use >= and <=, not > and <, so that 'a' and 'z'
     * themselves are included. */
    if (a >= 'a' && a <= 'z'){
        /* a - 32 is a number, but %c prints the character that has that
         * code, which is the capital form. */
        printf("%c", a - 32);
    } else {
        /* Watch out: this branch assumes that "not lowercase" means
         * uppercase, and that is wrong for everything else. Give it '5'
         * (code 53) and it prints code 85, which is 'U'. A safe version
         * would test a >= 'A' && a <= 'Z' here and leave anything that
         * is not a letter untouched. The code is left as written so the
         * trap stays visible. */
        printf("%c", a + 32);
    }
    return 0;
}
