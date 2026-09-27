/*
Given a number N and an array A of N numbers. Print the absolute summation of these numbers.

absolute value : means to remove any negative sign in front of a number .

EX : |-5| = 5 , |7| = 7

Input
First line contains a number N (1 ≤ N ≤ 10^5) number of elements.

Second line contains N numbers (-109  ≤  Ai  ≤  109).

Output
Print the absolute summation of these numbers.

Examples
InputCopy
4
7 2 1 3
OutputCopy
13
InputCopy
3
-1 2 -3
OutputCopy
2
Note
Second Example :

-1 + 2 + -3 = -2 and it absolute is 2 so the answer is 2.
*/

/* Note on the statement: "109" is 10^9 (the exponent lost its formatting when it was copied). */

#include <stdio.h>  // standard input/output library: scanf and printf
#include <stdlib.h> // standard library: malloc and free

/* The practice sheet asks for two things from this module: keep the numbers
   in a dynamic array (malloc), and walk that array with a pointer. */

int main(){ // program execution starts here
    int N; // number of elements
    scanf("%d", &N); // &N = address where scanf stores N

    /* malloc reserves room for N long longs and returns the address of the
       first one. Each value can be as big as 10^9, and the total of up to
       10^5 of them can reach 10^14, so long long, not int.
       (int stops near 2.1 * 10^9; long long reaches about 9.2 * 10^18.)
       The (long long *) cast turns malloc's plain void* address into a
       "pointer to long long". */
    long long *A = (long long *)malloc(N * sizeof(long long));

    /* A + i is the address of box i, so scanf can be given it directly
       (it means the same as &A[i]). %lld is the format for a long long. */
    for(int i=0; i<N; i++){
        scanf("%lld", A + i);
    }

    /* Walk the array with a pointer p: it starts at the first box (A) and
       p++ moves it one long long further each time. The loop stops when p
       reaches A + N, the address just past the last box. *p is the value
       p points at.
       The raw values are added - negatives pull the sum down.
       Trace with -1 2 -3: sum = -1, then 1, then -2. */
    long long sum = 0;
    for(long long *p = A; p < A + N; p++){
        sum += *p; // add the value p points at ("+=" means sum = sum + *p)
    }

    /* The judge wants the absolute value of the SUM, so the sign is removed
       only now, once, at the end. (Removing it from every number first would
       answer a different question: -1 2 -3 would give 6 instead of 2.) */
    if(sum < 0){
        sum = -sum; // e.g. -2 becomes 2
    }

    printf("%lld", sum); // %lld prints a long long

    /* Every malloc is paired with a free. */
    free(A);

    return 0; // program ended successfully
}
