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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    vector<int> c;
    for(int i=-0; i<n; i++){
        c.push_back(b[i]);
    }
    for(int i=0; i<n; i++){
        c.push_back(a[i]);
    }

    for(int i=0; i<c.size(); i++){
        cout << c[i] << " ";
    }

    return 0;
}