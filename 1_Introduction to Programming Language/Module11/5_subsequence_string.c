/*

M. Subsequence String
time limit per test: 1 second
memory limit per test: 256 megabytes

Given String S. Determine if there is a Subsequence in S that is equal to "hello" or not.

Note: A subsequence is a sequence that can be derived from another sequence by deleting some
elements without changing the order of the remaining elements.

For example: The list of all subsequence for the word "apple" would be "a", "ap", "al", "ae",
"app", "apl", "ape", "ale", "appl", "appe", "aple", "apple", "p", "pp", "pl", "pe", "ppl",
"ppe", "ple", "pple", "l", "le", "e".

Input
Only one line contains a string S (5 <= |S| <= 10^4) where |S| is the length of the string
and it consists of lowercase English letters.

Output
Print "YES" if there exists an Subsequence equal to "hello" otherwise, print "NO".

Examples

input
ahhellllloou

output
YES


input
hlelo

output
NO

*/

/* Idea (two pointers): i walks through S, j walks through "hello".
   j only moves forward when S gives us the letter we are waiting for.
   If j gets past all 5 letters, "hello" can be picked out of S in order. */

# include <stdio.h>  // standard input/output library: scanf and printf
# include <string.h> // string library: strlen

int main() { // program execution starts here
    /* |S| can be 10^4, so 10005 slots hold the letters and the '\0'. */
    char s[10005];
    scanf("%s", s); // read S; s is an array name (an address), so no &

    /* A char array can be filled from a string literal when it is declared:
       target gets 'h' 'e' 'l' 'l' 'o' '\0', and the remaining 4 slots are set to 0. */
    char target[10] = "hello";

    int length = strlen(s); // number of letters in S, computed once

    /* j points at the letter of "hello" we are still looking for.
       Walk S from left to right. Whenever the current letter of S is the
       one we need, move j to the next letter of "hello".
       Taking the earliest match is always safe: it leaves the most of S
       for the letters that are still needed.
       The check j < 5 comes first so that, once "hello" is complete,
       target[j] is not read any more (&& stops as soon as the left side is false).
       Trace with "hlelo": 'h' -> j=1, 'l' (need 'e') skip, 'e' -> j=2, 'l' -> j=3,
       'o' (need second 'l') skip -> j ends at 3 -> NO. */
    int j = 0; // index into target: how many letters of "hello" are already matched
    for(int i = 0; i < length; i++){ // i = index into S
        if(j < 5 && s[i] == target[j]){ // still letters to find, and this one is the next needed letter
            j++; // matched it; now look for the next letter of "hello"
        }
    }

    /* j reaches 5 only if all five letters h, e, l, l, o were found, in order. */
    if(j == 5){
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0; // program ended successfully
}
