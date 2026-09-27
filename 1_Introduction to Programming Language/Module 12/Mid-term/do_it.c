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

/* Idea: a nested loop. The outer loop repeats N times; every repetition the
   inner loop prints one full line 1 2 ... K and then a newline. */

#include <stdio.h>  // standard input/output library: scanf and printf
#include <string.h> // string functions (part of the HackerRank template; not used here)
#include <math.h>   // math functions (template; not used here)
#include <stdlib.h> // general utilities (template; not used here)

int main() { // program execution starts here

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, K; // N = how many lines, K = the last number on each line
    scanf("%d %d", &N, &K); // read both ints; &N and &K are their addresses

    /* A loop inside a loop. The outer loop only counts the N repetitions
       (its i is never printed); the inner loop prints one line 1 2 ... K.
       For N = 3, K = 5 the inner loop runs 5 times for each of the 3 outer passes,
       so 15 numbers are printed in total, 5 per line. */
    for(int i=0; i<N; i++){ // i = 0 .. N-1: one pass = one line
        for(int j=1; j<=K; j++){ // j = 1 .. K: the number to print (starts at 1, includes K)
            printf("%d ", j); // print j followed by a space
        }
        /* The line is complete, so start the next one. */
        printf("\n");
    }

    return 0; // program ended successfully
}
