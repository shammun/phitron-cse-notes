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
// This does n tests. That is fine for the small n here; the usual speed-up
// is to stop at the square root of n, because every divisor i below it pairs
// with a second divisor n / i above it.
//
// As in even_numbers.c, main ends without `return 0;`, which C allows.
int main() {

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        if(n % i == 0){
            printf("%d\n", i);
        }
    }

}