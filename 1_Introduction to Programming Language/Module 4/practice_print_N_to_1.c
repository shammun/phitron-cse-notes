/*
Print from N to 1
time limit per test1 second
memory limit per test64 megabytes
Given a number N. Print all numbers from N to 1 separated by a single space.

Note: Solve this problem using recursion.

Input
Only one line containing a number N (1 ≤ N ≤ 103).

Output
Print from N to 1 separated by a single space.

Example
InputCopy
4
OutputCopy
4 3 2 1
Note
Make sure don't print any leading or trailing spaces.
*/

#include <stdio.h>

/*
Function name: print_N_to_1
Parameters:
    - x: Starting number (integer)
    - n: Upper limit number (integer)
Purpose: Prints numbers from n down to x using recursion in descending order

How it works:
    1. Base case: If x > n, return (stop recursion)
    2. Make recursive call first with x+1 
    3. Then print current number x
    
Why this order matters:
    - To print in descending order (N to 1), we need to reach N first
    - Making recursive call before printing ensures we reach N first
    - Then while returning from recursion, numbers get printed in reverse
    
Call stack visualization for n=4, starting x=1:
    print_N_to_1(1, 4)
        calls print_N_to_1(2, 4)
            calls print_N_to_1(3, 4)
                calls print_N_to_1(4, 4)
                    calls print_N_to_1(5, 4)
                        returns (base case: 5 > 4)
                    prints 4
                prints 3
            prints 2
        prints 1

Why space is used instead of newline:
    - Problem requires all numbers on same line
    - Space separator between numbers
    - Last number should not be followed by space
*/
void print_N_to_1(int x, int n){
    // Base case: if x exceeds n, stop recursion
    if(x > n){
        return;
    }
    
    // First make recursive call to reach N
    print_N_to_1(x+1, n);

    // After returning from recursion, print current number
    // Print space only if it's not the first number (x > 1)
    // This avoids trailing space at the end
    if(x > 1){
        printf("%d ", x);
    } else {
        printf("%d", x);  // Last number (1) without space
    }
}

/*
Function name: main
Parameters: None
Return value: 0 for successful execution
Purpose: 
    - Takes input N from user
    - Calls print_N_to_1 to print numbers N to 1
    - Returns 0 to indicate successful execution
*/
int main(){
    // Declare variable to store input number
    int n;
    
    // Read integer from user
    // %d is format specifier for integer
    // &n gives address where input should be stored
    scanf("%d", &n);
    
    // Call print_N_to_1 starting from 1 up to n
    print_N_to_1(1, n);
    
    // Return 0 to indicate successful program execution
    return 0;
}