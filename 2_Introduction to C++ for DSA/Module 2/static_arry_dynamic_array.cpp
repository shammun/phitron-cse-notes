#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int main(){
    // Static array
    // Declare a static array 'a' of size 5. Static arrays are allocated on the stack.
    int a[5];
    // Use a for loop to take input for each element of the static array 'a'
    for(int i=0; i<5; i++){
        cin >> a[i]; // Read input from the user and store it in the array 'a'
    }
    // Use another for loop to print each element of the static array 'a'
    for(int i=0; i<5; i++){
        cout << a[i] << " "; // Print the value of each element in the array 'a'
    }

    cout << endl; // Print a newline character for better output formatting

    // Dynamic array
    // Declare a pointer 'p' and allocate memory for an array of 5 integers in the heap using the 'new' keyword
    int *p = new int[5];
    // Use a for loop to take input for each element of the dynamic array pointed to by 'p'
    for(int i=0; i<5; i++){
        cin >> p[i]; // Read input from the user and store it in the dynamic array
    }

    // Use another for loop to print each element of the dynamic array pointed to by 'p'
    for(int i=0; i<5; i++){
        cout << p[i] << " "; // Print the value of each element in the dynamic array
    }

    // Free the dynamically allocated memory to avoid memory leaks
    delete[] p;

    return 0; // Return 0 to indicate successful execution of the program
}