/*

Take a stack of size N and a queue of size M as input. Then check if both of them are 
the same or not in the order of removing. You should use STL to solve this problem.

Input
5
10 20 30 40 50
5
10 20 30 40 50

Output
NO

Input
5
10 20 30 40 50
4
10 20 30 40

Output
NO

Input
5
10 20 30 40 50
5
50 40 30 20 10

Output
YES

*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool compareStackQueue(stack<int> st, queue<int> q){
    if(st.size() != q.size()){
        return false;
    }

    while(!st.empty()){
        if(st.top() != q.front()){
            return false;
        }
        st.pop();
        q.pop();
    }

    return true;
}

int main(){
    int n;
    cin >> n;
    stack<int> st;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        st.push(val);
    }

    int m;
    cin >> m;
    queue<int> q;
    for(int i=0; i<m; i++){
        int val;
        cin >> val;
        q.push(val);
    }

    if(compareStackQueue(st, q)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}