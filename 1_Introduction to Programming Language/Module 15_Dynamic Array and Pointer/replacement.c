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

#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int A[N];
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    for(int i=0; i<N; i++){
        if(A[i] > 0){
            A[i] = 1;
        } else if(A[i] < 0){
            A[i] = 2;
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d ", A[i]);
    }

    printf("\n");

    return 0;
}