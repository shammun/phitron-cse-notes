// Topic: stringstream - treat a string like cin, so >> can pull words out of it one by one.
// This program reads THREE lines of input: the first is split word by word by hand,
// the second with a while loop, and the third is split and its words counted.

#include<iostream> // Include the input/output stream library for using cin and cout
#include <string>   // Include the string library for std::string and getline
#include <sstream> // Include the stringstream library for string stream operations
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() { // program starts here
    string s; // the first input line
    getline(cin, s); // Take input from the user with spaces (reads the whole line)
    cout << "The string entered is: " << s << endl; // Output the entered string
    // Suppose s is "Hello I am a string"

    // stringstream is a class in C++ that allows us to read and write strings as if they were streams of characters.
    // We ca use it to print the string word by word
    stringstream ss(s); // Create a stringstream object 'ss' and initialize it with the string s
    string word; // each >> puts the next word here
    // ss >> word works exactly like cin >> word: skip spaces, read up to the next space.
    ss >> word; // Gives the first word "Hello" from ss and removes it from ss
    // Now, ss is "I am a string" (strictly: s is unchanged; ss just moved its reading position past "Hello")
    cout << "The first word is: " << word << endl; // Output the first word "Hello"
    ss >> word; // // Gives the first word from ss or "I" and removes it from ss
    cout << "The second word is: " << word << endl; // Output the second word or "I" of the string
    ss >> word; // Gives the first word from ss or "am" and removes it from ss
    cout << "The third word is: " << word << endl; // Output the third word or "am" of the string
    ss >> word; // Gives the first word from ss or "a" and removes it from ss
    // Note: this is really the FOURTH word; the printed label below says "third" by mistake.
    cout << "The third word is: " << word << endl; // Output the fourth word or "a" of the string
    // We can use this to print the string word by word

    // Normally, we do this using while loop.
    // ss2 >> word is true while a word was read and false once ss2 has no words left,
    // so one pass = one word, and the loop stops after the last word.
    string s2;
    getline(cin, s2); // Take input from the user with spaces (the second input line)
    stringstream ss2(s2); // a new stream over the second line
    while(ss2 >> word){
        cout << word << endl; // print each word on its own line
    }
    // Extra spaces do not matter: "  hi   there " gives just "hi" and "there".

    // Using this, we can also count the number of words
    string s3;
    getline(cin, s3); // Take input from the user with spaces (the third input line)
    stringstream ss3(s3); // a new stream over the third line
    int count = 0; // words seen so far
    while(ss3 >> word){
        count++;              // one more word
        cout << word << endl; // and print it
    }
    cout << "The number of words in the string is: " << count << endl; // "I am here" -> 3

    return 0; // Indicate that the program ended successfully
}
