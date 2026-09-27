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

/*
 * Idea
 *
 * "The same in the order of removing" means: pop everything out of both and
 * write the values down in the order they come out. A stack gives back the
 * LAST value typed first (LIFO); a queue gives back the FIRST value typed
 * first (FIFO). So a stack filled with 10 20 30 40 50 comes out as
 * 50 40 30 20 10, and it matches a queue only if the queue was filled in the
 * opposite order: 50 40 30 20 10.
 *
 * The check is a walk: compare st.top() with q.front(), pop both, repeat.
 */

#include <iostream>     // cin, cout, endl
#include <stack>        // std::stack (LIFO)
#include <queue>        // std::queue (FIFO)
using namespace std;    // write stack/queue/cout without std::

// st and q are passed BY VALUE: the function works on copies, so popping
// here does not empty the caller's stack and queue.
// Returns true when both give the same values in the same removal order.
bool compareStackQueue(stack<int> st, queue<int> q){
    // Different counts can never give the same removal order. Checking it
    // first also means the loop below never pops an empty queue.
    if(st.size() != q.size()){
        return false;
    }

    // Next value out of the stack is top(); next out of the queue is front().
    while(!st.empty()){
        if(st.top() != q.front()){
            return false;   // one mismatch is enough: stop right here
        }
        // Both matched, so remove them and look at the next pair.
        st.pop();           // stack pop removes the top
        q.pop();            // queue pop removes the front
    }
    // Sample 3: stack gives 50 40 30 20 10, queue gives 50 40 30 20 10 -> YES.

    // Every pair matched.
    return true;
}

int main(){
    // n values pushed onto the stack: the last one typed ends up on top.
    int n;
    cin >> n;           // cin >> skips whitespace and reads one number
    stack<int> st;
    for(int i=0; i<n; i++){     // n passes
        int val;
        cin >> val;
        st.push(val);
    }

    // m values pushed into the queue: the first one typed is at the front.
    int m;
    cin >> m;
    queue<int> q;
    for(int i=0; i<m; i++){     // m passes
        int val;
        cin >> val;
        q.push(val);            // queue push adds at the back
    }

    if(compareStackQueue(st, q)){
        cout << "YES" << endl;  // endl = newline + flush
    } else {
        cout << "NO" << endl;
    }

    return 0;           // normal exit
}