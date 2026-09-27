/*

E. Count
time limit per test: 2 seconds
memory limit per test: 64 megabytes

Given a string S. Print the summation of its digits.

Input
Only one line contains a string S (1 <= |S| <= 10^6) where |S| is the length of the string.

It's guaranteed that S contains only digits from 0 to 9.

Output
Print the answer required above.

Example

input
351

output
9

Note
First Test: 3 + 5 + 1 = 9.

*/

/* Idea: the "number" can have a million digits, far too big for any int type,
   so we read it as a string of digit characters and add up the digits one by one. */

# include <stdio.h>  // standard input/output library: scanf and printf
# include <string.h> // string library: strlen

int main() { // program execution starts here
    /* |S| can be 10^6, so the array needs 10^6 slots plus room for the '\0'.
       (About 1 MB of chars; it works here, though very large arrays are
       often made global to avoid running out of stack space.) */
    char s[1000005];
    scanf("%s", s); // read all digits as text; s is an array name (an address), so no &

    /* Find the length once, before the loop, instead of calling strlen
       again on every pass: strlen walks the whole string each time. */
    int length = strlen(s); // number of digit characters

    /* A digit character is not its number: '3' is stored as 51, not 3.
       The digits '0' to '9' sit next to each other in the ASCII table,
       so s[i] - '0' turns the character into its value ('3' - '0' = 3).
       One pass adds the value of one digit. Trace with "351": 0 + 3 = 3, 3 + 5 = 8, 8 + 1 = 9. */
    int sum = 0; // running total, starts at 0
    for(int i = 0; i < length; i++){ // i = index of the current digit, 0 .. length-1
        sum = sum + (s[i] - '0'); // add this digit's value to the total
    }

    /* The biggest possible sum is 9 * 10^6 = 9000000, which fits in an int. */
    printf("%d", sum); // print the total

    return 0; // program ended successfully
}
