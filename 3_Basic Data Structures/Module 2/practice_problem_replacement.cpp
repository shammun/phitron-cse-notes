/*

Replacement
time limit per test: 1 second
memory limit per test: 256 megabytes

Given a number N and an array A of N numbers. Print the array after doing the following
operations:

- Replace every positive number by 1.
- Replace every negative number by 2.

Input
First line contains a number N (2 ≤ N ≤ 1000) number of elements.

Second line contains N numbers (-10^5  ≤  Ai  ≤  10^5).

Output
Print the array after the replacement and it's values separated by space.

Example
Input
5
1 -2 0 3 4
Output
1 2 0 1 1

*/

#include <iostream>  // cin and cout
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    int n; // number of elements
    cin >> n; // read N
    vector<int> a(n); // n slots, all 0 for now
    // Read the array: pass i fills a[i]. cin >> reads negative numbers like -2 fine.
    for(int i=0; i<n; i++){
        cin >> a[i]; // read one number
    }

    // Change the vector in place. Zero is neither positive nor negative,
    // so it matches neither branch and stays 0.
    // 1 -2 0 3 4 becomes 1 2 0 1 1.
    for(int i=0; i<n; i++){ // look at every element once
        if(a[i] > 0){ // positive?
            a[i] = 1;           // positive -> 1
        } else if(a[i] < 0){ // otherwise, negative?
            a[i] = 2 ;          // negative -> 2
        } // (no else: 0 is left alone)
    }

    // Print the changed array, space separated.
    for(int i=0; i<n; i++){
        cout << a[i] << " "; // print one element and a space
    }

    return 0; // program finished successfully
}
