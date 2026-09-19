/*
P. Log2
time limit per test 1 second
memory limit per test 64 megabytes

Given a number N, print how many times you have to divide it by 2 before it
becomes 1. Every division throws away the fraction, so 5 / 2 is 2.

Note: Solve this problem using recursion.

Input
One line containing a number N (1 <= N <= 10^18).

Output
Print one number: how many divisions were needed.

Example
Input
16
Output
4

Note
16 -> 8 -> 4 -> 2 -> 1, so four divisions.
*/

#include <stdio.h>

/* Dividing n by 2 until it reaches 1 is the same job as dividing n / 2 by 2
   until it reaches 1, plus the one division just made. That smaller copy of
   the same job is what recursion is for.

   Base case: n is already 1, so no division is needed and the answer is 0. */
int log2Steps(long long n) {
    if(n <= 1) {
        return 0;
    }
    return 1 + log2Steps(n / 2);
}

int main() {
    /* N can be 10^18, which does not fit in an int, so use long long and
       read it with %lld. */
    long long n;
    scanf("%lld", &n);

    printf("%d\n", log2Steps(n));

    return 0;
}
