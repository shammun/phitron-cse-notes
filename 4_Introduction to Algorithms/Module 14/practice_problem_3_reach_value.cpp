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

#include <iostream>
#include <set>

using namespace std;

set<long long> visited;

bool canReach(long long target){
    if(target == 1){
        return true;
    }
    if(target < 1){
        return false;
    }

    if(visited.find(target) != visited.end()){
        return false;
    }

    visited.insert(target);

    if(target % 10 == 0 && canReach(target / 10)){
        return true;
    }
    if(target % 20 == 0 && canReach(target / 20)){
        return true;
    }

    return false;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        visited.clear();

        if(canReach(n)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

