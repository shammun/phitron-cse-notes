/*

J. Count Letters
time limit per test: 2 seconds
memory limit per test: 64 megabytes

Given a string S. Determine how many times does each letter occurred in S.

Input
Only one line contains the string S (1 <= |S| <= 10^7) where |S| is the length
of the string and it consists of only lowercase English letters.

Output
For each character that appears in S, print a single line that contains the
following format: "X : Y" where X is the letter and Y is the number of times
that letter X occurred in S.

Note: you must print letters in ascending order.

Examples

input
aaabbc

output
a : 3
b : 2
c : 1

input
regff

output
e : 1
f : 2
g : 1
r : 1

*/

# include <stdio.h>
# include <string.h>

/* |S| can be 10^7, which is far too big for a local array: a local array lives
   in the small stack area. Declared here, above main, the array is global, so
   it has room, and a global array also starts filled with zeros. */
char s[10000005];

int main() {
    scanf("%s", s);

    /* One box per lowercase letter. Box 0 belongs to 'a', box 25 to 'z'. */
    int freq[26] = {0};

    /* Count the length once, before the loop. */
    int length = strlen(s);

    for(int i = 0; i < length; i++) {
        /* s[i] - 'a' turns the letter into its box number:
           'a' - 'a' is 0, 'b' - 'a' is 1, and so on. */
        freq[s[i] - 'a']++;
    }

    /* Walking the boxes from 0 to 25 prints the letters in alphabetical order
       on its own, whatever order they came in inside S. A letter that never
       appeared still holds 0, so it is skipped. */
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            printf("%c : %d\n", i + 'a', freq[i]);
        }
    }

    return 0;
}
