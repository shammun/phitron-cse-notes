/*

https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

2035. Partition Array Into Two Arrays to Minimize Sum Difference

Problem (in my own words)

You are given an array that holds exactly 2n numbers. Split it into two arrays of n numbers
each - every number is used once, and both sides must end up with the same amount of numbers.
Add up each side and look at the difference between the two sums. Return the smallest
difference you can reach.

This is the same job as "Mina and Moni" in this contest, but harder: the numbers here may be
negative, so a table indexed by the sum does not work, and n can be large enough that trying
every split one by one is far too slow.

Input Format
First line: an integer m, the amount of numbers (m is always even, m = 2n).
Second line: the m numbers, separated by spaces.

Output Format
One number: the smallest possible difference of the two sums.

Constraints
The array length is 2n with n at most 15, so there are at most 30 numbers.
The numbers may be negative as well as positive.

Sample Input 0
4
3 9 7 3

Sample Output 0
2

Explanation 0
n = 2, so each side gets 2 numbers. Take {3, 9} (sum 12) and {7, 3} (sum 10). The difference
is 2. No split of these four numbers into two pairs does better: {3, 7} vs {9, 3} gives
10 vs 12, again 2, and {3, 3} vs {9, 7} gives 6 vs 16, a difference of 10.

Sample Input 1
6
2 -1 0 4 -2 -9

Sample Output 1
0

Explanation 1
n = 3. Take {0, -1, -2} (sum -3) and {2, 4, -9} (sum -3). Both sides are -3, so the
difference is 0.

How the fast method works ("meet in the middle")

Trying every way to choose n of the 2n numbers means about 155 million choices when n = 15 -
too many. So cut the array in half: the first n numbers and the last n numbers. Each half has
only 2^n = 32768 subsets, which is nothing.

The finished left side takes k numbers from the first half and n - k from the second half, for
some k between 0 and n. So:
  - list every subset sum of the first half, grouped by how many numbers it took;
  - do the same for the second half, and sort each group;
  - for each k, walk the left group of size k, and for every sum in it binary-search the
    right group of size n - k for the partner that lands the total closest to half of
    everything.

Sorting is what makes the binary search legal, and the binary search is what turns a
32768 x 32768 comparison into 32768 x log(32768).

*/

// <bits/stdc++.h>: g++'s "include the whole standard library" header.
#include <bits/stdc++.h>

using namespace std;    // no std:: prefix

// LeetCode's required class; minimumDifference is what the judge calls.
class Solution {
public:   // usable from outside the class
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;     // each side gets n numbers

        long long total = 0;         // sum of everything
        for (int i = 0; i < (int)nums.size(); i++) {
            total += nums[i];
        }

        /* left[c] holds every sum you can make by taking exactly c numbers out of the first
           half; right[c] does the same for the second half. Grouping by the count is the
           whole point - the two sides must end up with n numbers each. */
        // (The space in "> >" is only for very old compilers.)
        vector<vector<long long> > left(n + 1), right(n + 1);

        // Every subset of n positions is one number "mask" from 0 to 2^n - 1:
        // bit b of mask is 1 when position b is taken. (1 << n) is 2^n.
        // Example n = 3, mask = 5 = binary 101 -> positions 0 and 2 are taken.
        for (int mask = 0; mask < (1 << n); mask++) {
            long long sumLeft = 0, sumRight = 0;
            int taken = 0;                    // how many positions this mask takes
            for (int bit = 0; bit < n; bit++) {
                // mask & (1 << bit) is non-zero exactly when that bit is 1.
                if (mask & (1 << bit)) {
                    taken++;
                    sumLeft += nums[bit];       // first half
                    sumRight += nums[n + bit];  // second half
                }
            }
            left[taken].push_back(sumLeft);
            right[taken].push_back(sumRight);
        }

        /* The binary search below needs the right-hand groups in order. */
        for (int c = 0; c <= n; c++) {
            sort(right[c].begin(), right[c].end());
        }

        long long best = LLONG_MAX;   // smallest difference found; starts "infinite"

        for (int k = 0; k <= n; k++) {
            /* k numbers come from the first half, so n - k must come from the second. */
            // & makes partners another name for right[n - k] (no copy).
            vector<long long> &partners = right[n - k];

            for (int i = 0; i < (int)left[k].size(); i++) {
                long long sumLeft = left[k][i];

                /* If the chosen side sums to S, the other side sums to total - S and the
                   difference is |total - 2*S|. So with sumLeft already fixed we want a
                   partner p with 2*(sumLeft + p) as close to total as possible, that is
                   2*p as close as possible to target. */
                long long target = total - 2 * sumLeft;

                /* First position whose doubled value is not below the target. Written by
                   hand instead of lower_bound so the "2 *" stays inside the comparison and
                   no halving of an odd number can go wrong. */
                // Binary search on [lo, hi): the answer always stays inside it,
                // and the range halves every pass.
                int lo = 0, hi = partners.size();
                while (lo < hi) {
                    int mid = (lo + hi) / 2;
                    if (2 * partners[mid] >= target) {
                        hi = mid;         // mid works; the answer is mid or earlier
                    } else {
                        lo = mid + 1;     // mid too small; the answer is later
                    }
                }

                /* The best partner is either that one (just above) or the one before it
                   (just below), so check both. */
                if (lo < (int)partners.size()) {
                    long long diff = target - 2 * partners[lo];
                    if (diff < 0) diff = -diff;          // absolute value
                    if (diff < best) best = diff;
                }
                if (lo > 0) {
                    long long diff = target - 2 * partners[lo - 1];
                    if (diff < 0) diff = -diff;
                    if (diff < best) best = diff;
                }
            }
        }

        return (int)best;   // convert back to the int the judge expects
    }
};

// Small driver so the file runs on its own.
int main() {
    int m;                  // amount of numbers (2n)
    cin >> m;

    vector<int> nums(m);
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    Solution sol;           // object to call the method on
    cout << sol.minimumDifference(nums) << endl;

    return 0;   // success
}
