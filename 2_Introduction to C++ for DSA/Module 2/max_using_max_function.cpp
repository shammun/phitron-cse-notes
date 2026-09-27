/*

E. Max
https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/E

Read N (1 <= N <= 1000) and then N numbers (each 0 to 10^9), and print the
largest of them.
The practice sheet asks for this one to be solved with the max() function.
(max.cpp solves the same problem with an if instead.)

Example
Input
5
1 8 5 7 5
Output
8

*/

#include <iostream>  // cin and cout
#include <algorithm> // max() (min, max and swap live here - see Module 1)
using namespace std; // write cin/cout/max instead of std::cin/...

int main(){ // the program starts running here
    int n; // how many numbers follow
    cin >> n; // cin skips spaces/newlines and reads one whole number

    // Make exactly n boxes on the heap once n is known.
    // new int[n] returns the address of the first box; the pointer a stores it,
    // and a[i] reaches box i just like a normal array.
    int *a = new int[n];
    for(int i=0; i<n; i++){ // i = 0..n-1, one number per pass
        cin >> a[i]; // read the i-th number into box i
    }

    // Start with the first number as the best so far. (Not 0: that would only
    // work because the numbers here are never negative.)
    int ans = a[0];

    // max(x, y) returns the bigger of the two, so each step keeps the larger
    // of "best so far" and the next number. With 1 8 5 7 5:
    // ans = 1 -> max(1,8)=8 -> max(8,5)=8 -> max(8,7)=8 -> max(8,5)=8
    // i starts at 1 because box 0 is already in ans.
    for(int i=1; i<n; i++){
        ans = max(ans, a[i]); // both arguments must be the same type (here int and int)
    }

    cout << ans << endl; // print the answer; endl = newline

    delete[] a; // give the heap array back (delete[] with brackets, because it is an array)

    return 0; // the program ended fine
}
