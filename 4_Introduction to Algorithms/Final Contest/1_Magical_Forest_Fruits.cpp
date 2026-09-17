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


#include <iostream>
using namespace std;

int fruits[1000005];

int main(){
    int N, Q;
    cin >> N >> Q;

    for(int i=1; i<=N; i++){
        cin >> fruits[i];
    }

    long long sum[1000005];

    for(int i=1; i<=N; i++){
        sum[i] = sum[i-1] + fruits[i];
    }

    while(Q--){
        int L, R;
        cin >> L >> R;

        cout << sum[R] - sum[L-1] << endl;
    }

    return 0;
}
