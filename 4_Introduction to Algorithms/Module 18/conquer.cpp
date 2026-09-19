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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    // First we will take the input for two arrays

    int n, m;      // how many values in the first array, and in the second
    cin >> n >> m;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // Both arrays must ALREADY be sorted - the merge below assumes it and does
    // not check. Feed it unsorted input and the result is simply unsorted.
    int b[m];
    for(int i=0; i<m; i++){
        cin >> b[i];
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
        if(a[i] < b[j]){
            c[curr] = a[i];
            i++;
            curr++;
        } else{
            c[curr] = b[j];
            j++;
            curr++;
        }
    }

    // The loop above stops the moment ONE array runs out, so the other may still
    // have a tail left. That tail is already sorted and every value in it is at
    // least as big as everything placed so far, so it can be copied straight
    // across with no comparisons. Exactly one of these two loops does any work.
    while(i < n){
        c[curr] = a[i];
        i++;
        curr++;
    }

    while(j < m){
        c[curr] = b[j];
        j++;
        curr++;
    }

    // n + m values came in and n + m go out: nothing is lost or invented, and
    // duplicates are kept.
    for(int i=0; i<n+m; i++){
        cout << c[i] << " ";
    }

    return 0;
}