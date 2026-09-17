/*

Take a stack of size N as input and copy those elements to another stack to get the 
values in the order they were inserted and print them. You should use STL to solve 
this problem.

Input
5
10 20 30 40 50

Output
10 20 30 40 50

*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st1;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        st1.push(val);
    }

    stack<int> st2; 
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }

    stack<int> st3; 
    while(!st2.empty()){
        st3.push(st2.top());
        st2.pop();
    }

    while(!st3.empty()){
        cout << st3.top() << " ";
        st3.pop();
    }

    cout << endl;

    return 0;
}