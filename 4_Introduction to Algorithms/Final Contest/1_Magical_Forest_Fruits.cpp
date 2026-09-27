/*

Problem Statament

In a magical forest, N trees stand in a straight line, each bearing a certain number of enchanted fruits with 
the power to grant wishes. The number of fruits on the i-th tree is given in an array A of size N.

A group of adventurers is planning a journey to collect fruits and needs to determine the total number of 
fruits available within different tree ranges. To help them, you must answer Q queries. Each query consists of 
two integers L and R, representing the range of trees they want to collect fruits from. Your task is to compute 
the total number of fruits in the range [L, R].

Input Format
The first line contains two integers N and Q:
1 <= N <= 10^6 (number of trees)
1 <= Q <= 10^5 (number of queries)

The second line contains N integers , where , representing the number of fruits on each tree.
Each of the next Q lines contains two integers L and R (), representing a query.
Constraints

Output Format

For each query, print a single integer—the total number of fruits in the range [L, R]. Each result should be 
printed on a new line.

Sample Input 0
5 3
2 4 1 5 3
1 3
2 5
4 4

Sample Output 0
7
13
5

Explanation 0

Query (1,3): Trees 1 to 3 → 2 + 4 + 1 = 7
Query (2,5): Trees 2 to 5 → 4 + 1 + 5 + 3 = 13
Query (4,4): Tree 4 alone → 5


*/

// Solution idea: prefix sums. Adding up trees L..R afresh for every query
// would be up to 10^6 steps times 10^5 queries - far too slow. Instead add
// everything up once: sum[i] = fruits on trees 1..i. Then the fruits on trees
// L..R are "everything up to R" minus "everything before L", one subtraction.

#include <iostream>     // cin, cout, endl
using namespace std;    // no std:: prefix

int fruits[1000005];    // fruits[i] = fruits on tree i (1-based)
// sum[i] = fruits[1] + ... + fruits[i]. It is global for two reasons: a global
// array starts at all zeros, so sum[0] = 0 as the formula needs, and 8 MB is
// too big to sit safely on the stack inside main.
// long long, because 10^6 trees can add up to more than an int holds.
long long sum[1000005];

int main(){
    int N, Q;               // trees, queries
    cin >> N >> Q;

    // 1-based on purpose: tree i sits at fruits[i], matching the query numbers.
    for(int i=1; i<=N; i++){
        cin >> fruits[i];
    }

    // Each running total is the previous one plus one more tree.
    // For 2 4 1 5 3: sum = 0, 2, 6, 7, 12, 15.
    for(int i=1; i<=N; i++){
        sum[i] = sum[i-1] + fruits[i];
    }

    while(Q--){             // answer each query
        int L, R;           // the range of trees
        cin >> L >> R;

        // Trees L..R = (trees 1..R) - (trees 1..L-1).
        // Query 2 5: sum[5] - sum[1] = 15 - 2 = 13. With L = 1 it uses sum[0] = 0.
        // (With 10^5 queries, "\n" would be faster than endl, which flushes.)
        cout << sum[R] - sum[L-1] << endl;
    }

    // O(N) once to build, then O(1) per query.
    return 0;
}
