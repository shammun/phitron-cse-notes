#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int *p; // Declare a global pointer variable 'p' which can be accessed by all functions

// Define a function 'fun' which demonstrates the use of dynamic memory allocation
void fun(){
    int *x = new int; // Dynamically allocate memory for an integer variable 'x' in the heap
    *x = 10; // Assign the value 10 to the memory location pointed to by 'x'
    p = x; // Assign the address of the dynamically allocated memory to the global pointer 'p'
    cout << "Fun -> " << *p << endl; // Print the value stored in the dynamically allocated memory using cout
    return; // Return from the function
}

// Define the main function which is the entry point of the program
int main(){
    fun(); // Call the function 'fun'
    // Fun -> 10
    // The following line will print the value stored in the dynamically allocated memory
    // because 'x' is a dynamic variable and its memory is not deallocated until we explicitly delete it
    cout << "Main -> " << *p << endl; // Dereference the pointer 'p' and print the value it points to
    // Main -> 10
    return 0; // Return 0 to indicate successful execution of the program
}