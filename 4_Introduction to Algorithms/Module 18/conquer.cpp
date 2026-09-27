// The CONQUER half of merge sort, on its own: given two arrays that are each
// already sorted, build one sorted array holding everything from both.
//
// Merge sort is the module's example of DIVIDE AND CONQUER - split the work in
// half, solve each half, then stitch the two answers together. This file is the
// stitching; divide.cpp is the splitting; merge_sort.cpp puts them together.
//
// The one idea to take away: because both inputs are sorted, the smallest value
// not yet used must be at the FRONT of one of them - there is nowhere else it
// could be hiding. So the whole merge is a single walk forwards through both
// arrays, comparing just the two front elements, never looking back and never
// searching. That is why it costs O(n + m) and not O(n log n) all over again.
//
// Trace: a = {1, 4, 7}, b = {2, 3, 9}
//   1<2 take 1 | 4>2 take 2 | 4>3 take 3 | 4<9 take 4 | 7<9 take 7 | a empty,
//   copy the tail 9  ->  c = {1, 2, 3, 4, 7, 9}

#include <iostream>     // cin, cout
#include <vector>       // not used here
#include <algorithm>    // not used here
#include <string>       // not used here

using namespace std;    // no std:: prefix

int main(){
    // First we will take the input for two arrays

    int n, m;      // how many values in the first array, and in the second
    cin >> n >> m;

    // int a[n]: an array whose size is only known at run time (a "variable
    // length array"). g++ accepts it; standard C++ does not.
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];   // read the first sorted array
    }

    // Both arrays must ALREADY be sorted - the merge below assumes it and does
    // not check. Feed it unsorted input and the result is simply unsorted.
    int b[m];
    for(int i=0; i<m; i++){
        cin >> b[i];   // read the second sorted array
    }

    // Now, declare an array to store the result for the merging of two arrays
    int c[n+m];

    // Now, take the two pointers for the two arrays and pointer for the result array
    // i = the next unused position in a, j = the next unused in b,
    // curr = the next free slot in c. All three only ever move forwards.
    int i=0, j=0, curr=0;

    // While both arrays still have something left, compare the two fronts and
    // move the smaller one across. One value is placed per turn, so this loop
    // runs at most n + m times.
    while(i < n && j < m){
        if(a[i] < b[j]){       // a's front is smaller
            c[curr] = a[i];    // place it
            i++;               // a's next value becomes the front
            curr++;            // next free slot in c
        } else{                // b's front is smaller (or equal)
            c[curr] = b[j];
            j++;
            curr++;
        }
    }

    // The loop above stops the moment ONE array runs out, so the other may still
    // have a tail left. That tail is already sorted and every value in it is at
    // least as big as everything placed so far, so it can be copied straight
    // across with no comparisons. Exactly one of these two loops does any work.
    while(i < n){              // leftover values of a
        c[curr] = a[i];
        i++;
        curr++;
    }

    while(j < m){              // leftover values of b
        c[curr] = b[j];
        j++;
        curr++;
    }

    // n + m values came in and n + m go out: nothing is lost or invented, and
    // duplicates are kept.
    // (This i is a NEW variable, local to the for loop; it hides the i above.)
    for(int i=0; i<n+m; i++){
        cout << c[i] << " ";
    }

    return 0;   // success
}