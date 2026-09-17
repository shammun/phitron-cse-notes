/*
This program demonstrates why swapping values doesn't work when:
1. Variables are passed by value (copies are passed)
2. Variables are declared independently in different functions

Key concepts illustrated:
- Function scope: Variables in different functions are independent
- Memory addresses: Shows how variables have different addresses
- Pass by value: Function gets copies, not original variables
*/

#include <stdio.h>

/*
Function: swap()
- Purpose: Attempts to swap two numbers but fails due to scope
- Problem 1: Creates new variables instead of using main's variables
- Problem 2: Changes to local variables don't affect main's variables
- Note: %p format prints addresses to show variables are different
*/
void swap(){
    // These are NEW variables, different from main's a and b
    int a = 10, b = 20;
    
    // Print to show we're inside swap function
    printf("Inside swap function\n");
    
    // Print addresses to prove these are different variables than main's
    printf("Inside swap function: %p %p\n", &a, &b);
    
    // Traditional swap logic using temporary variable
    int temp = a;
    a = b;
    b = temp;
    
    // Values are swapped here but only affect local copies
    printf("Inside function, swapped values: a = %d, b = %d\n", a, b);
}

/*
Function: main()
- Purpose: Shows why swap doesn't work across function boundaries
- Demonstrates:
  1. Variables have different addresses than swap's variables
  2. Calling swap() doesn't affect main's variables
  3. Need for proper parameter passing (covered in later examples)
*/
int main(){
    // Declare and initialize main's variables
    int a = 10, b = 20;
    
    // Print to show we're in main function
    printf("Inside main function\n");
    
    // Print addresses to compare with swap function's addresses
    printf("Inside main function: %p %p\n", &a, &b);
    
    // Show values before attempted swap
    printf("Before calling swap function: a = %d, b = %d\n", a, b);
    
    // Call swap (note: values won't actually swap)
    swap(a, b);
    
    // Values remain unchanged because swap worked on different variables
    printf("After calling swap function: a = %d, b = %d\n", a, b);
    return 0;
}