/*

In this tutorial, we will learn about vector input.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // The vector input is the same as the array input

    // First way to input the vector
    // It is not necessary to declare the size of the vector
    vector<int> v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x); 
        // push_back() function is used to add elements to the vector
        // by increasing the size and adding the elements at the end
    }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;

    // Second way to input the vector
    // declare an array of size n
    vector<int> v2(n); // vector of size n with all elements initialized to 0
    for(int i=0; i<n; i++){
        cin >> v2[i];
    }

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;


    return  0;
}