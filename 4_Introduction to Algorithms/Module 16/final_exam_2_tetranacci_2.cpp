/*

https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/tetranacci-number

Tetranacci Number II

The Tetranacci sequence is an extension of the well-known Fibonacci sequence, incorporating four 
previous terms instead of two.

The Tetranacci sequence Tn is defined as follows:

- T0 = 0, T1 = 1, T2 = 1,T3 = 2
- For n >= 4, Tn = Tn-1 + Tn-2 + Tn-3 + Tn-4

Given an integer 𝑛, return the value of Tn

Note : You must solve this problem using Loop. (Bottom up)

Input Format
A single integer n representing the position in the Tetranacci sequence.

Constraints
- 0 <= n <= 60
- The result is guaranteed to fit within a 64-bit integer (<=2^63-1 )

Output Format
Print a single integer, the value of Tn

Sample Input 0
4

Sample Output 0
4

Explanation 0
T4 = T3 + T2 + T1 + T0 = 2 + 1 + 1 + 0 = 4

Sample Input 1
5

Sample Output 1
8

Explanation 1
T5 = T4 + T3 + T2 + T1 = 4 + 2 + 1 + 1 = 8

*/

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long tetra[n+1];

    tetra[0] = 0;
    tetra[1] = 1;
    tetra[2] = 1;
    tetra[3] = 2;

    for(int i=4; i<=n; i++){
        tetra[i] = tetra[i-1] + tetra[i-2] + tetra[i-3] + tetra[i-4];
    }

    cout << tetra[n] << endl;
    return 0;
}