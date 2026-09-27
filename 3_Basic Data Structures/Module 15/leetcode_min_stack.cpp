/*

Min Stack (LeetCode 155)
https://leetcode.com/problems/min-stack/

The problem, in my own words
  Build a stack class that, besides the usual push, pop and top, can also
  tell you the smallest value currently inside it - and every one of the four
  operations must take constant time, O(1). The judge only calls pop, top and
  getMin when the stack is not empty.

Class to write (LeetCode signature)
  MinStack()          makes an empty stack
  void push(int val)  puts val on top
  void pop()          removes the top
  int top()           returns the top
  int getMin()        returns the smallest value in the stack

Input used by the test driver
  q, then q commands: "push x", "pop", "top" or "getMin".

Sample
  push -2, push 0, push -3, getMin -> -3, pop, top -> 0, getMin -> -2

*/

/*
 * The idea: scanning the whole stack for the minimum would be O(n). Instead
 * keep a SECOND stack, `mins`, that grows and shrinks together with the main
 * one. Its top always holds "the smallest value among everything currently
 * in the main stack".
 *
 *   push val -> main gets val; mins gets min(val, old minimum).
 *   pop      -> pop both. The minimum of what is left is now on top of mins,
 *               because it was saved back when that level was the top.
 *
 *   after push -2, 0, -3:   main  -2  0  -3      mins  -2  -2  -3
 *   after pop:              main  -2  0          mins  -2  -2    -> min is -2
 *
 * Note: no #include or main() - LeetCode's hidden code includes the STL,
 * creates a MinStack and calls its functions.
 */

class MinStack {
public:                // everything below can be used from outside the class
    stack<int> st;     // the actual values
    stack<int> mins;   // mins.top() = smallest value in st right now

    // Constructor: runs once when LeetCode creates the MinStack.
    MinStack() {
        // Two empty stacks - nothing else to set up.
    }

    // Put val on top, and record the minimum for this new level.
    void push(int val) {
        st.push(val);
        // The new minimum is val itself, unless an older value is smaller.
        // If mins is empty, || stops early, so mins.top() is never called on an empty stack.
        if(mins.empty() || val < mins.top()){
            mins.push(val);
        }
        else{
            mins.push(mins.top());   // same minimum as before, repeated
        }
    }

    // Remove the top value.
    void pop() {
        // Both stacks always have the same size, so pop them together.
        st.pop();
        mins.pop();
    }

    // Return the top value (without removing it).
    int top() {
        return st.top();
    }

    // Return the smallest value in the stack.
    int getMin() {
        return mins.top();   // O(1): no need to look through st
    }
};
