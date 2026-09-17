#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    string s;
    getline(cin, s); // Take input from the user with spaces
    cout << "The string entered is: " << s << endl; // Output the entered string
    // Suppose s is "Hello I am a string"

    // stringstream is a class in C++ that allows us to read and write strings as if they were streams of characters.
    // We ca use it to print the string word by word
    stringstream ss(s); // Create a stringstream object 'ss' and initialize it with the string s
    string word;
    ss >> word; // Gives the first word "Hello" from ss and removes it from ss
    // Now, ss is "I am a string"
    cout << "The first word is: " << word << endl; // Output the first word "Hello"
    ss >> word; // // Gives the first word from ss or "I" and removes it from ss
    cout << "The second word is: " << word << endl; // Output the second word or "I" of the string
    ss >> word; // Gives the first word from ss or "am" and removes it from ss
    cout << "The third word is: " << word << endl; // Output the third word or "am" of the string
    ss >> word; // Gives the first word from ss or "a" and removes it from ss
    cout << "The third word is: " << word << endl; // Output the third word or "a" of the string      
    // We can use this to print the string word by word

    // Normally, we do this using while loop
    string s2;
    getline(cin, s2); // Take input from the user with spaces
    stringstream ss2(s2);
    while(ss2 >> word){
        cout << word << endl;
    }

    // Using this, we can also count the number of words
    string s3;
    getline(cin, s3); // Take input from the user with spaces
    stringstream ss3(s3);
    int count = 0;
    while(ss3 >> word){
        count++;
        cout << word << endl;
    }
    cout << "The number of words in the string is: " << count << endl;

    return 0; // Indicate that the program ended successfully
}