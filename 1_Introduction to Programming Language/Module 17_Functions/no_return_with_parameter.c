/*
This program demonstrates functions that:
1. Don't return any value (void return type)
2. Take parameters (values passed to function)

Such functions are useful when:
- We want to perform operations on input values
- We want to display results directly rather than returning them
- We want to make functions reusable with different input values
*/

#include <stdio.h>

/*
Function: add()
- Return type: void (doesn't return any value)
- Parameters: Two integers a and b
- Purpose: Adds two numbers and prints their sum
- Note: Unlike no_return_no_parameter.c, this gets values through parameters
       instead of scanf() inside function, making it more reusable
*/
void add(int a, int b){
    printf("function called\n");
    int sum = a + b;               // Calculate sum of parameters
    printf("Sum: %d\n", sum);      // Display result
}

/*
Function: alphacheck()
- Return type: void (doesn't return any value) 
- Parameters: One character ch
- Purpose: Checks if a character is lowercase or uppercase
- Logic: 
  - ASCII values of 'a' to 'z' are consecutive
  - If character ASCII value falls between 'a' and 'z', it's lowercase
  - Otherwise (assuming it's a letter), it's uppercase
*/
void alphacheck(char ch){
    if('a' <= ch && ch <= 'z'){    // Check if character is between 'a' and 'z'
        printf("Lowercase\n");
    } else{
        printf("Uppercase\n");
    }
}

/*
Function: main()
- Return type: int (returns 0 for successful execution)
- Purpose: Entry point of program that demonstrates:
  1. Getting input from user
  2. Calling add() with parameters
  3. Calling alphacheck() with different characters
*/
int main(){
    int a, b;                      // Variables to store user input
    scanf("%d %d", &a, &b);        // Get two numbers from user
    add(a, b);                     // Call add() with user input
    alphacheck('a');               // Test with lowercase 'a'
    alphacheck('B');               // Test with uppercase 'B'
    return 0;
}