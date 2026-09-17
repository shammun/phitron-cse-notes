/*

Take a queue of size N as input. You need to copy those elements in another queue 
in reverse order. You might use stack here. You should use STL to solve this problem. 
After copying in another queue, print the elements of that queue.

Input
5
10 20 30 40 50

Output
50 40 30 20 10

*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    // Input size of queue
    int n;
    cin >> n;

    queue<int> q;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        q.push(val);
    }

    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    queue<int> q2;
    while(!st.empty()){
        q2.push(st.top());
        st.pop();
    }

    while(!q2.empty()){
        cout << q2.front() << " ";
        q2.pop();
    }

    cout << endl;

    return 0;
}