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
    string name;
    cin >> name;
    cin.ignore();
    
    string words;
    getline(cin, words);

    string word;
    
    stringstream ss3(words);
    int count = 0;
    while(ss3 >> word){
        if(word == name){
            count++;
        }
    }
    cout << count << endl;

    return 0; // Indicate that the program ended successfully
}