/*

Sort an Array   (LeetCode 912)

Given an array of integers, return it sorted in increasing order. The
built-in sort is not allowed, so this is the module's own merge sort:
split the array in half, sort each half by the same routine, then merge
the two sorted halves in one walk.

Constraints
    1 <= nums.length <= 5 * 10^4
    -5 * 10^4 <= nums[i] <= 5 * 10^4

Input (for the small driver below)
    first line: n, the number of values
    second line: the n values

Output
    sorted = the values in increasing order, separated by spaces

Example 1

input
4
5 2 3 1

output
sorted = 1 2 3 5

Example 2

input
6
5 1 1 2 0 0

output
sorted = 0 0 1 1 2 5

    Equal values stay next to each other; merge sort keeps them in order
    because the merge takes from the left half when the two fronts tie.

*/

// <bits/stdc++.h>: g++'s "include the whole standard library" header.
#include <bits/stdc++.h>
using namespace std;    // no std:: prefix

// LeetCode's required class; sortArray is what the judge calls.
class Solution {
public:   // usable from outside the class
    // Both halves a[l..mid] and a[mid+1..r] are already sorted.
    // Copy them out and write the smaller front back into a, one at a time.
    // a is passed by reference (&), so the caller's vector is changed.
    void conquer(vector<int>& a, int l, int mid, int r) {
        // vector(first, last) copies the elements from first up to (not
        // including) last. a.begin() + l points at a[l].
        vector<int> left(a.begin() + l, a.begin() + mid + 1);       // a[l..mid]
        vector<int> right(a.begin() + mid + 1, a.begin() + r + 1);  // a[mid+1..r]

        // i = next unused in left, j = next unused in right,
        // curr = next slot of a to write.
        int i = 0, j = 0, curr = l;

        // While both halves have values left, place the smaller front.
        while (i < (int)left.size() && j < (int)right.size()) {
            // <= and not <, so that equal values keep their original order.
            if (left[i] <= right[j]) {
                a[curr] = left[i];
                i++;
            } else {
                a[curr] = right[j];
                j++;
            }
            curr++;             // one slot filled either way
        }

        // One side may still have leftovers; they are already in order.
        while (i < (int)left.size()) {
            a[curr] = left[i];
            i++;
            curr++;
        }
        while (j < (int)right.size()) {
            a[curr] = right[j];
            j++;
            curr++;
        }
    }

    // Sorts a[l..r] (both ends included). The two recursive calls are trusted
    // to return their halves sorted; conquer then merges them.
    void divide(vector<int>& a, int l, int r) { // O(n log n)
        // One value (or none) is already sorted, so there is nothing to do.
        if (l >= r) {
            return;
        }

        int mid = (l + r) / 2;      // split point (rounds down)
        divide(a, l, mid);          // sort the left half
        divide(a, mid + 1, r);      // sort the right half
        conquer(a, l, mid, r);      // merge the two sorted halves
    }

    // Sort the whole vector in place, then return it.
    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

// Small driver so the file runs on its own.
int main() {
    int n;                      // how many values
    cin >> n;

    vector<int> nums(n);        // n slots
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;               // object to call sortArray on
    vector<int> ans = sol.sortArray(nums);

    cout << "sorted =";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << " " << ans[i];  // a space before each value
    }
    cout << endl;

    return 0;   // success
}
