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

#include<iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string>   // Gives us std::string and getline
#include <sstream> // Include the stringstream library for string stream operations
#include <algorithm> // Include the algorithm library for the reverse function
using namespace std; // Lets us write cin, cout, string, reverse instead of std::cin, ...

int main() {
    string s; // the whole input line
    getline(cin, s); // read the whole line, spaces included (cin >> s would stop at the first space)
    // A stringstream lets us read words out of a string with >>, exactly as
    // cin reads words from the keyboard: each ss >> word takes the next word
    // and skips the spaces.
    stringstream ss(s); // ss now holds the text of s, ready to be read word by word
    string word; // holds one word at a time
    // First version (commented out): prints a space after EVERY word, including the last one.
    /*
    while(ss >> word){
        reverse(word.begin(), word.end());
        cout << word << " ";
    }
    */
    // But Codeforces want space after the last word to be removed
    // So, we will first print the first word and then print the rest of the words with spaces
    // Trace for "I love you": print "I", then " evol", then " uoy" -> "I evol uoy".
    ss >> word; // take the first word
    reverse(word.begin(), word.end()); // the first word must be reversed too (begin()..end() = whole word)
    cout << word; // print it with no space
    // ss >> word is true while a word was read, false once the stream is empty.
    while(ss >> word){ // stops when the stringstream runs out of words
        reverse(word.begin(), word.end()); // turn this word around in place
        cout << " " << word;               // the space goes BEFORE each later word
    } // end of the while loop

    return 0; // Indicate that the program ended successfully
} // end of main
