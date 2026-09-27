/*

Selection Sort for an array of integers.

Input : n, then n integers.
Output: the same integers in ascending order, on one line, separated by spaces.

The idea: for each position `i` (left to right), look at every later position
`j` and swap whenever the later value is smaller. When the inner loop ends,
position `i` holds the smallest of everything from `i` onwards, so it is
finished and `i` can move on. Two nested loops over n values: O(n^2) time,
O(1) extra space.

Example: n = 4, values 3 1 4 2
    i=0: compare with 1 (swap -> 1 3 4 2), 4 (no), 2 (no)   -> 1 3 4 2
    i=1: compare with 4 (no), 2 (swap -> 1 2 4 3)           -> 1 2 4 3
    i=2: compare with 3 (swap)                              -> 1 2 3 4
    output: 1 2 3 4

*/

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // has std::swap too; our own swap below is chosen because a plain function beats a template
#include <string>     // std::string - not used here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Swap two ints. `int &a` is a reference: `a` is another name for the
// caller's variable, so the caller's two values really change places.
void swap(int &a, int &b){
    int temp = a;   // keep a's old value
    a = b;          // a gets b
    b = temp;       // b gets a's old value
}

int main(){
    int n;          // how many numbers
    cin >> n;
    // An array whose size is known only at run time (a "variable-length
    // array"). Standard C++ wants a constant size; g++ allows this as an
    // extension.
    int arr[n];
    // Read the n values into arr[0] .. arr[n-1].
    for(int i=0; i<n; i++){
        cin >> arr[i];   // `>>` reads the next integer, skipping spaces/newlines
    }

    // Outer loop: settle position i. It stops at n-2 because once every
    // earlier position is final, the last one has nothing left to swap with.
    for(int i=0; i<n-1; i++){
        // Inner loop: compare position i with every position after it.
        for(int j=i+1; j<n; j++){
            // A smaller value later on? Bring it forward. After this inner
            // loop, arr[i] is the smallest of arr[i..n-1].
            if(arr[j] < arr[i]){
                swap(arr[i], arr[j]);
            }
        }
    }

    // Print the sorted values on one line, separated by spaces.
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    // main has no `return 0;` - C++ allows that for main only; it returns 0 automatically.
}
