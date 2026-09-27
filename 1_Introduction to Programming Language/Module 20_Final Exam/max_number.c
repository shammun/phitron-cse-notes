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

/*
 * NOTE: the code in this file does NOT solve the "Max Number" problem written
 * above. It solves a different exercise: read T numbers, and for each number
 * N print 1 2 ... N ... 2 1 on its own line. Fed the Max Number sample above
 * (5, then 1 -3 5 4 -6), it prints five lines of counting - "1", an empty
 * line, "1 2 3 4 5 4 3 2 1", "1 2 3 4 3 2 1" and another empty line -
 * instead of the single answer 5.
 * For the Max Number problem solved with recursion, see practice_max_number.c
 * in this folder (or max_number.c in Module 19).
 *
 * What this code does, with input
 *     2
 *     3 1
 * it prints
 *     1 2 3 2 1
 *     1
 */

#include <stdio.h> // standard input/output library: scanf and printf

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
 * (it starts at n-1 so that the peak n, already printed by firstPart, is not repeated)
 */
void secondPart(int n){
    // Loop from (n-1) down to 1, decrementing by 1 each time
    for(int i=n-1; i>=1; i--){
        printf("%d ", i); // Print current number followed by a space
    }
}

int main(){ // program execution starts here
    // T represents the number of test cases
    int T;
    // Array to store N numbers, sized 10005 to handle large input
    // (N here is an array of the T input numbers, not a single number)
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

    return 0; // program ended successfully
}
