/*
Max Number
time limit per test1 second
memory limit per test64 megabytes
Given a number N and an array A of N numbers. Print the maximum value in this array.

Note: Solve this problem using recursion.

Input
First line contains a number N (1 ≤ N ≤ 103) number of elements.

Second line contains N numbers ( - 109 ≤ Ai ≤ 109).

Output
Print the maximum value in this array.

Example
InputCopy
5
1 -3 5 4 -6
OutputCopy
5
*/

#include <stdio.h>

void firstPart(int n){
    for(int i=1; i<=n; i++){
        printf("%d ", i);
    }
}

void secondPart(int n){
    for(int i=n-1; i>=1; i--){
        printf("%d ", i);
    }
}

int main(){
    int T; 
    int N[10005];
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        scanf("%d", &N[i]);
    }

    for(int i=0; i<T; i++){
        firstPart(N[i]);
        secondPart(N[i]);
        printf("\n");
    }

    return 0;
}