// Longest common SUBSEQUENCE (LCS) using recursion.
// We will be given two strings a and b. We have to find the length of the
// longest common subsequence of the two strings.
// We will use memoization to optimize the solution.
//
// Subsequence, not substring - the difference matters and the module's quiz
// asks about it:
//   * a substring is a run of neighbouring characters - "bcd" in "abcde";
//   * a subsequence keeps the order but may skip characters - "ace" in "abcde".
// For "abcde" and "ace" this program prints 3 (the subsequence a-c-e); the
// longest common substring is only "a", "c" or "e", length 1. A substring
// version would have to throw the count away whenever two characters differ,
// where the code below keeps the better of two partial answers instead.
//
// This is the same take-it-or-leave-it DP as Module 15 and Module 17, with two
// strings to walk through instead of one list of items.
//
// The DP in three parts:
//   meaning     dp[i][j] = LCS length of a[0..i] and b[0..j]
//   base case   i < 0 or j < 0 (an empty prefix) -> 0
//   transition  a[i] == b[j]: dp[i][j] = dp[i-1][j-1] + 1
//               otherwise:    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// Trace for "abcde" / "ace": e == e -> 1 + lcs("abcd","ac");
//   d != c -> max(lcs("abc","ac"), lcs("abcd","a")); c == c -> 1 + lcs("ab","a")
//   = 1 + 1 ... total 3.


#include <iostream>     // cin, cout
#include <vector>       // not used here
#include <algorithm>    // max
#include <string>       // string

using namespace std;    // no std:: prefix
string a, b;            // the two input strings (global so lcs can read them)
// dp[i][j] is the answer to one question: "what is the LCS length of the first
// i+1 characters of a and the first j+1 characters of b?" - that is, of the
// PREFIXES a[0..i] and b[0..j]. The two indexes are just the two arguments of
// lcs(). -1 marks a cell as not worked out yet; a length is never negative, so
// -1 can never be mistaken for a real answer.
// 1005 x 1005 ints is about 4 MB, far too much for the stack, hence global.
int dp[1005][1005];

// lcs(i, j) = length of the longest common subsequence of a[0..i] and b[0..j].
// Both strings are walked from the BACK; i and j shrink towards -1.
int lcs(int i, int j){
    // One of the prefixes is empty, so there is nothing in common: 0.
    // This also covers an empty input string, where the first call is lcs(-1, ..).
    if(i < 0 || j < 0){
        return 0;
    }

    // Already answered for this pair of prefixes? Reuse it. Without this line the
    // two calls below would branch endlessly; with it, only n x m distinct pairs
    // exist, so that is the most work that can be done.
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(a[i] == b[j]){
        // The two last characters match, so they can be the last character of the
        // common subsequence. Take it - it never costs anything to do so - and
        // step BOTH strings back one place.
        dp[i][j] = lcs(i-1, j-1) + 1;
        return dp[i][j];
    } else{
        // They differ, so at most one of them can belong to the answer. Two
        // choices, and the better one wins:
        //   op1 = drop a[i], keep all of b   (step only i back)
        int op1 = lcs(i-1, j);
        //   op2 = drop b[j], keep all of a   (step only j back)
        int op2 = lcs(i, j-1);
        dp[i][j] = max(op1, op2);   // store the better one
        return dp[i][j];
    }
}

int main(){
    // Mark every cell unknown. memset fills BYTES, and the byte 11111111 makes
    // the int -1 too, so this really does store -1 in all of them. (memset comes
    // from <cstring>, which this file does not include - it compiles only because
    // another header brings it in.)
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;      // two words (cin >> stops at spaces)
    int n = a.size();   // length of a
    int m = b.size();   // length of b
    // Start from the last character of each string. Note there is no endl, so the
    // number is printed with no newline after it.
    cout << lcs(n-1, m-1);

    return 0;           // success
}
