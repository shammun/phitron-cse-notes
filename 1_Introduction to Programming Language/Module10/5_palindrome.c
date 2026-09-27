/*

I. Palindrome
time limit per test: 1 second
memory limit per test: 256 megabytes

Given a string S. Determine whether S is Palindrome or not

Note: A string is said to be a palindrome if the reverse of the string is same as the string.
For example, "abba" is palindrome, but "abbc" is not palindrome.

Input
Only one line contains a string S (1 <= |S| <= 1000) where |S| is the length of the string
and it consists of lowercase letters only.

Output
Print "YES" if the string is palindrome, otherwise print "NO".

Examples

input
abba

output
YES


input
icpcassiut

output
NO


input
mam

output
YES

*/

/* Idea: find the length, then compare each character in the first half with
   its mirror character in the second half. Any difference means NO. */

# include <stdio.h> // standard input/output library: scanf and printf

int main() { // program execution starts here
    /* |S| can be 1000, so 1005 slots hold the letters and the '\0' at the end.
       '\0' (null character) is how C marks the end of a string. */
    char s[1005];
    scanf("%s", s); // read one word into s and put '\0' after it; the array name s is an address, so no &

    /* Count the length by walking the array until the closing '\0'.
       Each pass counts one real character. */
    int length = 0; // characters counted so far
    for(int i = 0; s[i] != '\0'; i++){ // stop at the end marker
        length++; // count this character
    }

    /* Same idea as the palindrome array, but with characters:
       compare the first letter with the last, the second with the second last,
       and stop at the middle. One mismatch is enough to answer NO.
       Flag: 1 = still looks like a palindrome, 0 = a mismatch was found. */
    int is_palindrome = 1;

    /* i goes over the first half: 0 .. length/2 - 1 (integer division drops the .5,
       so in an odd-length word the middle letter is skipped - it matches itself).
       Trace with "mam": length = 3, length/2 = 1, so only i = 0: s[0]='m' vs s[2]='m' -> equal -> YES. */
    for(int i = 0; i < length / 2; i++){
        if(s[i] != s[length - 1 - i]){ // s[length-1-i] is the mirror of s[i]
            is_palindrome = 0; // remember the mismatch
            break; // no need to check the other pairs
        }
    }

    /* Print the answer from the flag. */
    if(is_palindrome == 1){ // every pair matched
        printf("YES");
    }
    else { // some pair was different
        printf("NO");
    }

    return 0; // program ended successfully
}
