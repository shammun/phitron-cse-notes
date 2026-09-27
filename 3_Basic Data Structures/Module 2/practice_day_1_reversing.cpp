/*

Reversing

time limit per test: 1 second
memory limit per test: 64 megabytes

Given a number N and an array A of N numbers. Print the array in a reversed order.

Note:

*Don't use built-in-functions.

Input
First line contains a number N (1 ≤ N ≤ 103) number of elements.
(103 here means 10^3 = 1000; the superscript was lost when copying.)

Second line contains N numbers (0 ≤ Ai ≤ 109).
(109 here means 10^9, which still fits in an int, whose limit is about 2.1 * 10^9.)

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

#include <iostream>  // cin and cout
#include <vector>    // vector: an array that knows its own size and can grow
#include <algorithm> // sort, reverse, find, ... (not needed here: built-ins are not allowed)
#include <string>    // the string type (not used in this file)
using namespace std; // so we can write vector / cin / cout without the std:: prefix

/*
 * Idea: we do not have to change the vector at all. Reading it from the last
 * index down to index 0 already prints it in reversed order.
 * With 4 and 5 1 3 2 the loop visits a[3], a[2], a[1], a[0] -> 2 3 1 5.
 * Time O(n), extra space O(n) for the vector.
 */
int main() { // the program starts running here
    int n; // how many numbers will follow
    cin >> n; // read N

    // vector<int> a(n) makes a vector that already has n slots (all 0),
    // so we can fill it with a[i] just like an array.
    vector<int> a(n);
    // Read the n numbers: pass i stores the i-th number in a[i] (i = 0 .. n-1).
    // cin >> skips spaces and newlines, so the numbers can be on one line.
    for(int i=0; i<n; i++){
        cin >> a[i]; // read one number into slot i
    }

    // Walk backwards: start at the last index n-1 and stop after index 0.
    // i-- lowers i by 1 each pass; the loop ends when i becomes -1.
    for(int i=n-1; i>=0; i--){
        cout << a[i] << " "; // print this element followed by a space
    }

    return 0; // program finished successfully
}
