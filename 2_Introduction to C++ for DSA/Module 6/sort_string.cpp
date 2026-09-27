/*
Sorting the characters of a string.

sort(first, last) arranges everything in [first, last) in increasing order.
For characters "increasing" means by ASCII code, so 'a' < 'b' < ... and all
capital letters (65..90) come before all small letters (97..122).
Example: "banana" -> "aaabnn".
*/

#include<iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string>   // Gives us std::string
#include <sstream> // stringstream library; not actually used in this file
#include <algorithm> // Include the algorithm library for the sort function
using namespace std; // Lets us write cin, cout, string, sort instead of std::cin, ...

int main() {
    string s; // the word to sort
    cin >> s; // Take ONE word from the user: cin >> stops at the first space
    cout << s << endl; // Output the entered string, endl = newline
    // s.begin() marks the first character, s.end() one past the last: the whole string.
    sort(s.begin(), s.end()); // Sort the string, in place (s itself changes)
    cout << "After sorting using sort function: " << s << endl; // Output the sorted string

    return 0; // Indicate that the program ended successfully
} // end of main
