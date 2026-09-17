/*

In this tutorial, we will learn about vector element access.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,3,25};

    // Accessing the elements of the vector using the [] operator
    // O(1) operation
    cout << v[0] << endl; // 1
    cout << v[1] << endl; // 2
    cout << v[2] << endl; // 3
    cout << v[3] << endl; // 4

    // Accessing the elements of the vector using the at() function
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
    cout << v.back() << endl; // 25

    // Another way to access the last element of the vector
    cout << v[v.size()-1] << endl; // 25

    return 0;
}