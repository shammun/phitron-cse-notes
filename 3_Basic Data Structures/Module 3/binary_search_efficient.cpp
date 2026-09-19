/*

Codeforces group - Z. Binary Search

Same problem as binary_search_brute_force.cpp: n numbers, then q questions of the form
"is this value in the array?".

The brute-force file answers each question with a full scan and costs O(n*q), which is
10^10 steps at the judge's limits - far too slow. This file pays one sort up front and
then answers each question by halving the search range.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // The one line that changes everything. sort() from <algorithm> puts a[0..n-1] in
    // increasing order; a+n is one past the last box, the usual C++ "end" marker.
    // Sorting costs O(n log n) and is paid exactly once, before any query is read.
    // Why it is allowed: the questions only ask whether a value is present, and sorting
    // does not add or remove values - it only rearranges them.
    // Why it is needed: binary search below decides to throw away a whole half of the
    // range, and that decision is only correct if the array is in order. Run this code
    // on an unsorted array and it will answer "not found" for values that are there.
    sort(a, a+n);

    for(int i=0; i<q; i++){
        int x;
        cin >> x;
        int flag = 0;

        // The search window: the answer, if it exists at all, is somewhere in
        // a[l..r] inclusive. It starts as the whole array.
        int l = 0;
        int r = n - 1;

        // Keep going while the window still holds at least one box. When l and r cross
        // (l > r) the window is empty and x is simply not in the array.
        // The test is `l <= r`, not `l < r`: with l == r there is still one box left to
        // look at, and dropping that case would miss values sitting at the very edge.
        while(l <= r){
            // The middle box of the current window. Integer division rounds down, so
            // with l = 0, r = 3 mid is 1 - that is fine, either half is a fair guess.
            int mid = (l + r) / 2;

            if(a[mid] == x){
                flag = 1;
                break;                 // found it, stop this query
            } else if(a[mid] < x){
                // The middle is too small. The array is sorted, so everything at mid
                // and to its left is also too small - none of it can be x. Drop that
                // whole half by moving the left edge just past mid.
                l = mid + 1;
            } else {
                // The middle is too big, so mid and everything to its right is too big.
                // Move the right edge just before mid.
                r = mid - 1;
            }
            // Note the `+ 1` and `- 1`. mid has already been compared, so it must be
            // left out of the next window. Writing `l = mid;` would let a two-box window
            // pick the same mid for ever and the program would hang.
        }

        if(flag == 1){
            cout << "found" << endl;
        }
        else{
            cout << "not found" << endl;
        }
    }

    // What this costs, next to the brute force.
    //   sorting          O(n log n), once
    //   each query       O(log n), because the window's length halves every step:
    //                    n -> n/2 -> n/4 -> ... -> 1
    //   whole program    O(n log n + q log n)
    //
    // At n = q = 10^5, log2(n) is about 17. The brute force needed n*q = 10^10
    // comparisons; this needs roughly 10^5 * 17 = 1.7 * 10^6 for the queries plus the
    // sort - a few thousand times less work, and it finishes well inside the limit.
    //
    // Trace of one query on the sample. After sorting, a = 1 2 3 6 8, and x = 5:
    //   l=0 r=4  mid=2  a[2]=3 < 5  -> l=3      (boxes 0..2 thrown away)
    //   l=3 r=4  mid=3  a[3]=6 > 5  -> r=2
    //   l=3 > r=2 -> window empty, loop ends, flag is still 0 -> "not found"
    // Three steps instead of five comparisons here; on a big array, 17 instead of 10^5.

    return 0;
}