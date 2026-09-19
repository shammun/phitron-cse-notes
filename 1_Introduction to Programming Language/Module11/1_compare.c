/*

C. Compare
time limit per test: 1 second
memory limit per test: 256 megabytes

Given two strings X and Y. Print the smallest lexicographical one.

Note: Lexicographical is the way of ordering the words based on the alphabetical order
of their component letters.

Input
Only one line contains two strings X, Y (1 <= |X|, |Y| <= 20) consists of lowercase English letters.

Output
Print the smallest lexicographical string.

Note: If both of X and Y are equal, print any of them.

Example

input
acm
acpc

output
acm

*/

# include <stdio.h>
# include <string.h>

int main() {
    /* Each string has at most 20 letters, so 25 slots hold the letters and the '\0'. */
    char x[25];
    char y[25];

    scanf("%s %s", x, y);

    /* strcmp compares the two strings letter by letter, the way a dictionary does.
       It gives a negative number when x comes first, 0 when they are equal
       and a positive number when y comes first. */
    if(strcmp(x, y) <= 0){
        printf("%s", x);
    }
    else {
        printf("%s", y);
    }

    return 0;
}
