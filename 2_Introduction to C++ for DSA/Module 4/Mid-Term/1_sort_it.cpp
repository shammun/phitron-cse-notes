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

#include <iostream>
#include <algorithm>
using namespace std;

int* sort_it(int n){
    int* a = new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    return a;
}

int main(){

    int n;
    cin >> n;
    int* sorted_array = sort_it(n);

    // Print the sorted array in ascending order
    for(int i=0; i<n; i++){
        cout << sorted_array[i] << " ";
    }
    cout << endl;

    // Print the sorted array in descending order
    for(int i=n-1; i>=0; i--){
        cout << sorted_array[i] << " ";
    }
    cout << endl;

    delete[] sorted_array;

    return 0;
}