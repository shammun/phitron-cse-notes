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

#include <stdio.h> // standard input/output library: scanf and printf

/* Dividing n by 2 until it reaches 1 is the same job as dividing n / 2 by 2
   until it reaches 1, plus the one division just made. That smaller copy of
   the same job is what recursion is for.

   Base case: n is already 1, so no division is needed and the answer is 0.
   (The test is n <= 1 so that the chain also stops safely if n were ever 0.)

   Parameter: n (long long, because it can be up to 10^18).
   Returns: the number of divisions, an int - at most about 60 for 10^18,
   because 2^60 is already more than 10^18.
   Trace with 5: log2Steps(5) = 1 + log2Steps(2) = 1 + (1 + log2Steps(1)) = 1 + 1 + 0 = 2. */
int log2Steps(long long n) {
    if(n <= 1) {
        return 0; // nothing left to divide
    }
    return 1 + log2Steps(n / 2); // one division now, plus however many n / 2 needs (integer division drops the fraction)
}

int main() { // program execution starts here
    /* N can be 10^18, which does not fit in an int, so use long long and
       read it with %lld. */
    long long n;
    scanf("%lld", &n); // &n = address where scanf stores the number

    printf("%d\n", log2Steps(n)); // log2Steps returns an int, so %d is the right specifier here

    return 0; // program ended successfully
}
