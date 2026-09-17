#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int *p; // Declare a global pointer variable 'p' which can be accessed by all functions

// Define a function 'fun' which demonstrates the use of stack memory
void fun(){
    int x = 10; // Declare an integer variable 'x' in stack memory and initialize it to 10
    p = &x; // Assign the address of 'x' to the global pointer 'p'
    cout << "Fun -> " << x << endl; // Print the value of 'x' using cout
    return; // Return from the function
}

// Define the main function which is the entry point of the program
int main(){
    fun(); // Call the function 'fun'
    // Fun -> 10
    // The following line will print an undefined value or may cause a runtime error
    // because 'x' is a stack variable and its memory is deallocated after 'fun' returns
    cout << "Main -> " << *p << endl; // Dereference the pointer 'p' and print the value it points to
    // Main -> 10
    return 0; // Return 0 to indicate successful execution of the program
}