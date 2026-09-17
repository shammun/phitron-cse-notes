/*
Print from 1 to N
time limit per test1 second
memory limit per test64 megabytes
Given a number N. Print numbers from 1 to N in separate lines.

Note: Solve this problem using recursion.

Input
Only one line containing a number N (1 ≤ N ≤ 103).

Output
Print N lines according to the required above.

Example
InputCopy
5
OutputCopy
1
2
3
4
5
*/

// Include standard input/output library for printf and scanf functions
#include <stdio.h>

/*
Function name: print_1_to_N
Parameters:
    - x: Current number to print (integer)
    - n: Upper limit number to print up to (integer)
Purpose: Prints numbers from x to n using recursion
How it works:
    1. Base case: If x exceeds n, return (stop recursion)
    2. Print current number x
    3. Call itself with x+1 to print next number
    
Why recursion is used here:
    - The problem requires recursive solution
    - Each recursive call increases x by 1
    - When x exceeds n, recursion stops
    - The function calls itself (n-x+1) times
    
Call stack visualization for n=3, starting x=1:
    print_1_to_N(1, 3)
        prints 1
        calls print_1_to_N(2, 3)
            prints 2
            calls print_1_to_N(3, 3)
                prints 3
                calls print_1_to_N(4, 3)
                    returns (base case: 4 > 3)

Why \n is used instead of space:
    - Problem requires numbers to be printed in separate lines
    - \n creates a new line after each number
    - Using space would print all numbers on same line
*/
void print_1_to_N(int x, int n){
    // Base case: if x exceeds n, stop recursion
    if(x > n){
        return;
    }
    
    // Print current number followed by newline
    printf("%d\n", x);
    
    // Recursive call with next number (x+1)
    print_1_to_N(x+1, n);
}

/*
Function name: main
Parameters: None
Return value: 0 for successful execution
Purpose: Entry point of program that:
    1. Takes number n as input
    2. Calls print_1_to_N to print numbers 1 to n
    3. Returns 0 for successful execution
*/
int main(){
    // Declare variable to store input number
    int n;
    
    // Read integer from user
    // %d is format specifier for integer
    // &n gives address where input should be stored
    scanf("%d", &n);
    
    // Call print_1_to_N starting from 1 up to n
    print_1_to_N(1, n);
    
    // Return 0 to indicate successful program execution
    return 0;
}