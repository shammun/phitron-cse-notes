// Topic: reading a whole line (spaces included) into a C++ string with getline,
// and the cin >> + getline trap that cin.ignore() fixes.

#include<iostream> // Include the input/output stream library for using cin and cout
#include <string>   // Include the string library for std::string and getline(cin, s)
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() { // program starts here
    // previously, we used cin.getline(s, 100) to take input with spaces -- for character array char s[100]

    string s; // will hold one full line
    // getline(cin, s) reads everything up to the end of the line (the Enter key),
    // spaces included, stores it in s, and throws the '\n' away.
    // (cin >> s would stop at the first space: "Hello world" -> "Hello".)
    getline(cin, s); // Take input from the user with spaces
    cout << "The string entered is: " << s << endl; // Output the entered string

    // Suppose now, we want to insert integer value in one line, followed by a string with spaces in the next line
    // If we use cin >> x, followed by getline(cin, s) then it will not work for the second line as getline
    // will take the newline character in the first line as input and the string will be empty
    // To avoid this, we can use cin.ignore() to ignore the newline character after cin >> x
    // Input "5\nHello there": cin >> x reads 5 and leaves "\nHello there" waiting.
    // Without ignore, getline sees the '\n' first and returns "" at once.

    int x;       // the number on its own line
    string s2;   // the line of text after it
    cin >> x;    // reads the number only; the '\n' after it stays in the input
    cin.ignore(); // Ignore the newline character after cin >> x (skips exactly one character)
    getline(cin, s2); // now reads the real next line into s2
    cout << "The integer entered is: " << x << endl; // Output the entered integer
    cout << "The string entered is: " << s2 << endl; // Output the entered string

    return 0; // Indicate that the program ended successfully
}
