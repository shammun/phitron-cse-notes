#include <iostream> // This header file is used to perform input and output operations
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

int main(){
    int x; // Declaring an integer variable x to store the user input
    cin >> x; // Taking input from the user and storing it in variable x

    // Using the switch statement to check if x is even or odd
    // The expression (x % 2) calculates the remainder when x is divided by 2
    // If the remainder is 0, it means x is even
    // If the remainder is 1, it means x is odd
    switch(x % 2){
        case 0: // If the remainder is 0, execute the following block
            cout << "Even\n"; // Print "Even" followed by a new line
            break; // Exit the switch statement
        case 1: // If the remainder is 1, execute the following block
            cout << "Odd\n"; // Print "Odd" followed by a new line
            break; // Exit the switch statement
    }

    return 0; // return 0 indicates that the program ended successfully
}