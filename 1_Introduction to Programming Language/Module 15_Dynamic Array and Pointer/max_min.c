/*
Given 3 numbers A, B and C, Print the minimum and the maximum numbers.

Input
Only one line containing 3 numbers A, B and C ( - 105 ≤ A, B, C ≤ 105)

Output
Print the minimum number followed by a single space then print the maximum number.

Examples
InputCopy
1 2 3
OutputCopy
1 3
InputCopy
-1 -2 -3
OutputCopy
-3 -1
InputCopy
10 20 -5
OutputCopy
-5 20
*/

/* Note on the statement: "105" is 10^5 (the exponent lost its formatting when
   it was copied), so the numbers are between -100000 and 100000 and fit in an int. */

#include <stdio.h> // standard input/output library: scanf and printf

int main(){ // program execution starts here
    int A, B, C; // the three numbers
    scanf("%d %d %d", &A, &B, &C); // & gives scanf the address of each variable

    /* Start both answers at A, then let B and C challenge them. This is the
       "best so far" idea from the array lessons, written out for three
       values instead of a loop. */
    int min = A, max = A;

    /* Each value gets two separate ifs (not if/else): one value could be
       both the new minimum and the new maximum.
       Trace with 10 20 -5: start min=10 max=10; B=20 -> max=20; C=-5 -> min=-5 -> "-5 20". */
    if(B < min){ // B is smaller than the smallest so far
        min = B;
    }
    if(B > max){ // B is larger than the largest so far
        max = B;
    }
    if(C < min){
        min = C;
    }
    if(C > max){
        max = C;
    }

    printf("%d %d", min, max); // minimum, a space, then maximum

    return 0; // program ended successfully
}
