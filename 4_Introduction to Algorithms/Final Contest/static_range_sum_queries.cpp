/*

Static Range Sum Queries   (CSES 1646)

You are given an array of n values and q queries. Each query gives two
positions a and b (1-based) and asks for the sum of the values from
position a to position b, ends included. The array never changes.

Answering a query by walking from a to b would cost O(n) each time, which
is too slow for 2 * 10^5 queries. Build a prefix sum array once:
pre[i] = value[1] + ... + value[i]. Then the answer of a query is
pre[b] - pre[a-1], one subtraction.

Constraints
    1 <= n, q <= 2 * 10^5
    1 <= a <= b <= n

The values can be large and there can be 2 * 10^5 of them, so the sums do
not fit in an int. Keep the prefix array in long long.

Input
    first line: n and q
    second line: the n values
    next q lines: a and b

Output
    one line per query: the sum of the values from a to b

Example

input
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3

output
11
2
24
4

    The prefix sums are 3, 5, 9, 14, 15, 16, 21, 24. The first query is
    pre[4] - pre[1] = 14 - 3 = 11, and the last one is
    pre[3] - pre[2] = 9 - 5 = 4.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // The input can be large, so turn off the sync with C stdio and never
    // use endl (it flushes on every line).
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // pre[0] = 0 lets a query that starts at position 1 use the same
    // formula as every other query, with no special case.
    vector<long long> pre(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << "\n";
    }

    return 0;
}
