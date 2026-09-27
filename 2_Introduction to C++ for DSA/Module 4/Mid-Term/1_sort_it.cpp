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

// Idea of this solution:
//   1. A function reads the N numbers into an array it creates with `new`,
//      sorts that array from small to big, and returns it to main.
//   2. main prints the array front to back (ascending),
//   3. then prints the SAME array back to front (descending) - no second sort.
// The values fit in int: -10^9..10^9 is inside int's range (about -2.1*10^9..2.1*10^9).

#include <iostream>  // brings in cin (read from keyboard/input) and cout (print to screen)
#include <algorithm> // brings in sort(), the ready-made sorting function of C++
using namespace std; // lets us write cin/cout/sort instead of std::cin/std::cout/std::sort

// A second way to solve the same question, in the shape of Module 2:
// the function builds the array on the heap, reads it, sorts it ascending
// and returns its address. A local `int a[n]` could not be returned - it
// would die when the function ends - but a `new` array lives on.
//   Parameter n : how many numbers to read.
//   Returns     : int* = the address of the first element of the sorted array.
int* sort_it(int n){ // int* in front of the name = the function gives back a pointer to int
    // new int[n] asks the heap (free-store memory) for room for n ints and gives
    // back the address of the first one. Heap memory stays alive until we delete it,
    // even after this function returns - that is why it can be handed back to main.
    int* a = new int[n];
    // Read the n numbers. One pass reads one number into slot i; i goes 0..n-1.
    for(int i=0; i<n; i++){
        cin >> a[i]; // cin >> skips spaces/newlines and reads the next whole number into a[i]
    }
    // sort(first, last) sorts the range [first, last): a is the address of a[0],
    // a+n is the address just PAST the last element, so the whole array is sorted.
    // With no third argument it uses <, i.e. ascending. {2,4,6,1,3} -> {1,2,3,4,6}
    sort(a, a+n); // ascending: small to big
    return a; // give main the address of the (now sorted) heap array
} // the local variable a (the pointer) dies here, but the heap array it pointed to does not

int main(){ // program starts here

    int n;     // how many numbers are in the array
    cin >> n;  // read N from the first line
    int* sorted_array = sort_it(n); // receive the heap array from the function (its address)

    // Print the sorted array in ascending order:
    // walk i = 0, 1, ..., n-1 and print each value followed by a space.
    for(int i=0; i<n; i++){
        cout << sorted_array[i] << " "; // a pointer can be indexed like an array: sorted_array[i]
    }
    cout << endl; // endl = go to a new line (and flush the output)

    // Print the sorted array in descending order.
    // No second sort is needed: an ascending array read from the back IS descending.
    // i starts at the last index n-1 and goes down to 0; the loop stops when i becomes -1.
    // {1,2,3,4,6} read backwards -> 6 4 3 2 1
    for(int i=n-1; i>=0; i--){
        cout << sorted_array[i] << " "; // print the value at position i
    }
    cout << endl; // finish the second line

    delete[] sorted_array; // the array came from new[], so give it back with delete[]

    return 0; // 0 tells the operating system the program finished normally
}