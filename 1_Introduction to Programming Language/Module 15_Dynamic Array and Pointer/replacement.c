/*
Given a number N and an array A of N numbers. Print the array after doing the following operations:

Replace every positive number by 1.
Replace every negative number by 2.
Input
First line contains a number N (2 ≤ N ≤ 1000) number of elements.

Second line contains N numbers (-105  ≤  Ai  ≤  105).

Output
Print the array after the replacement and it's values separated by space.

Example
InputCopy
5
1 -2 0 3 4
OutputCopy
1 2 0 1 1
*/

/* Note on the statement: "105" is 10^5 (the exponent lost its formatting when it was copied). */

#include <stdio.h> // standard input/output library: scanf and printf

int main(){ // program execution starts here
    int N; // number of elements
    scanf("%d", &N); // &N = address where scanf stores the value

    /* A plain (variable-length) array of N ints.
       ("variable length" = its size comes from a value read at run time; a C99 feature) */
    int A[N];
    for(int i=0; i<N; i++){ // read N numbers into A[0] .. A[N-1]
        scanf("%d", &A[i]);
    }

    /* Change the values in place. Zero matches neither test, so it is left
       as it is - no third branch is needed.
       Trace: 1 -2 0 3 4 -> 1 2 0 1 1 */
    for(int i=0; i<N; i++){
        if(A[i] > 0){ // positive
            A[i] = 1;
        } else if(A[i] < 0){ // negative
            A[i] = 2;
        }
    }

    /* Print the changed array, a space after each value. */
    for(int i = 0; i < N; i++){
        printf("%d ", A[i]);
    }

    printf("\n"); // end the output line

    return 0; // program ended successfully
}
