/*
Different ways to create (construct) a string.

string is a class, so creating a string runs one of its constructors.
Which constructor runs depends on what you put in the brackets.
*/

#include<iostream> // Gives us cout (print to screen)
#include <string>   // Gives us std::string and its constructors
#include <sstream> // stringstream library; not actually used in this file
using namespace std; // Lets us write cout, string instead of std::cout, std::string

int main() {
    //string s = "Hello"; // Create a string object 's' and initialize it with the string "Hello";
    // Creating constructor of string -- 1st way
    string s("Hello"); // Create a string object 's' and initialize it with the text "Hello"
    cout << s << endl; // Output the string "Hello"

    // Creating constructor of string -- 2nd way
    string s2 = "Hello"; // Create a string object 's2' and initialize it with "Hello" (same result as the 1st way)
    cout << s2 << endl; // Output the string "Hello"

    // Creating constructor of string -- 3rd way
    string s3("Hello", 3); // Create a string object 's3' from the first 3 characters of "Hello" -> "Hel"
    // this 3 means that we are taking only 3 characters from the string "Hello"
    cout << s3 << endl; // Output the string "Hel"

    // Creating constructor of string -- 4th way --
    // string(other, pos) copies other from index pos to the end.
    // Indexes of "Hello": H=0, e=1, l=2, l=3, o=4 -> starting at 2 gives "llo".
    // (Careful: this is different from the 3rd way. With a quoted text the number is a COUNT,
    //  with a string object the number is a STARTING INDEX.)
    string s4(s, 2); // create a string from s starting at index 2 (i.e. skip the first 2 characters)
    cout << s4 << endl; // Output the string "llo"

    // Creating constructor of string -- 5th way
    // Create a string of size 5 with all characters as 'a'
    string s5(5, 'a'); // string(count, ch): 5 copies of the character 'a'
    cout << s5 << endl; // Output the string "aaaaa"


    return 0; // Indicate that the program ended successfully
} // end of main
