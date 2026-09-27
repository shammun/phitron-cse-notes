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

// Solution idea: the same sequence, but bottom-up (fibonacci_bottom_up_loop.cpp,
// Module 14). Fill a table from the smallest index upwards; by the time we reach
// tetra[i], the four values it needs are already sitting in the table.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    // n goes up to 60 and T60 is far beyond int, so the table holds long long.
    // The table has 65 boxes, not n+1: the four base values below are always
    // written, and with n < 3 an array of size n+1 would be too small for them.
    long long tetra[65];

    // The four given starting values.
    tetra[0] = 0;
    tetra[1] = 1;
    tetra[2] = 1;
    tetra[3] = 2;

    // Every later term is the sum of the four just before it.
    // With n = 5: tetra[4] = 2+1+1+0 = 4, then tetra[5] = 4+2+1+1 = 8.
    for(int i=4; i<=n; i++){
        tetra[i] = tetra[i-1] + tetra[i-2] + tetra[i-3] + tetra[i-4];
    }

    cout << tetra[n] << endl;
    // One pass over the table: O(n) time, O(n) memory, and no recursion at all.
    return 0;
}
