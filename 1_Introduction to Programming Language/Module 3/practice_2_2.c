/*

Problem (Phitron practice, in my own words)

Read two whole numbers A and B from one line and print their sum.
The numbers can be very large, bigger than an int can hold.

Sample input
3 5

Sample output
8

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* long long instead of int: an int stops at about 2.1 * 10^9, a long long
       reaches about 9.2 * 10^18, so a big A or B (and their sum) still fits. */
    long long A, B;

    /* %lld is the placeholder for a long long, in scanf and in printf alike.
       The space between the two %lld lets the numbers be separated by any
       spaces or newlines. & gives scanf the address of each variable. */
    scanf("%lld %lld", &A, &B); // Input the two numbers separated by space

    /* The sum is worked out right inside printf; no extra variable needed. */
    printf("%lld\n", A + B);
    return 0;
}
