/*

K. I Love strings
time limit per test: 2 seconds
memory limit per test: 64 megabytes

Given two strings S and T. Print a new string that contains the following:

- The first letter of the string S followed by the first letter of the string T.
- The second letter of the string S followed by the second letter of the string T.
- and so on...

In other words, the new string should be ( S0 + T0 + S1 + T1 + .... ).

Note: If the length of S is greater than the length of T then you have to add the rest of
S letters at the end of the new string and vice versa.

Input
The first line contains a number N (1 <= N <= 50) the number of test cases.

Each of the N following lines contains two string S, T (1 <= |S|, |T| <= 50) consists of
lower and upper English letters.

Output
For each test case, print the required string.

Example

input
2
ipAsu ccsit
ey gpt

output
icpcAssiut
egypt

*/

/* Idea: we never build the new string in memory; we just print its letters
   in the right order: S[0], T[0], S[1], T[1], ... skipping a string once it has
   no more letters. */

# include <stdio.h>  // standard input/output library: scanf and printf
# include <string.h> // string library: strlen

int main() { // program execution starts here
    int n; // number of test cases
    scanf("%d", &n); // &n = address of n, where scanf stores the value

    /* One pass of this loop solves one test case; k counts them 0 .. n-1. */
    for(int k = 0; k < n; k++){
        /* Each string has at most 50 letters, so 55 slots are enough
           (letters + the '\0' end marker). */
        char s[55]; // string S
        char t[55]; // string T
        scanf("%s %s", s, t); // read both words from the line; array names are addresses, so no &

        int length_s = strlen(s); // number of letters in S
        int length_t = strlen(t); // number of letters in T

        /* Run i up to the longer length. On each step print S's letter at i
           and then T's letter at i, but only if that string still has a letter there.
           When the shorter string runs out, the longer one simply keeps printing,
           which adds "the rest of the letters" at the end. */
        int longer = length_s; // assume S is the longer one ...
        if(length_t > longer){ // ... and switch if T is actually longer
            longer = length_t;
        }

        /* i is the position inside both strings. Trace with S = "ey", T = "gpt":
           i = 0 -> 'e' 'g', i = 1 -> 'y' 'p', i = 2 -> S has no letter, T gives 't' -> "egypt". */
        for(int i = 0; i < longer; i++){
            if(i < length_s){ // S still has a letter at position i
                printf("%c", s[i]); // %c prints one character
            }
            if(i < length_t){ // T still has a letter at position i
                printf("%c", t[i]);
            }
        }

        /* Each test case goes on its own line. */
        printf("\n");
    }

    return 0; // program ended successfully
}
