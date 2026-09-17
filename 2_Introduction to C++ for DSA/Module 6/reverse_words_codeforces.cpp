#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
#include <algorithm> // Include the algorithm library for sort function
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    /*
    while(ss >> word){
        reverse(word.begin(), word.end());
        cout << word << " ";
    }
    */
    // But Codeforces want space after the last word to be removed
    // So, we will first print the first word and then print the rest of the words with spaces
    ss >> word;
    cout << word;
    while(ss >> word){
        reverse(word.begin(), word.end());
        cout << " " << word;
    }

    return 0; // Indicate that the program ended successfully
}