#include<iostream> // Include the input/output stream library for using cout
#include<string.h>  // Include C-style string manipulation functions (used in the commented-out section)
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    string s;
    cin >> s; // Take input from the user without spaces

    cout << "We have a string s with the value: " << s << endl; // Output the value of the string
    
    cout << "Output at the first character using s[0] is: " << s[0] << endl; // Output the first character of the string
    cout << "Output at the first character using s.at(0) is: " << s.at(0) << endl; // Output the first character of the string using the at() function
    // Normally, we don't use at() function, rather we use [] operator
    cout << "Output the last character using s.back() is: " << s.back() << endl; // Output the last character of the string using the back() function
    cout << "Output the last character using s[s.size() - 1] is: " << s[s.size() - 1] << endl; // Output the last character of the string
    cout << "Output the first character using s.front() is: " << s.front() << endl; // Output the first character of the string using the front() function

    return 0; // Indicate that the program ended successfully

}