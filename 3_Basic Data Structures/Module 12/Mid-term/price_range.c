/*

Abul is plannig to by a smartphone. He has N smartphones available to buy of different prices. But he wants to buy a smartphone in a range between X and Y.

He has given you the price list.

Can you tell him how many smartphones are available in that price range.

Input Format

The first line of input will contain 3 integers N, X, Y, the number of phones and the range.

The next line will contain N numbers p1, p2, p3, ... , pn, the prices of N phones.

Constraints

1 <= N <= 10^5
1 <= pi, X, Y <= 10^9
Output Format

Print an integer, the number of phones available in his prefered range.

Sample Input 0

10 4 8
8 7 2 3 1 10 25 8 13 5
Sample Output 0

4

*/



#include <stdio.h>      /* scanf and printf */
#include <string.h>     /* not used here (template leftover) */
#include <math.h>       /* not used here (template leftover) */
#include <stdlib.h>     /* not used here (template leftover) */

/* main: program entry point; return 0 = success. */
int main() {

    /* The idea: count the prices p with X <= p <= Y. One pass over the list
     * with a counter is enough; the order of the prices does not matter.
     * Prices go up to 10^9, so they are stored as long long to be safe. */
    int N;                      /* number of phones */
    int count = 0;              /* phones inside the range so far */
    long long X, Y;             /* the price range, both ends included */
    long long prices[100000];   /* room for up to 10^5 prices */

    /* %d = int, %lld = long long; & gives scanf the address to write into. */
    scanf("%d %lld %lld", &N, &X, &Y);

    // Read the prices
    for(int i=0; i < N; i++){
        scanf("%lld", &prices[i]);
    }

    // Main logic: one pass, i = index of the phone being checked
    for(int i=0; i<N; i++){
        /* Inside the range, both ends included? Then count it. */
        if (prices[i] >= X && prices[i] <= Y){
            count = count + 1;
        }
    }
    /* Sample range 4..8: prices 8 7 8 5 qualify -> 4. */

    printf("%d", count);        /* print the answer */

    return 0;
}
