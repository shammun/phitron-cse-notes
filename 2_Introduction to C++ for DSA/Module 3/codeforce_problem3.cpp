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

// Idea: compare the first element with the last, the second with the
// second-last, and so on. If every pair matches, the array is a palindrome.

int main(){
    int n; // number of elements
    cin >> n; // read N

    // Variable-length array: its size comes from input at run time. g++ allows this,
    // though standard C++ prefers vector<int> a(n). N <= 10^5 ints = 400 KB, fine on the stack.
    int a[n];

    // Read the N numbers; pass i fills box a[i], i runs 0..n-1.
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // Assume it is a palindrome until a mismatch proves otherwise
    // bool holds only true or false.
    bool is_palindrome = true;

    // Two pointers: i walks in from the left, n-i-1 walks in from the right.
    // Only the first half needs checking - each step compares one pair.
    // With 1 3 2 3 1: a[0]=a[4] (1,1), a[1]=a[3] (3,3), the middle 2 has no partner.
    // n/2 is integer division: 5/2 = 2, so i takes 0 and 1 only. For 1 2 3 4 (n=4):
    // i=0 compares a[0]=1 with a[3]=4 -> mismatch -> NO.
    for(int i=0; i<n/2; i++){
        if(a[i] != a[n-i-1]){ // one mismatched pair is enough to say NO (!= means "not equal")
            is_palindrome = false; // remember the answer is NO
            break; // no need to look further (break leaves the for loop immediately)
        }
    }

    // Print the verdict; endl ends the line.
    if(is_palindrome){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }

    return 0; // program finished normally
}