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

# include <stdio.h>

int main() {
    /* Each string is at most 10 characters, so 15 slots are enough
       for the characters and the '\0' at the end. */
    char a[15];
    char b[15];

    scanf("%s", a);
    scanf("%s", b);

    /* Count both lengths by hand, by walking until the closing '\0'. */
    int length_a = 0;
    for(int i = 0; a[i] != '\0'; i++){
        length_a++;
    }

    int length_b = 0;
    for(int i = 0; b[i] != '\0'; i++){
        length_b++;
    }

    printf("%d %d\n", length_a, length_b);

    /* Line 2: printing A and then B, with nothing in between,
       is the same as printing A + B. */
    printf("%s%s\n", a, b);

    /* Line 3: swap the two first characters through a temporary box,
       then print the strings again. */
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    printf("%s %s", a, b);

    return 0;
}
