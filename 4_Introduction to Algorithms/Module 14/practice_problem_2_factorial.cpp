/*

https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/J

Factorial

Given a number N. Print factorial of N.

Note: Solve this problem using recursion.

Input
Only one line containing a number N (1 ≤ N ≤ 20).

Output
Print the factorial of the number N.

Example
Input
5

Output
120


*/

// Solution idea (recursion, this module): N! = N * (N-1)!, and 1! = 1.
// Each call hands a smaller copy of the problem to the next call until N = 1.

#include <iostream>

using namespace std;

// long long, not int: 13! is already about 6.2 * 10^9, past the int limit,
// while 20! (about 2.4 * 10^18) still fits in a long long.
long long factorial(long long n){
    if(n == 1){
        return 1;   // base case: stop the chain here (N >= 1 is promised)
    }
    return n * factorial(n-1);   // trust the smaller call, then multiply by n
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;

    // Cost: O(N) time and O(N) call-stack depth (at most 20 here).
    return 0;
}
