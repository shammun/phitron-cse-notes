/*

In this tutorial, we will learn about vector input.

Two ways to read n numbers into a vector:
  1. Start empty and push_back() each number as it is read.
  2. Create the vector with n slots first, then read into v2[i] like an array.
Example input:  3 / 1 2 3 / 4 5 6

*/

#include <iostream>  // cin and cout
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    // The vector input is the same as the array input

    // First way to input the vector
    // It is not necessary to declare the size of the vector
    vector<int> v; // empty vector: size 0
    int n; // how many numbers to read
    cin >> n; // read n
    // Each pass reads one number into a temporary x and appends it to v.
    for(int i=0; i<n; i++){
        int x; // temporary holder for one input number
        cin >> x; // read it
        v.push_back(x);
        // push_back() function is used to add elements to the vector
        // by increasing the size and adding the elements at the end
    }

    // Print v. v.size() is n now.
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " "; // print element i and a space
    }

    cout << endl; // finish the line

    // Second way to input the vector
    // declare an array of size n
    vector<int> v2(n); // vector of size n with all elements initialized to 0
    // Fill the existing slots directly (no push_back: the slots already exist).
    for(int i=0; i<n; i++){
        cin >> v2[i]; // read into slot i
    }

    // BUG: this loop prints v (the FIRST vector) again, not v2, so with the
    // example input it prints "1 2 3" instead of "4 5 6". Fix: use v2.size()
    // and v2[i] in this loop.
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " "; // prints v[i] (see BUG above)
    }

    cout << endl; // finish the line


    return  0; // program finished successfully
}
