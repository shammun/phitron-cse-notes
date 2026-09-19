/*

Practice copy of selection_sort_array.cpp, re-typed from memory.

It does not compile, because of a single missing character: the input loop
says `cin > arr[i];` with one `>`. A single `>` is the "greater than"
comparison; reading from the keyboard needs the extraction operator `>>`. The
compiler's message runs for pages, but the first line says it all:

    no match for 'operator>' (operand types are 'std::istream' and 'int')

- there is no way to compare an input stream with an int, so it lists every
`operator>` it knows and none of them fits. Change the line to
`cin >> arr[i];` and the program works. Apart from that one character the code
is the same as the original.

The method itself: for each position `i`, look at every later position `j` and
swap whenever the later value is smaller. When the inner loop ends, position
`i` holds the smallest of everything from `i` onwards, so it is finished and
`i` can move on. Two nested loops over n values, so O(n^2) time and O(1) extra
space.

Input: first n, then n numbers.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Swap two ints. The parameters are references, so this really exchanges the
// caller's two values instead of two copies.
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n;
    cin >> n;
    // An array whose size is only known while the program runs. Standard C++
    // asks for a constant size here; g++ allows this as an extension, which
    // is why the course can use it.
    int arr[n];
    // Read the n values. The next line is the typo: `>` instead of `>>`.
    for(int i=0; i<n; i++){
        cin > arr[i];
    }

    // The outer loop settles one position at a time and stops at n-2: once
    // every earlier position holds its final value, the last one has nothing
    // left to be swapped with.
    for(int i=0; i<n-1; i++){
        // Compare position i with every position after it.
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
}