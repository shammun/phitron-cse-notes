#include <iostream> // This is the header file that allows us to use input and output objects like std::cin and std::cout
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

int main(){
    int x;
    // Taking input from the user and storing it in variable x
    cin >> x;
    // Printing the value of x followed by a new line
    cout << x << endl;

    char c = 'A'; // Initializing character variable c with 'A'
    int ASCII_value = c; // Storing the ASCII value of character c in integer variable ASCII_value
    // Printing the ASCII value of character c
    cout << ASCII_value << endl;

    // Typecasting character c to its integer ASCII value and printing it
    cout << (int)c << endl;

    int y = 65; // Initializing integer variable y with 65
    // Typecasting integer y to its corresponding character and printing it
    cout << (char)y << endl;

    return 0;
}