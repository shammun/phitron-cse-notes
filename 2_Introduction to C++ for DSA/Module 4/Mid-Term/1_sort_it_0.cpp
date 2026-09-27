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

// Idea of this solution: read the array, sort it ascending and print it,
// then sort it again with a "bigger first" rule (descending) and print it again.
// The values fit in int: -10^9..10^9 is inside int's range (about -2.1*10^9..2.1*10^9).

#include <iostream>  // cin and cout (reading input and printing output)
#include <algorithm> // sort() and greater<int>() (greater comes with <functional>, which <algorithm> pulls in here)
using namespace std; // write cin/cout/sort instead of std::cin/std::cout/std::sort

int main(){ // program starts here
    int n;     // size of the array
    cin >> n;  // read N
    // int a[n] is a "variable length array": its size is known only at run time.
    // Standard C++ does not officially allow it, but g++ accepts it as an extension.
    int a[n]; // a plain array is enough here: everything happens inside main

    // Read the n numbers; pass i reads the number that goes into a[i].
    for(int i=0; i<n; i++){
        cin >> a[i]; // cin >> skips spaces/newlines and reads one whole number
    }

    // ascending order: sort(first, one-past-last) sorts the whole array small to big.
    // a is the address of a[0]; a+n is the address just after the last element.
    // {2,4,6,1,3} -> {1,2,3,4,6}
    sort(a, a+n);

    // Print the ascending array, each value followed by a space
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl; // new line after the first answer line

    // descending order: the third argument says how to compare.
    // greater<int>() means "the bigger one goes first", so the order flips.
    // {1,2,3,4,6} -> {6,4,3,2,1}
    sort(a, a+n, greater<int>());
    // Print the descending array
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl; // new line after the second answer line

    return 0; // program ended normally
}