/*

D. Strings
time limit per test: 2 seconds
memory limit per test: 64 megabytes

Given two strings A and B. Print three lines contain the following:

- The size of the string A and size of the string B separated by a space
- The string produced by concatenating A and B (A + B).
- The two strings separated by a single space respectively, after swapping their first character.

For more clarification see the example below.

Input
The first line contains a string A (1 <= |A| <= 10) where |A| is the length of A.
The second line contains a string B (1 <= |B| <= 10) where |B| is the length of B.

Output
Print the answer required above.

Example

input
abcd
ef

output
4 2
abcdef
ebcd af

*/

/* Module 10 solved this problem by counting the lengths by hand.
   Here the same job is done with the <string.h> functions from Module 11. */

# include <stdio.h>
# include <string.h>

int main() {
    /* Each string is at most 10 characters, so 15 slots are enough. */
    char a[15];
    char b[15];

    scanf("%s", a);
    scanf("%s", b);

    /* Line 1: strlen counts the characters before the '\0'.
       Its result is stored in an int first, so that %d prints an int. */
    int length_a = strlen(a);
    int length_b = strlen(b);
    printf("%d %d\n", length_a, length_b);

    /* Line 2: build A + B in a third array.
       It must hold up to 10 + 10 = 20 characters plus the '\0', so 25 slots.
       strcpy puts a copy of A into it, then strcat adds B to its end. */
    char joined[25];
    strcpy(joined, a);
    strcat(joined, b);
    printf("%s\n", joined);

    /* Line 3: swap the two first characters through a temporary box. */
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    printf("%s %s", a, b);

    return 0;
}
