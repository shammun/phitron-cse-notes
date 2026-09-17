#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int main(){
    // First we create a static array 'a' of size 3
    // Static arrays are allocated on the stack and have a fixed size
    int a[3];
    cout << "Enter the elements of the static array: " << endl;
    // Use a for loop to take input for each element of the static array 'a'
    for(int i=0; i<3; i++){
        cin >> a[i]; // Read input from the user and store it in the array 'a'
    }

    // Create another static array 'b' of size 5
    // This array is larger to accommodate additional elements
    int b[5];
    // Copy the elements of array 'a' into array 'b'
    for(int i=0; i<3; i++){
        b[i] = a[i]; // Copy each element from 'a' to 'b'
    }
    // Add additional elements to the new positions in array 'b'
    b[3] = 40;
    b[4] = 50;

    // Print the elements of the new static array 'b'
    cout << "The elements of the new array after using an array of size 5 are: " << endl;
    for(int i=0; i<5; i++){
        cout << b[i] << " "; // Print each element of the array 'b'
    }

    // Static arrays remain in the stack memory

    cout << endl; // Print a newline character for better output formatting

    // Now we create a dynamic array 'p' of size 3
    // Dynamic arrays are allocated on the heap and can be resized
    int *p = new int[3];
    cout << "Enter the elements of the dynamic array: " << endl;
    // Use a for loop to take input for each element of the dynamic array pointed to by 'p'
    for(int i=0; i<3; i++){
        cin >> p[i]; // Read input from the user and store it in the dynamic array
    }

    // Create another dynamic array 'q' of size 5
    // This array is larger to accommodate additional elements
    int *q = new int[5];
    // Copy the elements of the dynamic array 'p' into the new dynamic array 'q'
    for(int i=0; i<3; i++){
        q[i] = p[i]; // Copy each element from 'p' to 'q'
    }
    // Add additional elements to the new positions in array 'q'
    q[3] = 40;
    q[4] = 50;

    cout << endl; // Print a newline character for better output formatting
    // Print the elements of the new dynamic resized array 'q'
    cout << "The elements of the new dynamic resized array are: " << endl;
    for(int i=0; i<5; i++){
        cout << q[i] << " "; // Print each element of the dynamic array 'q'
    }

    // Free the dynamically allocated memory to avoid memory leaks
    delete[] p;

    return 0; // Return 0 to indicate successful execution of the program
}