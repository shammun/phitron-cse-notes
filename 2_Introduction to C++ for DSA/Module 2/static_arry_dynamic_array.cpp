// Topic: the same job done with a static (stack) array and a dynamic (heap) array.
// Both are read and printed the same way; the difference is where they live and
// who frees them. Reads 5 numbers into each and prints each group on its own line.
// Example: input 1 2 3 4 5 6 7 8 9 10 -> "1 2 3 4 5 " then "6 7 8 9 10 "

#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int main(){ // the program starts running here
    // Static array
    // Declare a static array 'a' of size 5. Static arrays are allocated on the stack.
    // (Its size is fixed when the code is written, and it is freed automatically when main ends.)
    int a[5];
    // Use a for loop to take input for each element of the static array 'a'
    // i = 0..4; the loop stops when i becomes 5
    for(int i=0; i<5; i++){
        cin >> a[i]; // Read input from the user and store it in the array 'a' (cin skips spaces)
    }
    // Use another for loop to print each element of the static array 'a'
    for(int i=0; i<5; i++){
        cout << a[i] << " "; // Print the value of each element in the array 'a'
    }

    cout << endl; // Print a newline character for better output formatting

    // Dynamic array
    // Declare a pointer 'p' and allocate memory for an array of 5 integers in the heap using the 'new' keyword
    // new int[5] returns the address of the first box; p stores it.
    // Heap memory is NOT freed automatically - we must call delete[] ourselves.
    int *p = new int[5];
    // Use a for loop to take input for each element of the dynamic array pointed to by 'p'
    for(int i=0; i<5; i++){
        cin >> p[i]; // Read input from the user and store it in the dynamic array (p[i] = box i)
    }

    // Use another for loop to print each element of the dynamic array pointed to by 'p'
    for(int i=0; i<5; i++){
        cout << p[i] << " "; // Print the value of each element in the dynamic array
    }

    // Free the dynamically allocated memory to avoid memory leaks
    // (delete[] with brackets because p points to an array, not one int)
    delete[] p;

    return 0; // Return 0 to indicate successful execution of the program
}