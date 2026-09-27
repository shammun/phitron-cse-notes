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

/* Idea: count both lengths by hand, print A and B back to back (that is A + B),
   then swap the first characters of the two strings and print them. */

# include <stdio.h> // standard input/output library: scanf and printf

int main() { // program execution starts here
    /* Each string is at most 10 characters, so 15 slots are enough
       for the characters and the '\0' at the end.
       ('\0' = null character, the marker that ends every C string.) */
    char a[15]; // string A
    char b[15]; // string B

    scanf("%s", a); // read A (one word); a is an array name = an address, so no &
    scanf("%s", b); // read B; %s skips the newline between the two lines by itself

    /* Count both lengths by hand, by walking until the closing '\0'. */
    int length_a = 0; // number of characters in A
    for(int i = 0; a[i] != '\0'; i++){ // one pass = one character of A
        length_a++;
    }

    int length_b = 0; // number of characters in B
    for(int i = 0; b[i] != '\0'; i++){ // one pass = one character of B
        length_b++;
    }

    printf("%d %d\n", length_a, length_b); // line 1: both sizes separated by a space

    /* Line 2: printing A and then B, with nothing in between,
       is the same as printing A + B. */
    printf("%s%s\n", a, b); // e.g. "abcd" then "ef" -> "abcdef"

    /* Line 3: swap the two first characters through a temporary box,
       then print the strings again.
       We need temp because after a[0] = b[0] the old a[0] would be lost.
       Trace: a = "abcd", b = "ef": temp = 'a', a[0] = 'e' -> "ebcd", b[0] = 'a' -> "af". */
    char temp = a[0]; // save A's first character
    a[0] = b[0]; // A gets B's first character
    b[0] = temp; // B gets A's old first character

    printf("%s %s", a, b); // print both strings with one space between them

    return 0; // program ended successfully
}
