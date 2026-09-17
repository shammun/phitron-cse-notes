/*
Print Recursion
time limit per test: 1 second
memory limit per test: 256 megabytes
Given a number N. Print "I love Recursion" N times.

Note: Solve this problem using recursion.

Input
Only one line containing a number N (1≤N≤100)
Output
Print "I love Recursion" N times.

Example
InputCopy
3
OutputCopy
I love Recursion
I love Recursion
I love Recursion
*/

// Include standard input/output library for printf and scanf functions
#include <stdio.h>

/*
Function name: printRecursion
Parameter: 
    - n: Number of times to print the message (integer)
Purpose: Prints "I love Recursion" n times using recursion
How it works:
    1. Base case: If n becomes 0, return (stop recursion)
    2. Print message once
    3. Call itself with n-1 to print remaining n-1 times
    
Why recursion is used here:
    - The problem requires recursive solution
    - Each recursive call reduces n by 1
    - When n reaches 0, recursion stops
    - The function calls itself n times, printing once in each call
    
Call stack visualization for n=3:
    printRecursion(3)
        prints once
        calls printRecursion(2)
            prints once
            calls printRecursion(1)
                prints once
                calls printRecursion(0)
                    returns (base case)
*/
void printRecursion(int n){
    // Base case: if n becomes 0, stop recursion
    if(n == 0){
        return;
    }
    
    // Print the message once
    printf("I love Recursion\n");
    
    // Recursive call with n-1 to print remaining times
    printRecursion(n-1);
}

/*
Function name: main
Parameters: None
Return value: 0 for successful execution
Purpose: Entry point of program that:
    1. Takes number n as input
    2. Calls printRecursion to print message n times
    3. Returns 0 for successful execution
*/
int main(){
    // Declare variable to store input number
    int n;
    
    // Read integer from user
    // %d is format specifier for integer
    // &n gives address where input should be stored
    scanf("%d", &n);

    // Call printRecursion function with input n
    printRecursion(n);

    // Return 0 to indicate successful execution
    return 0;
}

