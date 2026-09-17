/*

Reversing

time limit per test: 1 second
memory limit per test: 64 megabytes

Given a number N and an array A of N numbers. Print the array in a reversed order.

Note:

*Don't use built-in-functions.

Input
First line contains a number N (1 ≤ N ≤ 103) number of elements.

Second line contains N numbers (0 ≤ Ai ≤ 109).

Output
Print the array in a reversed order.

Examples
Input
4
5 1 3 2
Output
2 3 1 5 

Input
5
1 2 3 4 5
Output
5 4 3 2 1 

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=n-1; i>=0; i--){
        cout << a[i] << " ";
    }
    
    return 0;    
}