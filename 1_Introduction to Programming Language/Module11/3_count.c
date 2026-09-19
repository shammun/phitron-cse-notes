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

# include <stdio.h>
# include <string.h>

int main() {
    /* |S| can be 10^6, so the array needs 10^6 slots plus room for the '\0'. */
    char s[1000005];
    scanf("%s", s);

    /* Find the length once, before the loop, instead of calling strlen
       again on every pass: strlen walks the whole string each time. */
    int length = strlen(s);

    /* A digit character is not its number: '3' is stored as 51, not 3.
       The digits '0' to '9' sit next to each other in the ASCII table,
       so s[i] - '0' turns the character into its value ('3' - '0' = 3). */
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum = sum + (s[i] - '0');
    }

    /* The biggest possible sum is 9 * 10^6 = 9000000, which fits in an int. */
    printf("%d", sum);

    return 0;
}
