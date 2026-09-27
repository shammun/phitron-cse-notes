/*

Help Hablu!!!


Problem Statament

In an enchanted forest, there lies a magical book filled with ancient symbols, represented by the string s. 
Hidden deep within its pages Hablu discovers a secret ancient spell, represented by the string t which consists 
of exactly 3 letters. To unlock the spell's power, Hablu needs to find out how many times the spell t appears 
as a subsequence in the magical book s. Can you help Hablu?

A subsequence of a string is a string made from the original string by deleting some characters (can be none) 
without changing the relative order of the remaining characters. For example, the subsequences of "abc" include 
"a", "b", "c", "ab", "ac", "bc", and "abc".

Input Format
- First line contains a single integer T — the number of test cases.
- First line of each test case contains the string  consisting of lowercase letters of the English alphabet.
- The second line of each test case contains the string t consisting of lowercase letters of the English 
alphabet.

Constraints
- 1 <= T <= 10^4
- 1 <= |s| <= 3 X 10^5
- Summation of |s| over all test cases doesn't exceed 

Output Format
For each test cases, output a single integer — the number of times t occurs as a subsequence of s.

Sample Input 0
4
ababcc
abc
effkbd
bad
phiphihhitron
phi
fykklopjplloopre
kop

Sample Output 0
6
0
11
10

Explanation 0
For the first test, we need to count how many times the string t=abc occurs as a subsequence in the string 
s = ababcc.

Let's find all the subsequences of  that match :

Subsequence: a (position 1), b (position 2), c (position 5).
Subsequence: a (position 1), b (position 2), c (position 6).
Subsequence: a (position 1), b (position 4), c (position 5).
Subsequence: a (position 1), b (position 4), c (position 6).
Subsequence: a (position 3), b (position 4), c (position 5).
Subsequence: a (position 3), b (position 4), c (position 6).

So, the string t = abc appears 6 times as a subsequence in the string s = ababcc. Therefore, the output is 6.

*/

// Solution idea: a counting DP table over the two strings, the same shape as
// the LCS table of Module 18 but with + where LCS takes a max.
//   arr[i][j] = in how many ways the first j letters of t can be picked out of
//               the first i letters of s (as a subsequence).
// t has exactly 3 letters, so the table is only 4 columns wide.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long subsequences(string s, string t) {
    int n = s.length();

    // (n+1) rows x 4 columns, all starting at 0. A vector keeps the table on
    // the heap: as a local array long long arr[n+1][4] it would take about
    // 9.6 MB of stack when |s| = 3 * 10^5, enough to crash the program.
    // Counts go up to about (10^5)^3, so they need long long.
    vector<vector<long long>> arr(n + 1, vector<long long>(4, 0));

    // Column 0: the empty part of t can be picked out of any prefix of s in
    // exactly one way - pick nothing.
    for(int i = 0; i <= n; i++) {
        arr[i][0] = 1;
    }

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= 3; j++) {
            // Way 1: do not use the letter s[i-1]. Every way that already
            // worked with the first i-1 letters still works.
            arr[i][j] = arr[i-1][j];

            // Way 2: if s[i-1] equals t[j-1], use it as the j-th letter of t;
            // the first j-1 letters of t must then come from the first i-1
            // letters of s. These ways use a different position, so we add.
            if(s[i-1] == t[j-1]) {
                arr[i][j] += arr[i-1][j-1];
            }
        }
    }

    // All n letters of s used as the pool, all 3 letters of t built.
    // For s = "ababcc", t = "abc" this is 6.
    return arr[n][3];
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        string s, t;
        cin >> s >> t;

        cout << subsequences(s, t) << endl;
    }

    // O(|s| * 3) time per test case.
    return 0;
}
