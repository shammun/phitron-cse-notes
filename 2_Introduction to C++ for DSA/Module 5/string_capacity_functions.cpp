// Topic: string "capacity" functions - size(), max_size(), capacity(), clear(),
// empty() and resize(). size() = how many characters the string holds now;
// capacity() = how many it could hold before it must grab more memory.

#include<iostream> // Include the input/output stream library for using cout
#include<string.h>  // C-style string functions (strlen, strcpy...); not actually used in this file
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() { // program starts here
    string s = "Hello"; // Declare and initialize a std::string with "Hello"
    cout << s.size() << endl; // Output the size of the string (prints: 5). s.length() gives the same number.

    cout << "The maximum size of the string is: " << s.max_size() << endl;
    // Output the maximum size (the largest length this string type could ever have on this system)
    // Fixed: this is NOT about 10^6 - it is a huge number, 4611686018427387903 (about 4.6 * 10^18)
    // with 64-bit g++. In practice memory runs out long before that.

    cout << "The capacity of the string is: " << s.capacity() << endl;
    // Output the current capacity of the string (related to dynamic memory allocation)
    // This can be increased dynamically as needed
    // g++ prints 15 here: short strings (up to 15 chars) are kept inside the string object itself.
    // capcity() and max_size() will not be needed for most practical tasks

    s.clear(); // Clear the contents of the string: size becomes 0, the text becomes ""
    cout << "The value of s after using s.clear() is: " << s << endl; // Output the cleared string (prints: "")
    cout << "The size of the cleared string is: " << s.size() << endl; // Output the size of the cleared string (prints: 0)
    cout << "The capacity of the cleared string is: " << s.capacity() << endl; // Output the capacity of the cleared string (prints: 15)
    // Note: The capacity remains the same after clearing the string (the memory is kept for reuse)

    // Checking empty string: s.empty() is true when size() == 0
    if(s.empty()){
        cout << "The string is empty" << endl; // Output if the string is empty (this is what prints here)
    } else {
        cout << "The string is not empty" << endl; // Output if the string is not empty
    }

    // Resizing the string: resize(n) makes the size exactly n -
    // cutting characters off the end if n is smaller, adding characters if n is bigger.
    s = "I would like to resize this string"; // Assign a new value to the string
    s.resize(10); // keep only the first 10 characters (indexes 0..9)
    cout << "The value of s after using s.resize(10) is: " << s << endl; // Output the resized string (prints: I would li)

    // Now, we will increase the size of the string
    s.resize(15); // grow from 10 to 15 characters
    // Fixed: the cut-off text does NOT come back. The 5 new characters are '\0' (NUL),
    // which are invisible, so it looks like "I would li" (followed by 5 hidden NULs).
    cout << "The value of s after using s.resize(15) is: " << s << endl; // Output the resized string (prints: I would li + 5 invisible NULs)
    // It adds NUL characters to fill the remaining space

    // Now, make the string smaller again
    s.resize(10); // drop the 5 NULs again
    cout << "The valus of s is again: " << s << endl; // Output the resized string (prints: I would li)
    // To avoid having NUL when the string is smaller than the resized string size, we can specify the character to fill the remaining space
    s.resize(15, 'x'); // grow to 15 and fill the 5 new places with 'x'
    cout << "The value of s after using s.resize(15, 'x') is: " << s << endl; // Output the resized string with 'x' filling the remaining space (prints: I would lixxxxx - five x's)

    return 0; // Indicate that the program ended successfully
}
