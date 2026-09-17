#include<iostream> // Include the input/output stream library for using cout
#include<string.h>  // Include C-style string manipulation functions (used in the commented-out section)
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    string s = "Hello, World!";
    cout << s << endl;

    // Printing all the characters of the string without using iterators
    for(int i=0; i<s.size(); i++){
        cout << s[i] << " ";
    }

    // Using iterators to access elements of the string
    cout << *s.begin() << endl; // s.begin() outputs the address of the first element of the string
    // and so  we use * to get the value of the first element of the string
    cout << *s.end() << endl; // s.end() output the address of the last element of the string
    // and so  we use * to get the value of the element after the last element of the string
    cout << *(s.end()-1) << endl; // s.end()-1 outputs the address of the last element of the string
    // and so  we use * to get the value of the last element of the string

    // Using iterator to print all the elements of the string
    for(string::iterator it = s.begin(); it!=s.end(); it++){
        cout << *it << endl;
    } 

    // After C++11, we can use auto keyword to simplify the iterator declaration
    for(auto it=s.begin(); it!=s.end(); it++){
        cout << *it << endl;
    }


    return 0; // Indicate that the program ended successfully
}