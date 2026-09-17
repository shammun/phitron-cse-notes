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

#include <iostream>
using namespace std;

void printDigits(long long n){
    if(n < 10){
        cout << n;
        return;
    }

    printDigits(n/10);
    cout << " " << n % 10;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        printDigits(n);
        cout << endl;
    }

    return 0;
}