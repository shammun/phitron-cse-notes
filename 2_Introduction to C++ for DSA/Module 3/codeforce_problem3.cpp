/*

Palindrome Array
time limit per test: 1 second
memory limit per test: 256 megabytes
Given a number N
 and an array A
 of N
 numbers. Determine if it's palindrome or not.

Note:

An array is called palindrome if it reads the same backward and forward, for example, arrays { 1 } and { 1,2,3,2,1 } are palindromes, while arrays { 1,12 } and { 4,7,5,4 } are not.

Input
First line contains a number N
 (1≤N≤105)
 number of elements.

Second line contains N
 numbers (1≤Ai≤109)
.

Output
Print "YES" (without quotes) if A is a palindrome array, otherwise, print "NO" (without quotes).

Examples

Input
5
1 3 2 3 1
Output
YES

Input
4
1 2 3 4
Output
NO


*/

#include <iostream> // Include the iostream library for input/output operations
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before cin, cout, etc.

int main(){
    int n;
    cin >> n;

    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    bool is_palindrome = true;

    for(int i=0; i<n/2; i++){
        if(a[i] != a[n-i-1]){
            is_palindrome = false;
            break;
        }
    }

    if(is_palindrome){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }

    return 0;
}