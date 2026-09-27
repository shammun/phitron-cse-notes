/*

Take a sentence S as input and then take another string word X as input. Then count how many times the word X
appeared in the sentence. The words in the sentence are separated by spaces.

Input:
Sanju Samson shamanta samson jessica Bhatta Asif John takla john abraham john baby Shark tank
john

Output:
2

*/

#include<iostream> // Include the input/output stream library for using cin, cout and getline
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() { // Program execution starts here
    // The sentence comes first. getline reads the whole line, spaces included.
    // (No cin.ignore() is needed because nothing was read with cin >> before it.)
    string words; // holds the whole sentence
    getline(cin, words); // read everything up to the Enter key

    // Then the word to look for, on the next line. cin >> reads one word.
    string name; // the word X we are counting
    cin >> name; // read it

    string word; // will hold one word of the sentence at a time

    // A stringstream reads the sentence one word at a time with >>, the same
    // way cin reads words from the keyboard, skipping the spaces between them.
    stringstream ss3(words); // build a stream whose "input" is the sentence text
    int count = 0; // how many matches found so far
    // Each pass pulls the next word into "word"; ss3 >> word is false once no words are left
    while(ss3 >> word){ // stops when no words are left
        // == compares whole words, letter by letter and case-sensitively:
        // "john" matches only "john", not "John" or "johnny"
        if(word == name){
            count++; // one more match
        }
    }
    // In the sample, "john" appears twice in lowercase ("John" does not count) -> prints 2
    cout << count << endl; // print the answer and a newline

    return 0; // Indicate that the program ended successfully
}
