#include<iostream> // Include the input/output stream library for using cout
#include<string.h>  // Include C-style string manipulation functions (used in the commented-out section)
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    // Using C-style strings (char array) for string operations (commented out)
    /*
    char s[10] = "hello"; // Declare a char array with a fixed size of 10 and initialize it with "hello"
    strcpy(s, "world");   // Copy the string "world" into the char array 's'
    */

    // Using std::string (modern and preferred approach in C++) for string operations
    string s = "hello";   // Declare and initialize a std::string with "hello"
    s = "world";          // Reassign the string with a new value "world"
    cout << s << endl;    // Output the value of the string (prints: world)

    // Comparison of two strings
    /*
    char r[10] = "Hello"; // Declare two C-style char arrays with the same content
    char r2[10] = "Hello";
    if(strcmp(r, r2) == 0) { // Use strcmp to compare C-style strings for equality
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }
    */

    // Using std::string to compare two strings (easier and safer)
    string r = "Hello";      // Declare and initialize a std::string with "Hello"
    string r2 = "Hello";     // Declare another std::string with the same value
    if(r == r2) {            // Use the `==` operator for comparison (direct and intuitive)
        cout << "Equal" << endl;  // If strings are the same, output "Equal"
    } else {
        cout << "Not equal" << endl; // If strings are different, output "Not equal"
    }

    // Demonstrating dynamic resizing of std::string
    r = "Hello, how are you?"; // Assign a longer string to the existing std::string 'r'
    cout << r << endl;         // Output the new value of 'r'

    return 0; // Indicate that the program ended successfully
}

/*
 * Explanation for the different string approaches:
 * 
 * 1. C-style strings (char arrays):
 *    - Need a predefined size (e.g., char s[10]) that can lead to buffer overflows if the size is exceeded.
 *    - Operations like assignment and comparison are not straightforward; you need functions like strcpy and strcmp.
 *    - These require manual memory management and are error-prone, especially for beginners.
 * 
 * 2. std::string (modern and recommended):
 *    - No need to specify a fixed size; std::string dynamically adjusts its size based on content.
 *    - Supports intuitive operators for assignment (`=`) and comparison (`==`).
 *    - Provides built-in safety and rich functionality for string manipulation.
 *    - Eliminates the need for external functions like strcpy and strcmp.
 * 
 * Why std::string is preferred:
 * - It is part of the Standard Template Library (STL) in C++.
 * - Offers safer, cleaner, and more powerful string operations.
 * - Avoids common issues like buffer overflow and memory mismanagement.
 * 
 * Key takeaway:
 * Beginners should prefer std::string over C-style strings to write safer and more readable code.
 */
