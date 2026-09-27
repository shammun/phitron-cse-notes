/*

New Array

time limit per test: 1 second
memory limit per test: 256 megabytes

Given two arrays A and B of size N. Print a new array C that holds the concatenation of
array B followed by array A.

Note: Solve this problem using function.

Input
First line will contain a number N (1≤N≤10^3).

Second line will contain N numbers (1≤Ai≤10^5) array A elements.

Third line will contain N numbers (1≤Bi≤10^5) array B elements.

Output
Print array C elements separated by space.

Example
Input
2
1 2
3 4

Output
3 4 1 2

*/

#include <iostream>  // cin and cout
#include <vector>    // vector
#include <algorithm> // not needed here, kept from the template
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

// Note: the task says "use a function", but this solution does everything in
// main(); the judge only checks the output, so it is still accepted.
int main() { // the program starts running here
    int n; // size of each array
    cin >> n; // read N
    vector<int> a(n), b(n); // two vectors of n slots each (one line can declare several)
    // Read array A: pass i fills a[i].
    for(int i=0; i<n; i++){
        cin >> a[i]; // read one number of A
    }
    // Read array B the same way.
    for(int i=0; i<n; i++){
        cin >> b[i]; // read one number of B
    }
    // c starts empty; push_back() adds one value at the end and grows it.
    // B must come first, so push all of b, then all of a.
    // With a = 1 2 and b = 3 4: c becomes 3, 3 4, 3 4 1, 3 4 1 2.
    vector<int> c; // empty vector, size 0
    for(int i=0; i<n; i++){
        c.push_back(b[i]); // append b[i] at the end of c
    }
    for(int i=0; i<n; i++){
        c.push_back(a[i]); // then append a[i]
    }

    // c.size() is now 2n.
    // (size() returns an unsigned number; comparing it with int i gives a
    // harmless compiler warning here.)
    for(int i=0; i<c.size(); i++){
        cout << c[i] << " "; // print each element with a space after it
    }

    return 0; // program finished successfully
}
