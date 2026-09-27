/*

Pain Sum

Problem Statement

There is a sequence of length N, the property of the sequence is -

- N >= 3 and N is a multiple of 3.
- Sorted in non-decreasing order.
- Each element appears exactly thrice from 1 to N/3.

You are given the value N and you are also given Q queries, where each query consists of two integers L and R. 
For each query, you need to find the sum of the elements in the sequence from position L to R.

Note: A multiple of 3 is any integer that can be expressed as 3k, where k is an integer. For example: 
3,6,9,12,15 etc. are all multiples of 3.

Input Format
- The first line will contain a single positive integer N and Q, the length of the sequence and the number of 
queries respectively.
- Next Q lines will contain L and R.

Constraints
- 3 <= N <= 10^9
- 1 <= Q <= 2 X 10^5
- 1 <= L <= R <= N

Output Format
For each query find the sum of the elements in the sequence from position L to R. Don't forget to print a 
newline after each query.

Sample Input 0
9 3
2 9
2 6
7 9

Sample Output 0
17
8
9

Explanation 0
In the given test case N = 9 . So the sequence will be [1,1,1,2,2,2,3,3,3]. Now for first query L = 2 and 
R = 9, it represents the values [1,1,2,2,2,3,3,3] which belongs from the position L = 2 to R = 9 
(considering 1-base indexing) and hence the sum of 1+1+2+2+2+3+3+3 = 17 for the first query.

*/

// Solution idea: prefix sums again (like 1_Magical_Forest_Fruits.cpp), but N
// can be 10^9, so we cannot even store the sequence. We do not need to: the
// sequence is so regular that "sum of the first p positions" has a formula.
//
// The first p positions hold k = p / 3 complete groups (1,1,1), (2,2,2), ...,
// (k,k,k), plus r = p % 3 extra copies of the next value k + 1.
//   complete groups: 3 * (1 + 2 + ... + k) = 3 * k * (k + 1) / 2
//   leftovers      : r * (k + 1)
// Then, exactly as with a prefix-sum array, sum(L..R) = prefix(R) - prefix(L-1).

#include <iostream>     // cin, cout

using namespace std;    // no std:: prefix

// Sum of the first p numbers of 1,1,1,2,2,2,3,3,3,...
// long long everywhere: k can be about 3 * 10^8, and k * (k + 1) is near 10^17.
long long prefix(long long p){
    long long k = p / 3;    // how many values appear all three times
    long long r = p % 3;    // 0, 1 or 2 copies of the next value
    // Example p = 7: k = 2, r = 1 -> 3*(1+2) + 1*3 = 9 + 3 = 12,
    // and indeed 1+1+1+2+2+2+3 = 12.
    // k * (k + 1) is always even (one of two neighbours is even), so / 2 is exact.
    return 3 * (k * (k + 1) / 2) + r * (k + 1);
}

int main(){
    // Up to 2 * 10^5 queries: switch off the slow C/C++ stream syncing
    // and print "\n" instead of endl (endl flushes the output every time).
    // sync_with_stdio(false): cin/cout stop staying in step with scanf/printf,
    // which makes them much faster (do not mix the two styles afterwards).
    // cin.tie(nullptr): cin no longer flushes cout before every read.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;     // length of the sequence (up to 10^9)
    int Q;           // number of queries
    cin >> N >> Q;   // N itself is not needed: every L..R already lies inside it

    while(Q--){
        long long L, R;     // 1-based positions
        cin >> L >> R;
        // Positions L..R = (first R positions) - (first L-1 positions).
        // Query 2 9 on N = 9: prefix(9) - prefix(1) = 18 - 1 = 17.
        cout << prefix(R) - prefix(L - 1) << "\n";
    }

    // O(1) per query, and no array at all.
    return 0;
}
