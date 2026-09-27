// Topic: reading several values of different types in one cin statement.
// Example input:  5 A 3.14
// Example output: 5 A 3.14

#include <iostream> // This is the header file that allows us to use input and output objects like std::cin and std::cout
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

// main() is where the program starts running.
int main(){
    int x; // Declaring an integer variable x
    char c; // Declaring a character variable c (holds exactly one character)
    double d; // Declaring a double (floating-point) variable d (a number with a decimal part)

    // Taking multiple inputs from the user and storing them in variables x, c, and d respectively
    // cin is used to take input from the user
    // The '>>' operator is used to extract the input values and store them in the respective variables
    // The reads happen left to right; spaces/newlines between values are skipped.
    // cin uses each variable's type: x reads digits as an int, c reads one non-space character,
    // d reads a decimal number. (In C this would be scanf("%d %c %lf", &x, &c, &d);)
    cin >> x >> c >> d;

    // Printing the values of x, c, and d separated by spaces
    // cout is used to print output to the console
    // The '<<' operator is used to send the values of x, c, and d to the output stream
    // " " is a string holding one space, printed between the values
    // endl is used to print a new line
    cout << x << " " << c << " " << d << endl;

    return 0; // return 0 indicates that the program ended successfully
}