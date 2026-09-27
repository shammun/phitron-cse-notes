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

# include <stdio.h>  // standard input/output library: scanf and printf
# include <string.h> // string library: strlen (length), strcpy (copy), strcat (append)

int main() { // program execution starts here
    /* Each string is at most 10 characters, so 15 slots are enough
       (the characters plus the '\0' end marker, with room to spare). */
    char a[15]; // string A
    char b[15]; // string B

    scanf("%s", a); // read A; an array name is already an address, so no &
    scanf("%s", b); // read B; %s skips the newline left after A

    /* Line 1: strlen counts the characters before the '\0'.
       Its result is stored in an int first, so that %d prints an int.
       (strlen really returns size_t, an unsigned type; %d expects int, so the
       int variables avoid a type mismatch in printf.) */
    int length_a = strlen(a); // e.g. "abcd" -> 4
    int length_b = strlen(b); // e.g. "ef" -> 2
    printf("%d %d\n", length_a, length_b); // print both sizes, then a newline

    /* Line 2: build A + B in a third array.
       It must hold up to 10 + 10 = 20 characters plus the '\0', so 25 slots.
       strcpy puts a copy of A into it, then strcat adds B to its end.
       Trace: joined = "abcd" after strcpy, then "abcdef" after strcat. */
    char joined[25]; // destination for A + B
    strcpy(joined, a); // copy A (including its '\0') into joined
    strcat(joined, b); // find the '\0' of joined and write B from there (B's '\0' ends the new string)
    printf("%s\n", joined); // print A + B on its own line

    /* Line 3: swap the two first characters through a temporary box.
       temp keeps a[0] safe, because a[0] is overwritten on the next line. */
    char temp = a[0]; // save A's first character
    a[0] = b[0]; // A's first character becomes B's first character
    b[0] = temp; // B's first character becomes A's old first character

    printf("%s %s", a, b); // e.g. "ebcd af"

    return 0; // program ended successfully
}
