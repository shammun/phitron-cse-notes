/*

N Times

time limit per test: 1 second
memory limit per test: 256 megabytes
Given a number N and a character C. Print the character(C) N times.

Note: Solve this problem using function.

Input

The first line contains a number T (1≤T≤50) the number of test cases.
Next T lines contains a number N and a character C (1≤N≤100).

Output
Print T lines, for every line print the character(C) N times separated by space.

Examples
Input
2
1 n
5 O
Output
n 
O O O O O 

Input
1
8 z
Output
z z z z z z z z 

*/

#include <iostream> // Include the input/output stream library for using cout
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

string generateString(int n, char c){
    string s = "";
    for(int i=0; i<n; i++){
        s += c;
        if (i != n-1){
            s += " ";
        }
    }
    return s;
}

int main(){
    int t;
    cin >> t;

    int n[50];
    char c[50];
    string outputs[50];

    for(int i=0; i<t; i++){
        cin >> n[i] >> c[i];
        outputs[i] = generateString(n[i], c[i]);
    }

    for(int i=0; i<t; i++){
        cout << outputs[i] << endl;
    }

    return 0;
}