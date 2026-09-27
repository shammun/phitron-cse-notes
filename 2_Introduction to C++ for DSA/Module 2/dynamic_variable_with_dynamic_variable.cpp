// Topic: a heap (dynamic) variable survives after the function that made it returns.
// Compare with dynamic_variable_with_stack_variable.cpp, where a stack variable does not.
// Output:
//   Fun -> 10
//   Main -> 10

#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

// int *p is a pointer: it stores the address of an int. Because it is global
// (outside every function), both fun and main can read and change it.
int *p; // Declare a global pointer variable 'p' which can be accessed by all functions

// Define a function 'fun' which demonstrates the use of dynamic memory allocation
// void = returns nothing; no parameters.
void fun(){
    // new int asks the heap for one int box and returns its address.
    // The local pointer x (on the stack) dies when fun returns, but the heap box
    // it points to does NOT - heap memory lives until delete is called.
    int *x = new int; // Dynamically allocate memory for an integer variable 'x' in the heap
    *x = 10; // Assign the value 10 to the memory location pointed to by 'x' (*x = "the box x points to")
    p = x; // Copy the address (not the value) into the global pointer 'p': now p and x point to the same heap box
    cout << "Fun -> " << *p << endl; // *p reads the heap box -> prints 10; endl = newline
    return; // Return from the function (x the pointer dies, the heap box stays)
}

// Define the main function which is the entry point of the program
int main(){
    fun(); // Call the function 'fun'
    // Fun -> 10
    // The following line will print the value stored in the dynamically allocated memory
    // because the heap box is not deallocated until we explicitly delete it
    // (only the pointer variable x was destroyed when fun returned, not the box).
    cout << "Main -> " << *p << endl; // Dereference the pointer 'p' and print the value it points to
    // Main -> 10
    // Good habit (not done here): delete p; would give the heap box back.
    // Without it the box "leaks" until the program ends.
    return 0; // Return 0 to indicate successful execution of the program
}