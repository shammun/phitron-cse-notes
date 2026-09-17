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

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d", &N);

    long long sum = 0;
    for(int i=0; i<N; i++){
        long long num;
        scanf("%lld", &num);
        sum += abs(num);
    }

    printf("%lld", sum);

    return 0;
}
