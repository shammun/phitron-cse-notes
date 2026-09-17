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

#include <iostream>

using namespace std;

int factorial(int n){
    if(n == 1){
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;

    return 0;
}