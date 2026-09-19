/*

https://leetcode.com/problems/implement-queue-using-stacks/description/

Implement Queue using Stacks (LeetCode 232)

Build a First-In-First-Out queue using only stacks. A stack hands back the
newest value; a queue must hand back the oldest one. The two rules are exact
opposites, and that is the whole puzzle.

The trick is that pouring one stack into another reverses it, so the value
that was at the bottom ends up on top. This file uses one stack `st` to hold
the values and a temporary stack inside pop() and peek() to reach the bottom.

Cost: push and empty are O(1); pop and peek are O(n), because they touch every
value twice (out and back). When you build one structure out of another, one
operation always pays for the mismatch.

This is a re-typed practice copy of leetcode_implement_queue_using_stacks.cpp;
only the indentation differs.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class MyQueue {
    public:
        // One stack holds everything. Its TOP is the newest value, so its
        // BOTTOM is the oldest -- and the bottom is what a queue wants.
        stack<int> st;
        MyQueue(){

        }

        // Newest value goes on top of the stack. Nothing else to do: O(1).
        void push(int x){
            st.push(x);
        }

        // Remove and return the oldest value, i.e. the bottom of `st`.
        int pop(){
            stack<int> st2;
            int val;
            // Take values off the top one at a time. `val` always holds the
            // one just taken, so when `st` runs empty, `val` is the bottom
            // value -- the oldest, the one the queue must return.
            while(!st.empty()){
                val = st.top();
                st.pop();
                // The break happens AFTER st.pop() and BEFORE st2.push(val),
                // so the oldest value is removed and never put aside. That
                // is exactly what "pop from the front" means here.
                if(st.empty()){
                    break;
                }
                st2.push(val);
            }

            // Pour st2 back. That is a second reversal, so the remaining
            // values return to the order they were in before.
            while(!st2.empty()){
                st.push(st2.top());
                st2.pop();
            }

            return val;
        }

        // Same walk, but the oldest value is only read, not removed.
        int peek(){
            stack<int> st3;
            int val;
            // No break this time: everything, including the bottom value,
            // is moved into st3. `val` ends up as the last one taken.
            while(!st.empty()){
                val = st.top();
                st.pop();
                st3.push(val);
            }

            // Pour it all back so the queue is unchanged.
            while(!st3.empty()){
                st.push(st3.top());
                st3.pop();
            }
            return val;
        }

        // The queue is empty exactly when the stack is. This is also the
        // guard the caller needs: pop() and peek() read `val` without ever
        // assigning it when `st` starts out empty.
        bool empty(){
            return st.empty();
        }
};
