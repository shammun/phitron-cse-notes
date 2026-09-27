/*

https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908

Implement a Queue (Code360 - Queue Using Array or Singly Linked List)
Write a class `Queue` for whole numbers with four operations:
  isEmpty()      -> true when the queue holds nothing
  enqueue(x)     -> add x at the back
  dequeue()      -> remove the front value and return it; -1 if empty
  front()        -> return the front value without removing it; -1 if empty
The judge creates one Queue and calls these functions; you only write the
class.

Example
enqueue 5, enqueue 7, front() -> 5, dequeue() -> 5, front() -> 7,
dequeue() -> 7, isEmpty() -> true, dequeue() -> -1

*/

/*
 * Idea: this time use the ARRAY option of the problem (Module 14 used a
 * linked list).
 *
 * A queue adds at the back and removes from the front. Adding at the back of
 * a vector is cheap (`push_back`), but erasing its first element is not:
 * every other element would shift left, O(n).
 *
 * So we never erase. Instead we remember in `f` the index of the current
 * front. Removing the front just moves `f` one step right; the old value
 * stays in the vector but is no longer part of the queue.
 *
 *   enqueue 5, enqueue 7:   v = [5, 7]       f = 0   queue is 5 7
 *   dequeue -> 5:           v = [5, 7]       f = 1   queue is 7
 *
 * The queue is the part v[f .. end], so it is empty when f reaches v.size().
 * Every operation is O(1). The cost: removed values still take memory. That
 * is fine here, because the judge only makes a limited number of calls.
 */

#include <bits/stdc++.h>
using namespace std;

class Queue {
    vector<int> v;   // every value ever enqueued, in arrival order
    int f;           // index of the current front inside v

public:
    Queue() {
        f = 0;       // nothing removed yet, so the front is index 0
    }

    bool isEmpty() {
        // Everything before f was already removed; nothing left from f on.
        return f == (int)v.size();
    }

    void enqueue(int data) {
        v.push_back(data);   // new values join at the back
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;       // the problem asks for -1 on an empty queue
        }
        int data = v[f];     // the value leaving the queue
        f++;                 // the next value becomes the front
        return data;
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }
        return v[f];         // look, don't remove
    }
};
