// Queue on the STL `list<int>` (a ready-made doubly linked list).
// A queue is First-In-First-Out: values join at the BACK and leave from the FRONT.
// std::list reaches both ends directly, so every operation below is O(1).

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
#include <list>         // std::list, the storage of our queue
using namespace std;    // write list/cin/cout without std::

// Our own queue class: it only allows push at the back and pop at the front.
class myQueue{
    public:
        list<int> l;    // front of the list = front of the queue

        // push: join the back of the line.
        void push(int val){
            l.push_back(val); // O(1)
        }

        // pop: the front leaves (returns nothing). Only call when not empty.
        void pop(){
            l.pop_front(); // O(1)
        }

        // front: read the oldest value.
        int front(){ // O(1)
            return l.front();
        }

        // back: read the newest value.
        int back(){ // O(1)
            return l.back();
        }

        // size: how many values are waiting.
        int size(){ // O(1)
            return l.size();
        }

        // empty: true when the line is empty; check before front/back/pop.
        bool empty(){ // O(1)
            return l.empty();
            // return size == 0;    // (would need size() with brackets; left as a note)
        }
};

int main(){
    myQueue q;          // an empty queue
    int n;
    cin >> n;           // how many values follow (cin >> skips whitespace)
    for(int i=0; i<n; i++){     // n passes, one value each
        int val;
        cin >> val;
        q.push(val);
    }

    // Oldest, newest, count. Input 4 / 10 20 30 40 prints `10 40 4`.
    cout << q.front() << " " << q.back() << " " << q.size() <<  endl;

    // Drain the queue: values come out in arrival order, 10 20 30 40.
    while(!q.empty()){
        cout << q.front() << endl;  // endl = newline + flush
        q.pop();
    }
    // (No `return 0;` needed: main returns 0 automatically at its end.)
}