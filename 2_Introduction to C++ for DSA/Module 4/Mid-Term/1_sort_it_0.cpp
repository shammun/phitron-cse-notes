/*

Problem Statement

You will be given an array A of size N. Initially, you need to print the array by sorting it in ascending order. Afterward, you need to print the array sorted in descending order.

Input Format

First line will contain N.
Next line will contain the array A.
Constraints

1 <= N <= 10^5
-10^9 <= A[i] <= 10^9 Where 0 <= i < N
Output Format

Print two lines. First line will contain the array sorted in ascending order. Next line will contain the array sorted in descending order.
Sample Input 0

5
2 4 6 1 3
Sample Output 0

1 2 3 4 6
6 4 3 2 1

*/

#include <iostream>  // cin and cout
#include <algorithm> // sort() and greater<int>()
using namespace std; // write cin/cout/sort instead of std::cin/...

int main(){
    int n;
    cin >> n;
    int a[n]; // a plain array is enough here: everything happens inside main

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // ascending order: sort(first, one-past-last) sorts the whole array small to big
    sort(a, a+n);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    // descending order: the third argument says how to compare.
    // greater<int>() means "the bigger one goes first", so the order flips.
    sort(a, a+n, greater<int>());
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}