#include <iostream> // This is the header file that allows us to use input and output objects like std::cin and std::cout
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

int main(){
    int x; // Declaring an integer variable x
    char c; // Declaring a character variable c
    double d; // Declaring a double (floating-point) variable d

    // Taking multiple inputs from the user and storing them in variables x, c, and d respectively
    // cin is used to take input from the user
    // The '>>' operator is used to extract the input values and store them in the respective variables
    cin >> x >> c >> d;

    // Printing the values of x, c, and d separated by spaces
    // cout is used to print output to the console
    // The '<<' operator is used to send the values of x, c, and d to the output stream
    // endl is used to print a new line
    cout << x << " " << c << " " << d << endl;

    return 0; // return 0 indicates that the program ended successfully
}