// Topic: writing a tiny if/else in one line with the ternary operator  condition ? A : B
// Output (x = 6): Even

#include <iostream> // This header file is used to perform input and output operations
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

// main() is where the program starts running.
int main(){
    int x = 6; // Initializing integer variable x with value 6

    // Using the ternary operator to check if x is even or odd.
    // Shape:  condition ? do_this_if_true : do_this_if_false ;
    // The condition (x % 2 == 0) checks if x is divisible by 2 with no remainder, which means x is even
    // (% is the remainder operator: 6 % 2 = 0, 7 % 2 = 1).
    // If the condition is true, it executes the first part (cout << "Even\n"), which prints "Even" followed by a new line
    // If the condition is false, it executes the second part (cout << "Odd\n"), which prints "Odd" followed by a new line
    // ("\n" is the newline character; unlike endl it does not flush, so it is slightly faster.)
    // It is the same as:  if (x % 2 == 0) cout << "Even\n"; else cout << "Odd\n";
    x % 2 == 0 ? cout << "Even\n" : cout << "Odd\n";
    // Works only when there is only one statement to execute inside if and one statement
    // to execute inside else

    return 0; // return 0 indicates that the program ended successfully
}