// Topic: the different ways to read one character of a C++ string:
// s[i], s.at(i), s.front() (first character) and s.back() (last character).
// Positions (indexes) start at 0, so a string of size n has indexes 0 .. n-1.

#include<iostream> // Include the input/output stream library for using cin and cout
#include<string.h>  // C-style string functions (strlen, strcpy...); not actually used in this file
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() { // program starts here
    string s; // a C++ string: holds text and knows its own size (string comes in through <iostream> here)
    cin >> s; // Take input from the user without spaces (cin >> stops reading at the first space)

    cout << "We have a string s with the value: " << s << endl; // Output the value of the string

    // For input "hello": s[0] is 'h'
    cout << "Output at the first character using s[0] is: " << s[0] << endl; // Output the first character of the string
    // s.at(0) gives the same character as s[0]. The difference: at() checks the index
    // and throws an error (std::out_of_range) if it is outside the string, while []
    // does no check at all (a wrong index silently reads garbage).
    cout << "Output at the first character using s.at(0) is: " << s.at(0) << endl; // Output the first character of the string using the at() function
    // Normally, we don't use at() function, rather we use [] operator
    cout << "Output the last character using s.back() is: " << s.back() << endl; // Output the last character of the string using the back() function ("hello" -> 'o')
    // s.size() is the number of characters, so the last index is s.size() - 1 ("hello": size 5, last index 4)
    cout << "Output the last character using s[s.size() - 1] is: " << s[s.size() - 1] << endl; // Output the last character of the string
    cout << "Output the first character using s.front() is: " << s.front() << endl; // Output the first character of the string using the front() function (same as s[0])

    return 0; // Indicate that the program ended successfully

}
