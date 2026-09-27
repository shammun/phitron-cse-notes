// Topic: iterators - a "pointer-like" object that marks a position inside a string
// (or vector, list...). s.begin() marks the first character, s.end() marks the
// position JUST AFTER the last character. *it gives the character at position it,
// and it++ moves to the next position. So [begin, end) covers the whole string.
//   "Hello, World!"   positions 0..12, begin() -> 'H', end()-1 -> '!', end() -> past '!'

#include<iostream> // Include the input/output stream library for using cout
#include<string.h>  // C-style string functions (strlen, strcpy...); not actually used in this file
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() { // program starts here
    string s = "Hello, World!"; // a C++ string with 13 characters (indexes 0..12)
    cout << s << endl;          // print the whole string

    // Printing all the characters of the string without using iterators.
    // i walks 0 .. s.size()-1; s[i] is the character at index i.
    // (s.size() is unsigned; comparing it with int i gives a compiler warning but works here.)
    for(int i=0; i<s.size(); i++){
        cout << s[i] << " "; // prints: H e l l o ,   W o r l d !  (no endl, so the next output continues on this line)
    }

    // Using iterators to access elements of the string
    cout << *s.begin() << endl; // s.begin() is an iterator to the first element of the string (like its address)
    // and so  we use * to get the value of the first element of the string ('H')
    // BUG: s.end() does NOT point to the last element - it points one step PAST it,
    // where there is no character of the string. Dereferencing it (*s.end()) is
    // undefined behavior: here it happened to print the hidden '\0' (an invisible
    // character), but it could print anything or crash. Never write *s.end().
    // Fix: to get the last character use *(s.end()-1), s.back() or s[s.size()-1].
    cout << *s.end() << endl; // s.end() is the position just after the last element of the string
    // and so  we use * to get the value of the element after the last element of the string
    cout << *(s.end()-1) << endl; // s.end()-1 is an iterator to the last element of the string
    // and so  we use * to get the value of the last element of the string ('!')

    // Using iterator to print all the elements of the string.
    // string::iterator is the full type name of a string's iterator.
    // it starts at begin(), prints *it, moves with it++, and stops when it reaches end().
    for(string::iterator it = s.begin(); it!=s.end(); it++){
        cout << *it << endl; // one character per line
    }

    // After C++11, we can use auto keyword to simplify the iterator declaration.
    // auto = "compiler, work out the type from the value on the right" (here string::iterator).
    for(auto it=s.begin(); it!=s.end(); it++){
        cout << *it << endl; // same output as the loop above
    }


    return 0; // Indicate that the program ended successfully
}
