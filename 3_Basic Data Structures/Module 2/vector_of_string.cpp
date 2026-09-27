/*

In this tutorial, we will learn about vector of string.

A vector can hold any type: vector<string> is a resizable list of words.
Two ways to read strings:
  cin >> s        reads ONE word: it stops at the first space or newline.
  getline(cin, s) reads a WHOLE line, spaces included, up to the newline.
Mixing them has a trap: after cin >> n2, the newline the user typed after the
number is still waiting in the input. getline would read that empty rest of
the line immediately. cin.ignore() throws away one character (that newline)
first, so getline starts on the next real line.

*/

#include <iostream>  // cin, cout, getline
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
#include <string>    // string and getline
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    // We can create a vector of string also and also of any data type

    // A string vector with values initialized
    vector<string> v = {"Rahim", "Karim", "Sohan", "Mohan", "Lipon", "Sakib"}; // 6 names


    // A string vector without values initialized
    // A string vector with the size declared only
    // We will take the size of the vector from the user and then input the elements
    int n; // how many names
    cin >> n; // read n
    vector<string> v2(n); // vector of size n with all elements initialized to empty string
    // Read n single-word names into the existing slots.
    for(int i=0; i<n; i++){
        cin >> v2[i]; // one word per slot
    }

    // Print them with an index loop.
    for(int i=0; i<n; i++){
        cout << v2[i] << " "; // name + space
    }
    cout << endl; // end the line

    // Another way to print the vector
    // Range-for: s takes a copy of each string in v2. (const string& s would
    // avoid the copy, which matters for long strings.)
    for(string s: v2){
        cout << s << " "; // name + space
    }
    cout << endl; // end the line

    // Now, we will learn about inserting strings with spaces into the vector
    // We will use getline() function to input the strings with spaces

    // This first ignore() is not really needed: the next cin >> skips leading
    // newlines by itself. It eats the newline left after the last name.
    cin.ignore(); // ignore the newline character
    int n2; // how many full-line names follow
    cin >> n2; // read n2
    cin.ignore(); // ignore the newline character (this one IS needed before getline)
    // BUG: sized with n instead of n2. Fix: vector<string> v3(n2);
    vector<string> v3(n);

    // Read n2 whole lines.
    // BUG: getline stores each line into v[i] (the first vector of 6 names), not
    // v3[i], so v3 stays full of empty strings and the loop below prints n empty
    // lines. With n2 > 6 it would also write past the end of v. Fix: getline(cin, v3[i]);
    for(int i=0; i<n2; i++){
        getline(cin, v[i]); // reads the whole line, spaces included (into v[i], see BUG)
    }

    // Print v3, one string per line.
    for(string s: v3){
        cout << s << endl; // prints an empty line for each empty string
    }

    return 0; // program finished successfully
}

/*

Input:
5
Rahim
Karim
Sohan
Mohan
Lipon
5
Sakib Khan
Rakib Hasan
Rafi Khan
Shakib Al Hasan
Tamim Iqbal

Output:
Rahim Karim Sohan Mohan Lipon
Rahim Karim Sohan Mohan Lipon
Sakib Khan
Rakib Hasan
Rafi Khan
Shakib Al Hasan
Tamim Iqbal

Note: the last five lines are the INTENDED output. Because of the BUGs above,
the program as written prints five empty lines there instead.
*/
