/*

Problem Statement

You will be given two positive integer N and K. You need to print from 1 to K, and you need to do this N times.

Please look at the sample input output.

Input Format

Input will contain N and K.
Constraints

1 <= N,K <= 100
Output Format

You need to print fron 1 to K, N times. Don't forget to print new line after printing from 1 to K.
Sample Input 0

3 5
Sample Output 0

1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
Sample Input 1

7 4
Sample Output 1

1 2 3 4 
1 2 3 4 
1 2 3 4 
1 2 3 4 
1 2 3 4 
1 2 3 4 
1 2 3 4 

*/


#include <stdio.h>      /* scanf and printf */
#include <string.h>     /* not used here (template leftover) */
#include <math.h>       /* not used here (template leftover) */
#include <stdlib.h>     /* not used here (template leftover) */

/* main: program entry point; return 0 = success. */
int main() {

    /* The idea: two nested loops. The outer loop counts the N rows; for each
     * row the inner loop prints 1 2 ... K, then a newline ends the row. */
    int N, K;                   /* N = how many rows, K = count up to K on each row */
    scanf("%d %d", &N, &K);     /* %d = int; &N, &K are the addresses scanf writes into */

    /* Outer loop: i = 0 .. N-1, one row per pass (i itself is not printed). */
    for(int i=0; i<N; i++){          /* N rows */
        /* Inner loop: j = 1 .. K, the numbers printed on this row. */
        for(int j=1; j<=K; j++){     /* 1 to K on this row */
            printf("%d ", j);        /* the number and a space */
        }
        printf("\n");               /* end of the row (\n = newline character) */
    }
    /* Sample 3 5 -> three lines of "1 2 3 4 5 ". */

    return 0;
}
