/*

https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W

Reach Value

Given a number N. Initially you have a value equal 1 and you can perform one of the 
following operation any number of times:

1. Multiply your current value by 10.
2. Multiply your current value by 20.

Determine if your value can reach N or not.

Note: Solve this problem using recursion.

Input
First line contains a number T (1≤T≤100) number of test cases.

Next T lines will contain a number N (1≤N≤10^12).

Output
For each test case print "YES" if your value can reach exactly N otherwise, print "NO".

Example
Input
5
1
2
10
25
200

Output
YES
NO
YES
NO
YES

*/

// Solution idea (recursion, this module), worked BACKWARDS from N.
// Going forward from 1 there are two choices at every step. Going backward is
// simpler: if N was made by "times 10", then N / 10 must be reachable; if by
// "times 20", then N / 20 must be. Only try a division when it is exact.
// Reaching exactly 1 means YES; anything that cannot be divided further is NO.

#include <iostream>
#include <set>

using namespace std;

// Values already tried in this test case (a memo of failures). A value we see
// a second time has already been answered "no", or we would have stopped.
set<long long> visited;

bool canReach(long long target){
    if(target == 1){
        return true;    // back at the starting value: a path exists
    }
    if(target < 1){
        return false;
    }

    // Already explored from here and it did not lead to 1.
    if(visited.find(target) != visited.end()){
        return false;
    }

    visited.insert(target);

    // Undo a "times 10" step, if N really is a multiple of 10.
    if(target % 10 == 0 && canReach(target / 10)){
        return true;
    }
    // Undo a "times 20" step, if N really is a multiple of 20.
    if(target % 20 == 0 && canReach(target / 20)){
        return true;
    }

    return false;   // neither undo works: N cannot be built
}

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;   // N is up to 10^12, too big for int
        cin >> n;

        visited.clear();   // a fresh memo for every test case

        if(canReach(n)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    // Cost: each division shrinks N at least tenfold, so about 12 levels;
    // the memo keeps the branching small.
    return 0;
}
