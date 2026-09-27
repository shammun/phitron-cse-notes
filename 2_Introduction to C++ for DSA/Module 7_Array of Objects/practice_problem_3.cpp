/*

Take a sentence S as input and then take another string word X as input. Then count how many times the word X 
appeared in the sentence. The words in the sentence are separated by spaces.

Input:
Sanju Samson shamanta samson jessica Bhatta Asif John takla john abraham john baby Shark tank 
john

Output:
2

*/

#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    // The sentence comes first. getline reads the whole line, spaces included.
    string words;
    getline(cin, words);

    // Then the word to look for, on the next line. cin >> reads one word.
    string name;
    cin >> name;

    string word;

    // A stringstream reads the sentence one word at a time with >>, the same
    // way cin reads words from the keyboard, skipping the spaces between them.
    stringstream ss3(words);
    int count = 0;
    while(ss3 >> word){ // stops when no words are left
        // == compares whole words, letter by letter and case-sensitively:
        // "john" matches only "john", not "John" or "johnny"
        if(word == name){
            count++;
        }
    }
    cout << count << endl;

    return 0; // Indicate that the program ended successfully
}