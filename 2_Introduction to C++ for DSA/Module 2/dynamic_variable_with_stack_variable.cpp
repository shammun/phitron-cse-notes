// Topic: a stack (normal local) variable dies when its function returns, so a
// pointer that still holds its address becomes a "dangling pointer".
// Compare with dynamic_variable_with_dynamic_variable.cpp, where new keeps the value alive.
// One run on this machine printed:
//   Fun -> 10
//   Main -> 0      (garbage - not guaranteed, could be any value)

#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

// int *p is a pointer: it stores the address of an int. Global, so fun and main share it.
int *p; // Declare a global pointer variable 'p' which can be accessed by all functions

// Define a function 'fun' which demonstrates the use of stack memory
// void = returns nothing; no parameters.
void fun(){
    int x = 10; // Declare an integer variable 'x' in stack memory (fun's frame) and initialize it to 10
    p = &x; // &x = "address of x": the global pointer 'p' now remembers where x lives
    cout << "Fun -> " << x << endl; // Print the value of 'x' using cout (x is still alive -> 10)
    return; // Return from the function: fun's stack frame, including x, is released now
}

// Define the main function which is the entry point of the program
int main(){
    fun(); // Call the function 'fun'
    // Fun -> 10
    // The following line will print an undefined value or may cause a runtime error
    // because 'x' is a stack variable and its memory is deallocated after 'fun' returns
    // (p still holds x's old address, but that memory may already be reused by
    //  other code - e.g. by cout itself - so *p reads whatever is there now).
    cout << "Main -> " << *p << endl; // Dereference the pointer 'p' and print the value it points to
    // Main -> garbage (0 on one run here; it CAN still show 10 by luck, which is why
    // this bug is dangerous - it may look fine and then break later).
    // (Fixed: the old comment said "Main -> 10", which contradicts the point above.)
    return 0; // Return 0 to indicate successful execution of the program
}