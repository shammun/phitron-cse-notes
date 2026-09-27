/*

Palindrome
time limit per test: 1 second
memory limit per test: 256 megabytes
Given a string S. Determine whether S is Palindrome or not

Note: A string is said to be a palindrome if the reverse of the string is same as the string. For example, "abba" is palindrome, but "abbc" is not palindrome.

Input
Only one line contains a string S (1 ≤ |S| ≤ 1000) where |S| is the length of the string and it consists of lowercase letters only.

Output
Print "YES" if the string is palindrome, otherwise print "NO".

Examples:

Input
abba
Output
YES

Input
icpcassiut
Output
NO

Input
mam
Output
YES

*/

#include <iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string>   // Gives us std::string, a text type that knows its own length
#include <algorithm> // Include the algorithm library for the reverse function
using namespace std; // Lets us write cin, cout, string, reverse instead of std::cin, std::cout, ...

int main(){
    string s; // the word to test
    cin >> s; // read it (lowercase letters, no spaces)

    // Make a copy (= copies a whole string in C++) and turn the copy around.
    // reverse(begin, end) reverses everything between the two iterators,
    // here the whole string. s itself stays as it was.
    // An iterator is a "position marker" in a container: begin() is the first
    // character, end() is one step PAST the last character.
    string rev_s = s; // rev_s is an independent copy, e.g. "abc"
    reverse(rev_s.begin(), rev_s.end()); // now rev_s is "cba"; s is still "abc"

    // A palindrome reads the same backwards, so it equals its own reverse.
    // == compares two strings letter by letter.
    if (s == rev_s){
        cout << "YES" << endl; // endl = newline
    } else {
        cout << "NO" << endl;
    }

    return 0; // Indicate that the program ended successfully
} // end of main
