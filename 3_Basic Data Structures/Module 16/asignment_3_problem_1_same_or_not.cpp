/*

Problem Statement

There is a list of  values that were inserted into a stack and a list of  values that were inserted into a queue. You need to determine whether the stack and queue are the same or not based on the order in which the elements are removed.

Note: You need to solve it using  Stack and Queue only.

Input Format

First line will contain  and .
Second line will contain stack  with  values.
Third line will contain queue  with  values.
Constraints

Output Format

Output YES if they were same, otherwise NO.
Sample Input 0

5 5
10 20 30 40 50
50 40 30 20 10
Sample Output 0

YES
Sample Input 1

4 4
10 20 30 40
10 20 30 40
Sample Output 1

NO
Sample Input 2

5 4
1 2 3 4 5
5 4 3 2
Sample Output 2

NO

*/

/*
 * Idea
 *
 * "Same in the order of removal": a stack gives back its values newest
 * first (LIFO), a queue oldest first (FIFO). So a stack filled with
 * 10 20 30 40 50 comes out as 50 40 30 20 10, and it matches a queue that
 * was filled with 50 40 30 20 10.
 *
 * Fill an STL stack and an STL queue, then pop both together and compare
 * st.top() with q.front() every time. O(n).
 */

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    stack<int> st;
    queue<int> q;

    // The stack gets n values: the last one typed ends up on top.
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        st.push(val);
    }

    // The queue gets m values: the first one typed is at the front.
    for(int i=0; i<m; i++){
        int val;
        cin >> val;
        q.push(val);
    }

    // Different sizes can never give the same removal order. Checking this
    // first also means the loop below never touches an empty queue.
    if(n != m){
        cout << "NO" << endl;
        return 0;
    }

    // Remove from both side by side: the stack gives top(), the queue gives
    // front(). The first pair that differs settles it.
    while(!st.empty()){
        if(st.top() != q.front()){
            cout << "NO" << endl;
            return 0;
        } 
        st.pop();
        q.pop();
    }

    // Every pair matched.
    cout << "YES" << endl;

    return 0;
}