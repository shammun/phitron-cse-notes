/*

https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/D

Print Digits using Recursion

Given a number N. Print the digits of N separated by a space.

Note: Solve this problem using recursion.

Input
First line contains a number T (1 ≤ T ≤ 10) number of test cases.

Next T lines will contain a number N (0 ≤ N ≤ 10^9).

Output
For each test case print a single line contains the digits of the number separated by 
space.

Example
Input
3
121
39
123456

Output
1 2 1 
3 9 
1 2 3 4 5 6 

*/

// Solution idea (recursion, this module).
// n % 10 is the LAST digit, n / 10 is everything before it. Printing the last
// digit first would come out backwards, so: first recurse on n / 10 (which
// prints all the earlier digits), and only on the way back print n % 10.

#include <iostream>
using namespace std;

void printDigits(long long n){
    // Base case: a single digit (this also handles N = 0). Print it, no space.
    if(n < 10){
        cout << n;
        return;
    }

    printDigits(n/10);         // print every digit except the last one
    cout << " " << n % 10;     // then the last, with a space before it
    // For 121: printDigits(12) -> printDigits(1) prints "1", back in 12 prints
    // " 2", back in 121 prints " 1". Result "1 2 1".
}

int main(){
    int t;
    cin >> t;   // number of test cases

    while(t--){
        long long n;
        cin >> n;

        printDigits(n);
        cout << endl;   // one line per test case
    }

    // Cost: O(number of digits) per test, at most 10 calls deep.
    return 0;
}
