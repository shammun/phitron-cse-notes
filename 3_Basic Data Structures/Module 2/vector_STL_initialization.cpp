/*
STL -- Standard Template Library
Vectors in C++ STL
We will learn the basics of STL vectors in this tutorial.
We will learn how to initialize a vector in C++.

A vector is like an array that remembers its own size and can grow or shrink.
vector<int> means "a vector whose elements are ints"; the type goes inside < >.
What this program actually prints: "Size: 0", "Size: 0", then 1..5, then 1..5
(see the BUG notes below).
*/
#include <iostream> // cout
#include <vector>   // vector
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    // Initializing a vector
    vector<int> v; // empty vector: no elements yet
    cout << "Size: " << v.size() << endl; // 0

    // Construct a vector of size n
    vector<int> v1(5); // 5 elements, all 0: {0, 0, 0, 0, 0}
    // BUG: this prints v.size() (the EMPTY vector), so it prints 0, not 5.
    // Fix: use v1.size().
    cout << "Size: " << v.size() << endl; // prints 0 (see BUG above)

    // Construct a vector of size n with all elements initialized to 10
    vector<int> v2(5, 10); // {10, 10, 10, 10, 10}
    // BUG: this loop walks v (size 0), so it prints nothing. Fix: use v2.size() and v2[i].
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl; // never runs (see BUG above)
    }

    // Construct a vector with elements of another vector
    vector<int> v3(v2); // {10, 10, 10, 10, 10}  -- a separate copy of v2

    // We can also create a vector by following the content of an array
    int a[5] = {1, 2, 3, 4, 5}; // a normal array
    // vector<int>(first, last) copies the range [first, last). An array name
    // like a acts as a pointer to its first element, so a .. a+5 is the whole array.
    vector<int> v4(a, a+5); // {1, 2, 3, 4, 5}, a copy of the array
    for(int i=0; i<v4.size(); i++){
        cout << v4[i] << endl; // prints 1 2 3 4 5, one per line
    }

    // Creating a vector
    // Initializer list: list the starting values inside { }.
    vector<int> v5 = {1, 2, 3, 4, 5};
    for(int i=0; i<v5.size(); i++){
        cout << v5[i] << endl; // prints 1 2 3 4 5, one per line
    }


    return 0; // program finished successfully
}
