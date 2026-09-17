/*
You will be given two integer numbers A and B , you need to print the difference between these two numbers. Remember, difference is always positive.

Note: Use pointers to solve this Problem.

Input Format

Input will contain two integers A and B.
Constraints

0 <= A <= 100
0 <= B <= 100
Output Format

Print a single integer representing the absolute difference between A and B.
Sample Input 0

6 10
Sample Output 0

4
*/

#include<stdio.h>

int main(){
    int A, B;
    scanf("%d %d", &A, &B);
    /*
    int diff = A - B;
    */
    int *ptr1 = &A;
    int *ptr2 = &B;

    int diff = *ptr1 - *ptr2;
    if(diff < 0){
        diff = -diff;
    }

    printf("%d\n", diff);

    return 0;
}