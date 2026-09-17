#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    //string s = "Hello"; // Create a string object 's' and initialize it with the string "Hello";
    // Creating constructor of string -- 1st way
    string s("Hello"); // Create a string object 's' and initialize it with the string "Hello";
    cout << s << endl; // Output the string "Hello"

    // Creating constructor of string -- 2nd way
    string s2 = "Hello"; // Create a string object 's' and initialize it with the string "Hello";
    cout << s2 << endl; // Output the string "Hello"

    // Creating constructor of string -- 3rd way
    string s3("Hello", 3); // Create a string object 's' and initialize it with the string "Hel";
    // this 3 means that we are taking only 3 characters from the string "Hello"
    cout << s3 << endl; // Output the string "Hel"

    // Creating constructor of string -- 4th way -- 
    string s4(s, 2); // create a string from s and remove the first 2 characters
    cout << s4 << endl; // Output the string "llo"
    
    // Creating constructor of string -- 5th way
    // Create a string of size 5 with all characters as 'a'
    string s5(5, 'a'); // Create a string of size 5 with all characters as 'a'
    cout << s5 << endl; // Output the string "aaaaa"


    return 0; // Indicate that the program ended successfully
}