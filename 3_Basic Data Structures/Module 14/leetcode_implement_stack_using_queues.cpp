/*

https://leetcode.com/problems/implement-stack-using-queues/description/

Implement Stack using Queues (LeetCode 225)

Build a Last-In-First-Out stack when the only tool you have is a queue.
A queue hands back the OLDEST value; a stack must hand back the NEWEST one.

Example: push 1, push 2, top() -> 2, pop() -> 2, empty() -> false.

*/

/*
 * Idea
 *
 * Keep every value in one queue `q`, in the order it was pushed. The newest
 * value is then at the BACK of the queue.
 *
 *  - top() is easy: queue has back(), and back() is the newest value.
 *  - pop() is the hard part: a queue can only remove from the front. So the
 *    values are taken off the front one by one and moved to a second queue
 *    `q2`, except the very last one, which is the newest -- that one is
 *    thrown away and returned. Then `q2` (everything else, same order)
 *    becomes the new `q`.
 *
 * Cost: push, top and empty are O(1); pop is O(n) because it moves every value.
 * (The judge supplies the includes and `using namespace std`.)
 */

class MyStack {
public:
    queue<int> q;   // front = oldest value, back = newest value (the stack's top)
    MyStack() {

    }

    // A new value joins the back of the queue: it is the new top. O(1).
    void push(int x) {
        q.push(x);
    }

    // Remove and return the newest value, the one at the back of q.
    int pop() {
        queue<int> q2;
        int val;
        while(!q.empty()){
            // Take the front value off q.
            val = q.front();
            q.pop();
            // If q is empty now, `val` was the last (newest) value: that is
            // the one to remove, so do NOT keep it -- leave the loop.
            if(q.empty()){
                break;
            }
            // Any other value is kept, in the same order, in q2.
            q2.push(val);
        }
        // q2 holds every value except the newest one: it becomes the stack.
        q = q2;
        return val;
    }

    // The top of the stack is the newest value, i.e. the back of the queue.
    int top() {
        return q.back();
    }

    // The stack is empty exactly when the queue is.
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */