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

/*
 * Idea
 *
 * A queue can only be read from the front, oldest value first, so it cannot
 * reverse itself. A stack can: whatever goes in last comes out first. So the
 * values take a trip through a stack:
 *
 *   q  : 10 20 30 40 50   (front is 10)
 *   st : push them all    (top is 50)
 *   q2 : pop st into q2   (front is 50)
 *
 * Printing q2 from the front gives 50 40 30 20 10.
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

    // Empty the queue into the stack, front value first.
    // After this loop 10 is at the bottom of st and 50 is on top.
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    // Empty the stack into the new queue. The top (50) comes out first, so it
    // becomes the front of q2: the order is now reversed.
    queue<int> q2;
    while(!st.empty()){
        q2.push(st.top());
        st.pop();
    }

    // Print q2 front to back, popping as we go.
    while(!q2.empty()){
        cout << q2.front() << " ";
        q2.pop();
    }

    cout << endl;

    return 0;
}