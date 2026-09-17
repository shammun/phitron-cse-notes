/*

Max and Min
time limit per test: 0.25 seconds
memory limit per test: 64 megabytes
Given 3 numbers A, B and C, Print the minimum and the maximum numbers.

Input
Only one line containing 3 numbers A, B and C ( - 105 ≤ A, B, C ≤ 105)

Output
Print the minimum number followed by a single space then print the maximum number.

Examples
Input
1 2 3
Output
1 3
Input
-1 -2 -3
Output
-3 -1
Input
10 20 -5
Output
-5 20

*/

#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int min = a;
    if(b < min){
        min = b;
    }
    if(c < min){
        min = c;
    }

    int max = a;
    if(b > max){
        max = b;
    }
    if(c > max){
        max = c;
    }

    cout << min << " " << max << endl;

    return 0;
}