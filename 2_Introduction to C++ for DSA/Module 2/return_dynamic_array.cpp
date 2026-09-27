// Topic: returning an array from a function.
// The array must be made on the heap with new; a normal local array would die
// when the function returns. Program: read 5 numbers inside dynamic_array(),
// return the array to main, print it.
// Example: input 1 2 3 4 5 -> output: an empty line, then "1 2 3 4 5 "

#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

/*
 * The following function 'static_array' is commented out because it demonstrates
 * an incorrect approach to returning arrays from functions. The array 'a' is
 * declared as a local static array, which means it is stored in stack memory.
 * Returning a pointer to this array is unsafe because the memory is deallocated
 * once the function exits, leading to undefined behavior or segmentation faults.
 *
 * (Wording note: "static array" in this course means a normal fixed-size local
 *  array like int a[5]. It is NOT the C++ keyword static - an array declared
 *  "static int a[5];" would actually live until the program ends and be safe to return.
 *  g++ also warns "address of local variable returned" for this function.)
 */
/*
int *static_array(){
    int a[5]; // Declare a static array 'a' of size 5
    for(int i=0; i<5; i++){
        cin >> a[i]; // Read input from the user and store it in the array 'a'
    }
    return a; // Return the address of the static array 'a'
}
*/

/*
 * The function 'dynamic_array' demonstrates the correct way to return an array
 * from a function. It uses dynamic memory allocation to create an array in the
 * heap, which persists beyond the function's scope. This allows the returned
 * pointer to be safely used in the calling function.
 *
 * No parameters. Return type int* = "address of an int" (the first box of the array).
 */
int *dynamic_array(){
    // new int[5] asks the heap for 5 int boxes and returns the address of the first;
    // p[i] then reaches box i exactly like a normal array.
    int *p = new int[5]; // Dynamically allocate memory for an array of 5 integers
    for(int i=0; i<5; i++){ // i = 0..4, one number per pass
        cin >> p[i]; // Read input from the user and store it in the dynamic array
    }
    return p; // Return the pointer to the dynamically allocated array (the heap boxes stay alive)
}

int main(){ // the program starts running here
    /*
     * The following code is commented out because it attempts to use the
     * 'static_array' function, which would result in a segmentation fault.
     * This is because the array 'a' is stored in stack memory and is deallocated
     * after the function call, making the returned pointer invalid.
     * (A crash is not guaranteed: it is undefined behaviour, so it may print
     *  garbage, crash, or even look correct by luck.)
     */
    /*
    int *x = static_array();
    for(int i=0; i<5; i++){
        cout << x[i] << " "; // Attempt to print the elements of the invalid array
    }
    */

    cout << endl; // Print a newline character for better output formatting (so the output starts with an empty line)

    /*
     * The following code correctly uses the 'dynamic_array' function to obtain
     * a pointer to a dynamically allocated array. This array is stored in heap
     * memory, so it remains valid after the function call, allowing us to safely
     * access and print its elements.
     */
    int *y = dynamic_array(); // Call the function 'dynamic_array' and store the returned pointer
    for(int i=0; i<5; i++){ // i = 0..4
        cout << y[i] << " "; // Print the value of each element in the dynamic array
    }

    // Free the dynamically allocated memory to avoid memory leaks
    // (delete[] with brackets because it is an array, not a single int)
    delete[] y;

    return 0; // Return 0 to indicate successful execution of the program
}