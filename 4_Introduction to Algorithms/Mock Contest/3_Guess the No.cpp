/*

Problem Statement

You are given a target integer T. Initially, you start with a variable S=0. In each step, you can add 
either 3 or 4 to S. Your task is to determine whether it is possible to reach the target T by performing 
a series of such additions.

Input Format
A single integer T, representing the target sum.

Constraints
1 <= T <= 10^9

Output Format
Print "YES" if it is possible to reach the target T by adding 3 or 4 in each step.
Print "NO" otherwise.

Sample Input 0
10

Sample Output 0
YES

Explanation 0
- Start with S=0.
- Add 3: S=0+3=3.
- Add 4: S=3+4=7.
- Add 3: S=7+3=10.
- The target T=10 is achieved.

Sample Input 1
2

Sample Output 1
NO

Explanation 1
It is impossible to reach 2 by adding only 3 or 4.

*/

// Solution idea: T is up to 10^9, so we cannot try step by step; we reason
// about which totals are reachable instead.
// Small totals, by hand: 3, 4, 6 (3+3), 7 (3+4), 8 (4+4), 9, 10, 11 are
// reachable; 1, 2 and 5 are not. From 12 on everything works: 12, 13 and 14
// are reachable (3+3+3+3, 3+3+3+4, 3+3+4+4), and adding one more 3 to a
// reachable number gives the next block of three, forever.
// So the answer is NO only for 1, 2 and 5.

#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    if(T < 3){
        // 1 and 2 are smaller than the smallest step.
        cout << "NO" << endl;
    } else if(T == 3 || T == 4 || T == 6 || T == 7 || T == 8 || T == 9 || T == 10 || T == 11 || T >= 12){
        // The reachable values listed above; the only number from 3 up that
        // is missing is 5 (3 + 3 = 6 already overshoots it).
        cout << "YES" << endl;
    } else{
        // Only T = 5 gets here.
        cout << "NO" << endl;
    }

    // O(1): a fixed number of comparisons whatever T is.
    return 0;
}
