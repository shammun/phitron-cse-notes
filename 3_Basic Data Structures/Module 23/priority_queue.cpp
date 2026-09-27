
/*

Priority Queue in C++

A priority_queue is a container that always lets you see (top) and remove
(pop) its "best" element first, whatever order the values were pushed in.
Inside it is a binary heap (Module 22), so:
    push  O(log n)    pop  O(log n)    top  O(1)

  priority_queue<int> pq;                                   max-heap: top() is the LARGEST
  priority_queue<int, vector<int>, greater<int>> pq2;       min-heap: top() is the SMALLEST

In the min-heap version the three template arguments are: the type stored
(int), the container the heap lives in (vector<int>), and the comparison
(greater<int>, which flips the order so the smallest value wins).

Output of this program, one value per line:
    30 10 100 100 0 5 10 10 10 3 0

*/

#include<iostream>      // cout, endl
#include <vector>       // vector (the container inside the min-heap)
#include <queue>        // priority_queue (and greater<int> comes along with it)



using namespace std;    // write cout, priority_queue ... without std::

int main(){

    // Maximum Priority Queue

    priority_queue<int> pq;     // default: a max-heap, the largest value is on top
    pq.push(10);                // push adds a value, O(log n)
    pq.push(5);
    pq.push(30);

    cout << pq.top() << endl; // 30   (top() only looks; it does not remove)
    pq.pop();                 // pop() removes the top value (30); it returns nothing
    cout << pq.top() << endl; // 10

    pq.push(100);
    cout << pq.top() << endl; // 100

    pq.push(21);
    cout << pq.top() << endl; // 100 -- it is still 100

    cout << pq.empty() << endl; // 0   (empty() is false; a bool prints as 0 or 1)

    // Minimum Priority Queue

    priority_queue<int, vector<int>, greater<int>> pq2;   // min-heap: smallest on top
    pq2.push(10);
    pq2.push(5);
    pq2.push(30);

    cout << pq2.top() << endl; // 5
    pq2.pop();                 // removes 5; left: 10 30
    cout << pq2.top() << endl; // 10

    pq2.push(100);
    cout << pq2.top() << endl; // 10   (5 was already popped; 10 is the smallest left)

    pq2.push(21);
    cout << pq2.top() << endl; // 10

    pq2.push(3);
    cout << pq2.top() << endl; // 3    (a new smallest value goes straight to the top)

    cout << pq.empty() << endl; // 0   (this asks about pq, the max-heap, again; pq2.empty() was probably meant, also 0)

    return 0;                   // program finished normally
}
