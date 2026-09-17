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

#include <stdio.h>

int main(){
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int min = A, max = A;

    if(B < min){
        min = B;
    }
    if(B > max){
        max = B;
    }
    if(C < min){
        min = C;
    }
    if(C > max){
        max = C;
    }

    printf("%d %d", min, max);

    return 0;
}

