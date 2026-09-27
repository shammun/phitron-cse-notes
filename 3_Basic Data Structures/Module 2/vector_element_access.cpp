/*

In this tutorial, we will learn about vector element access.

Four ways to read an element:
  v[i]      -> fast, no checking: a bad index is undefined behaviour
  v.at(i)   -> same result, but a bad index throws an out_of_range error
               instead of silently reading garbage (a tiny bit slower)
  v.front() -> the first element (same as v[0])
  v.back()  -> the last element  (same as v[v.size()-1])
All of them are O(1): a vector keeps its elements side by side in memory, so
the address of element i is computed directly.

*/

#include <iostream>  // cout
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    vector<int> v = {1,2,3,4,5,3,25}; // 7 elements: indexes 0..6

    // Accessing the elements of the vector using the [] operator
    // O(1) operation
    cout << v[0] << endl; // 1
    cout << v[1] << endl; // 2
    cout << v[2] << endl; // 3
    cout << v[3] << endl; // 4

    // Accessing the elements of the vector using the at() function
    // (v.at(10) here would stop the program with an out_of_range error.)
    cout << v.at(0) << endl; // 1
    cout << v.at(1) << endl; // 2
    cout << v.at(2) << endl; // 3
    cout << v.at(3) << endl; // 4

    // Accessing the first element of the vector using the front() function
    // O(1) operation
    cout << v.front() << endl; // 1

    // Anothr way to access the first element of the vector
    cout << v[0] << endl; // 1

    // Accessing the last element of the vector using the back() function
    // O(1) operation
    // (front() and back() on an EMPTY vector are undefined behaviour: check empty() first.)
    cout << v.back() << endl; // 25

    // Another way to access the last element of the vector
    // size() is 7, so the last index is 7 - 1 = 6.
    cout << v[v.size()-1] << endl; // 25

    return 0; // program finished successfully
}
