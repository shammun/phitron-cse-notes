/*
Range-based for loop.

for(char c: s) means "for each character c in the string s, in order".
It is a shorter way to visit every element when you do not need the index i.
Example: input "abc" prints "a b c ".
*/

#include<iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string>   // Gives us std::string
#include <sstream> // stringstream library; not actually used in this file
using namespace std; // Lets us write cin, cout, string instead of std::cin, std::cout, std::string

int main() {
    string s; // the text to walk over
    cin >> s; // Take ONE word from the user: cin >> stops at the first space, so "ab cd" gives only "ab" (use getline(cin, s) to keep spaces)
    // The same job with a normal index loop (commented out, kept for comparison):
    /*
    for(int i = 0; i < s.size(); i++){
        cout << s[i] << " ";
    }
    */
    // Shortcut for the above code
    // c is a COPY of each character in turn: first s[0], then s[1], ... until the end of s.
    for(char c: s){
        cout << c << " "; // print the character followed by a space
    } // end of the range-based for loop

    return 0; // Indicate that the program ended successfully
} // end of main
