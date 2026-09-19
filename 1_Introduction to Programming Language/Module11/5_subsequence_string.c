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

# include <stdio.h>
# include <string.h>

int main() {
    /* |S| can be 10^4, so 10005 slots hold the letters and the '\0'. */
    char s[10005];
    scanf("%s", s);

    char target[10] = "hello";

    int length = strlen(s);

    /* j points at the letter of "hello" we are still looking for.
       Walk S from left to right. Whenever the current letter of S is the
       one we need, move j to the next letter of "hello".
       Taking the earliest match is always safe: it leaves the most of S
       for the letters that are still needed. */
    int j = 0;
    for(int i = 0; i < length; i++){
        if(j < 5 && s[i] == target[j]){
            j++;
        }
    }

    /* j reaches 5 only if all five letters h, e, l, l, o were found, in order. */
    if(j == 5){
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}
