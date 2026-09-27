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

#include<stdio.h> // standard input/output library: scanf and printf

int main(){ // program execution starts here
    int A, B; // the two numbers
    scanf("%d %d", &A, &B); // & gives scanf the addresses of A and B
    /*
    int diff = A - B;
    */
    /* (switched-off line above: the plain way without pointers; kept for
       comparison, but the task asks for pointers) */

    /* The question asks for pointers, so the values are reached through
       them: ptr1 holds the address of A, and *ptr1 reads the value stored
       there (the same as A). */
    int *ptr1 = &A; // "int *" = pointer to int; &A = address of A
    int *ptr2 = &B; // ptr2 holds the address of B

    int diff = *ptr1 - *ptr2; // same as A - B, but read through the pointers

    /* The difference must be positive: if A was the smaller number the
       result is negative, and flipping its sign fixes that (6 - 10 = -4
       becomes 4). */
    if(diff < 0){
        diff = -diff;
    }

    printf("%d\n", diff); // print the positive difference

    return 0; // program ended successfully
}
