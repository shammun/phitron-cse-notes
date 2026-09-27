/*

Distinct Subsequences   (LeetCode 115)

Given two strings s and t, count how many different ways t can be picked
out of s as a subsequence. A subsequence keeps the order of the letters but
may drop any of them, so two ways count as different when they use
different positions of s, even if the letters look the same.

This is a DP table over the two strings, like the LCS table of Module 18,
but it adds instead of taking a max:

    dp[i][j] = number of ways to build the first j letters of t out of the
               first i letters of s

    dp[i][0] = 1        (the empty t is built in exactly one way: take nothing)
    dp[0][j] = 0 for j > 0   (a non-empty t cannot come out of an empty s)
    dp[i][j] = dp[i-1][j]                      (skip s[i-1])
             + dp[i-1][j-1] if s[i-1] == t[j-1] (match s[i-1] with t[j-1])

The answer is dp[n][m].

Constraints
    1 <= s.length, t.length <= 1000
    s and t are made of English letters
    the answer fits in a signed 32-bit integer

The table itself is kept in long long: a half-built count can grow past an
int even when the final answer does not.

Input (for the small driver below)
    first line: s
    second line: t

Output
    numDistinct = the number of ways

Example 1

input
rabbbit
rabbit

output
numDistinct = 3

    "rabbit" is spelled out by dropping one of the three b's, and there are
    three of them to drop.

Example 2

input
babgbag
bag

output
numDistinct = 5

    s is b a b g b a g, so the b's sit at positions 1, 3, 5, the a's at
    2 and 6, and the g's at 4 and 7. The five sets of positions that spell
    "bag" in order are (1,2,4), (1,2,7), (1,6,7), (3,6,7) and (5,6,7).

*/

// <bits/stdc++.h>: g++'s "include the whole standard library" header.
#include <bits/stdc++.h>
using namespace std;    // no std:: prefix

// LeetCode's required class; numDistinct is what the judge calls.
class Solution {
public:   // usable from outside the class
    int numDistinct(string s, string t) {
        int n = s.size();   // length of s
        int m = t.size();   // length of t

        // (n+1) x (m+1) table of zeros; dp[i][j] as defined in the header.
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // Building nothing out of any prefix of s is one way: take nothing.
        // Row 0 stays at 0 for j > 0, because an empty s builds nothing.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill row by row: row i only reads row i-1, which is already done.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Always possible: leave s[i-1] out of the answer.
                dp[i][j] = dp[i - 1][j];

                // If the letters agree, s[i-1] may also be used as t[j-1],
                // and then both strings step back by one.
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        // The judge promises the final answer fits in an int.
        return (int)dp[n][m];
    }
};

// Small driver so the file runs on its own.
int main() {
    string s, t;            // two words, one per line
    cin >> s >> t;

    Solution sol;           // object to call numDistinct on
    cout << "numDistinct = " << sol.numDistinct(s, t) << endl;

    return 0;   // success
}
