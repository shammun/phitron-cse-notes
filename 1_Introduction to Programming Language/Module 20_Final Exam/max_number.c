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

/*
 * This function prints numbers from 1 to n in ascending order
 * For example, if n=5, it prints: 1 2 3 4 5
 * Parameters:
 *   n: The upper limit number up to which we need to print
 */
void firstPart(int n){
    // Loop from 1 to n, incrementing by 1 each time
    for(int i=1; i<=n; i++){
        printf("%d ", i); // Print current number followed by a space
    }
}

/*
 * This function prints numbers from (n-1) to 1 in descending order
 * For example, if n=5, it prints: 4 3 2 1
 * Parameters:
 *   n: The number from which we start counting down (minus 1)
 */
void secondPart(int n){
    // Loop from (n-1) down to 1, decrementing by 1 each time
    for(int i=n-1; i>=1; i--){
        printf("%d ", i); // Print current number followed by a space
    }
}

int main(){
    // T represents the number of test cases
    int T; 
    // Array to store N numbers, sized 10005 to handle large input
    int N[10005];
    
    // Read the number of test cases
    scanf("%d", &T);

    // Read N numbers, one for each test case
    for(int i=0; i<T; i++){
        scanf("%d", &N[i]);
    }

    // Process each test case
    for(int i=0; i<T; i++){
        // For each number N[i]:
        // 1. First print numbers 1 to N[i]
        firstPart(N[i]);
        // 2. Then print numbers (N[i]-1) to 1
        secondPart(N[i]);
        // 3. Print newline to separate test cases
        printf("\n");
    }

    return 0;
}