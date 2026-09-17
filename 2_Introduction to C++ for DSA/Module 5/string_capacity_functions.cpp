#include<iostream> // Include the input/output stream library for using cout
#include<string.h>  // Include C-style string manipulation functions (used in the commented-out section)
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    string s = "Hello"; // Declare and initialize a std::string with "Hello"
    cout << s.size() << endl; // Output the size of the string (prints: 5)

    cout << "The maximum size of the string is: " << s.max_size() << endl; 
    // Output the maximum size ((based on the capacity of the compiler) of the string
    // Normally 10^6

    cout << "The capacity of the string is: " << s.capacity() << endl; 
    // Output the current capacity of the string (related to dynamic memory allocation)
    // This can be increased dynamically as needed
    // capcity() and max_size() will not be needed for most practical tasks

    s.clear(); // Clear the contents of the string
    cout << "The value of s after using s.clear() is: " << s << endl; // Output the cleared string (prints: "")
    cout << "The size of the cleared string is: " << s.size() << endl; // Output the size of the cleared string (prints: 0)
    cout << "The capacity of the cleared string is: " << s.capacity() << endl; // Output the capacity of the cleared string (prints: 15)
    // Note: The capacity remains the same after clearing the string

    // Checking empty string
    if(s.empty()){
        cout << "The string is empty" << endl; // Output if the string is empty
    } else {
        cout << "The string is not empty" << endl; // Output if the string is not empty
    }

    // Resizing the string
    s = "I would like to resize this string"; // Assign a new value to the string
    s.resize(10);
    cout << "The value of s after using s.resize(10) is: " << s << endl; // Output the resized string (prints: I would li)
    
    // Now, we will increase the size of the string
    s.resize(15);
    cout << "The value of s after using s.resize(15) is: " << s << endl; // Output the resized string (prints: I would like to)
    // It adds NUL characters to fill the remaining space

    // Now, make the string smaller again
    s.resize(10);
    cout << "The valus of s is again: " << s << endl; // Output the resized string (prints: I would li)
    // To avoid having NUL when the string is smaller than the resized string size, we can specify the character to fill the remaining space
    s.resize(15, 'x');
    cout << "The value of s after using s.resize(15, 'x') is: " << s << endl; // Output the resized string with 'x' filling the remaining space (prints: I would lixxxx)

    return 0; // Indicate that the program ended successfully
}