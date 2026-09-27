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

/* Idea: read all prices, then count how many of them lie between X and Y
   (both ends included). */

#include <stdio.h>  // standard input/output library: scanf and printf
#include <string.h> // string functions (part of the HackerRank template; not used here)
#include <math.h>   // math functions (template; not used here)
#include <stdlib.h> // general utilities (template; not used here)

int main() { // program execution starts here

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N; // number of phones
    /* The answer: how many prices fall inside the range. Starts at 0. */
    int count = 0;
    /* Prices and limits go up to 10^9; long long keeps them safe.
       (10^9 would still fit in an int, whose limit is about 2.1 * 10^9,
       but long long leaves no doubt. It must then be read with %lld.) */
    long long X, Y; // the lower and upper ends of the price range
    long long prices[100000]; // room for the largest N (10^5)

    scanf("%d %lld %lld", &N, &X, &Y); // %d for the int N, %lld for each long long

    // Read the prices: one pass stores one price in prices[i]
    for(int i=0; i < N; i++){
        scanf("%lld", &prices[i]); // %lld because prices is a long long array
    }

    // Main logic: a price is in range when it is at least X AND at most Y.
    // Both ends are included, so >= and <=, not > and <.
    // Trace with X = 4, Y = 8: prices 8 7 2 3 1 10 25 8 13 5 -> 8, 7, 8, 5 are inside -> 4.
    for(int i=0; i<N; i++){
        if (prices[i] >= X && prices[i] <= Y){ // && = both sides must be true
            count = count + 1; // one more phone in range
        }
    }

    printf("%d", count); // print how many phones are in range

    return 0; // program ended successfully
}
