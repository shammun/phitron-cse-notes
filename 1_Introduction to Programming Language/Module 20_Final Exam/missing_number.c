/*
Problem Statement

Given the multiplication of four numbers and three of those numbers, find the missing number.

Note: If the missing number could not be found for the given input, print -1. All numbers are non-negative integers.

Input Format

The first line will contain T, number of test cases.
For every test case, the input will contain one integer M (the multiplication of the four numbers), A, B, C (three of those four numbers).
Constraints

1 < T <= 100000
0 <= M <= 10^18
1 <= A, B, C <= 10^6
Output Format

Print the missing number. Don't forget to print a new line after it.
Sample Input 0

4
20 1 2 2
10 2 2 1
1 1 2 3
0 3 10 15
Sample Output 0

5
-1
-1
0
Sample Input 1

3
20 5 1 1
18 2 3 3
0 10 20 30
Sample Output 1

4
1
0
*/
#include <stdio.h>

int main(){
    // T represents the number of test cases
    int T;
    // Using %d format specifier since T is an integer
    scanf("%d", &T);
    
    // Using long long array to store results since the multiplication can be very large (up to 10^18)
    // Array size is 100005 to accommodate maximum possible test cases (100000) with buffer
    long long results[100005];

    // Loop through each test case
    for(int i=0; i<T; i++){
        // M is the multiplication of all 4 numbers (can be up to 10^18)
        // A, B, C are 3 of the 4 numbers (up to 10^6 each)
        // Using %lld format specifier for long long data type
        long long M, A, B, C;
        scanf("%lld %lld %lld %lld", &M, &A, &B, &C);

        // Calculate if M is perfectly divisible by product of A, B, and C
        // If it is, then the quotient is our missing number
        // Using modulo (%) operator to check divisibility
        long long remainder = M % (A*B*C);

        if(remainder == 0){
            // If remainder is 0, M is perfectly divisible
            // The missing number is M divided by product of A, B, C
            results[i] = M / (A*B*C);
        }else{
            // If there's a remainder, no valid integer solution exists
            // Store -1 as per problem requirements
            results[i] = -1;
        }
    }

    // Print results for all test cases
    // Using %lld format specifier to print long long values
    for(int i=0; i<T; i++){
        printf("%lld\n", results[i]);
    }
}