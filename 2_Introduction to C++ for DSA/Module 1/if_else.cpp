#include <iostream> // This header file is used to perform input and output operations
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

int main(){
    int x = 6; // Initializing integer variable x with value 6

    // Using the ternary operator to check if x is even or odd
    // The condition (x % 2 == 0) checks if x is divisible by 2 with no remainder, which means x is even
    // If the condition is true, it executes the first part (cout << "Even\n"), which prints "Even" followed by a new line
    // If the condition is false, it executes the second part (cout << "Odd\n"), which prints "Odd" followed by a new line
    x % 2 == 0 ? cout << "Even\n" : cout << "Odd\n"; 
    // Works only when there is only one statement to execute inside if and one statement 
    // to execute inside else

    return 0; // return 0 indicates that the program ended successfully
}