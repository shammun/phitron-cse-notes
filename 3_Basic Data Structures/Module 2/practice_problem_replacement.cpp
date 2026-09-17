/*

Replacement
time limit per test: 1 second
memory limit per test: 256 megabytes

Given a number N and an array A of N numbers. Print the array after doing the following 
operations:

- Replace every positive number by 1.
- Replace every negative number by 2.

Input
First line contains a number N (2 ≤ N ≤ 1000) number of elements.

Second line contains N numbers (-10^5  ≤  Ai  ≤  10^5).

Output
Print the array after the replacement and it's values separated by space.

Example
Input
5
1 -2 0 3 4
Output
1 2 0 1 1 

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

    for(int i=0; i<n; i++){
        if(a[i] > 0){
            a[i] = 1;
        } else if(a[i] < 0){
            a[i] = 2 ;
        }
    }

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}