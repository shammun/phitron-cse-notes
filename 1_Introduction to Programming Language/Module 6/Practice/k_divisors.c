// stdio.h ("standard input output") declares scanf and printf.
#include <stdio.h>

// Find the number of k divisors of number n
//
// (The file is named after problem K in the practice set. What the program
// actually does is print the divisors themselves, one per line, rather than
// count them.)
//
// d is a divisor of n when dividing n by d leaves nothing over, so the whole
// test is `n % d == 0`. Trying every d from 1 up to n finds all of them, and
// because the loop counts upwards they come out in increasing order without
// any extra work.
//
// i <= n, not i < n: n divides itself, so n is a divisor and must be tested.
//
// Example: input 6 -> 1, 2, 3, 6 (6 % 4 = 2 and 6 % 5 = 1, so 4 and 5 are
// skipped).
//
// This does n tests. That is fine for the small n here; the usual speed-up
// is to stop at the square root of n, because every divisor i below it pairs
// with a second divisor n / i above it.
//
// main ends without `return 0;`, which C allows for main alone (it then
// returns 0 by itself).
int main() {        // the program starts running here

    int n;              // the number whose divisors we want
    scanf("%d", &n);    // %d = read a whole number; &n = where to store it

    // Try every candidate i = 1, 2, ..., n; one pass tests one candidate.
    for(int i = 1; i <= n; i++) {
        if(n % i == 0){             // remainder 0: i divides n exactly
            printf("%d\n", i);      // print it on its own line
        }
    }

}   // end of main