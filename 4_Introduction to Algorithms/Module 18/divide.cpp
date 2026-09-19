// The DIVIDE half of merge sort, on its own: the splitting, with no merging.
//
// Nothing is printed and nothing is sorted - this file exists only to show the
// shape of the recursion that merge_sort.cpp will hang the work on. Put a
// cout << l << " " << r << endl; at the top of divide() to watch the ranges
// being cut in half.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// divide(a, l, r) is responsible for the slice a[l..r], BOTH ends included.
// It never touches anything outside that range - which is what makes it safe for
// the two halves to work on the same array at the same time.
void divide(int a[], int l, int r){
    // One element (l == r) or none (l > r). A slice that short is already in
    // order, so there is nothing to do. This is the stopping point of the
    // recursion.
    if(l >= r){
        return;
    }
    // The cut. Integer division rounds down, so for l = 0, r = 1 the mid is 0 and
    // the halves are [0,0] and [1,1] - both strictly smaller than [0,1], which is
    // what guarantees the recursion gets there in the end.
    int mid = (l+r)/2;
    // Left half:  a[l .. mid]
    divide(a, l, mid);
    // Right half: a[mid+1 .. r]
    // The two ranges touch at mid/mid+1 and together cover l..r exactly once -
    // no gap, no overlap.
    divide(a, mid+1, r);

    // merge_sort.cpp adds one line here: the call that merges the two halves
    // back together. Everything else stays as it is.
}

// Each level of calls halves the size of the ranges, so there are about log2(n)
// levels, and the calls at one level cover the array between them.

int main(){
    // First we will take the input for two arrays

    int n, m;      // m is read but never used - a leftover from conquer.cpp,
    cin >> n >> m; // which needed two array sizes. The input must still supply it.

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // Start with the whole array: positions 0 to n-1 inclusive.
    divide(a, 0, n-1);

    return 0;
}