#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    // previously, we used cin.getline(s, 100) to take input with spaces -- for character array char s[100] 

    string s;
    getline(cin, s); // Take input from the user with spaces
    cout << "The string entered is: " << s << endl; // Output the entered string

    // Suppose now, we want to insert integer value in one line, followed by a string with spaces in the next line
    // If we use cin >> x, followed by getline(cin, s) then it will not work for the second line as getline
    // will take the newline character in the first line as input and the string will be empty
    // To avoid this, we can use cin.ignore() to ignore the newline character after cin >> x

    int x;
    string s2;
    cin >> x;
    cin.ignore(); // Ignore the newline character after cin >> x
    getline(cin, s2);
    cout << "The integer entered is: " << x << endl; // Output the entered integer
    cout << "The string entered is: " << s2 << endl; // Output the entered string

    return 0; // Indicate that the program ended successfully
}