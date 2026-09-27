/*

F. Reversing
https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/F

Read N and then N numbers, and print them in reverse order.
The practice sheet asks for this one to be solved with swap(): turn the
array itself around, then print it from the front.
(reversing.cpp solves the same problem by printing backwards instead.)

Example
Input
4
5 1 3 2
Output
2 3 1 5

*/

#include <iostream>  // cin and cout
#include <algorithm> // swap() (min, max and swap live here - see Module 1)
using namespace std; // write cin/cout/swap instead of std::cin/...

int main(){ // the program starts running here
    int n; // how many numbers
    cin >> n; // cin skips spaces/newlines and reads one whole number

    // The size is known only after reading n, so the array is made on the
    // heap with new, the way this module shows.
    // new int[n] returns the first box's address; a[i] reaches box i.
    int *a = new int[n];
    for(int i=0; i<n; i++){ // i = 0..n-1
        cin >> a[i]; // read the i-th number into box i
    }

    // Two ends walk towards the middle: the first box swaps with the last,
    // the second with the second-last, and so on.
    // Box i pairs with box n-1-i. Stop at the middle (i < n/2), otherwise
    // every pair would be swapped twice and the array would end up unchanged.
    // With 5 1 3 2: swap a[0],a[3] -> 2 1 3 5, swap a[1],a[2] -> 2 3 1 5.
    // (For odd n, n/2 rounds down, so the middle box is left alone - it is already in place.)
    for(int i=0; i<n/2; i++){
        swap(a[i], a[n-1-i]); // swap() exchanges the two values, no temp variable needed
    }

    // The array is now reversed in place, so a normal front-to-back loop prints it
    for(int i=0; i<n; i++){
        cout << a[i] << " "; // box i, then a space
    }
    cout << endl; // finish the line

    delete[] a; // give the heap array back (delete[] with brackets for an array)

    return 0; // the program ended fine
}
