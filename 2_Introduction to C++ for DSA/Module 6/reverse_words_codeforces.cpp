/*

Q. Reverse Words
https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/Q

A line of words separated by single spaces is given. Reverse the letters of
every word, but keep the words in their original order, and print the line.

Example
Input
I love you
Output
I evol uoy

*/

#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
#include <algorithm> // Include the algorithm library for sort function
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    string s;
    getline(cin, s); // read the whole line, spaces included
    // A stringstream lets us read words out of a string with >>, exactly as
    // cin reads words from the keyboard: each ss >> word takes the next word
    // and skips the spaces.
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
    reverse(word.begin(), word.end()); // the first word must be reversed too
    cout << word;
    while(ss >> word){ // stops when the stringstream runs out of words
        reverse(word.begin(), word.end()); // turn this word around in place
        cout << " " << word;               // the space goes BEFORE each later word
    }

    return 0; // Indicate that the program ended successfully
}