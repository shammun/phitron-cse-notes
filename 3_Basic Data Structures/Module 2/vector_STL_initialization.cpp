/*
STL -- Standard Template Library
Vectors in C++ STL
We will learn the basics of STL vectors in this tutorial. 
We will learn how to initialize a vector in C++.
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initializing a vector
    vector<int> v;
    cout << "Size: " << v.size() << endl; // 0

    // Construct a vector of size n
    vector<int> v1(5);
    cout << "Size: " << v.size() << endl; // prints 5

    // Construct a vector of size n with all elements initialized to 10
    vector<int> v2(5, 10); // {10, 10, 10, 10, 10}
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }

    // Construct a vector with elements of another vector
    vector<int> v3(v2); // {10, 10, 10, 10, 10}

    // We can also create a vector by following the content of an array
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> v4(a, a+5); // {10, 10, 10, 10, 10}
    for(int i=0; i<v4.size(); i++){
        cout << v4[i] << endl;
    }

    // Creating a vector
    vector<int> v5 = {1, 2, 3, 4, 5};
    for(int i=0; i<v5.size(); i++){
        cout << v5[i] << endl;
    }


    return 0;
}