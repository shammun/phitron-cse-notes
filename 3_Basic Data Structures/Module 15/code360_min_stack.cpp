/*

Min Stack (Code360)
https://www.naukri.com/code360/problems/min-stack_3843991

The problem, in my own words
  Same idea as LeetCode's Min Stack, but with Code360's rules: build a class
  `minStack` where every operation is O(1) and an empty stack is not an
  error - it answers -1.
    push(num)   put num on top
    pop()       remove the top and RETURN it; -1 if the stack is empty
    top()       return the top; -1 if empty
    getMin()    return the smallest value in the stack; -1 if empty

Input used by the test driver
  q, then q commands: "push x", "pop", "top" or "getMin".

Sample
  push 5, push 3, push 3, push 7, getMin -> 3, pop -> 7, pop -> 3,
  getMin -> 3, pop -> 3, getMin -> 5

*/

/*
 * The idea: a second stack `mins` remembers the minimums - but, unlike the
 * LeetCode version in this folder, it only gets a value when that value is a
 * NEW minimum or TIES the current one (num <= mins.top()). Values bigger than
 * the minimum never change it, so there is no need to store anything for them.
 *
 *   push 5, 3, 3, 7:   st   5 3 3 7        mins  5 3 3      (7 is skipped)
 *   pop -> 7:          7 != mins.top(), mins is untouched  -> min still 3
 *   pop -> 3:          3 == mins.top(), pop mins too       -> min still 3
 *   pop -> 3:          pop mins again                      -> min is 5
 *
 * The "<=" (not "<") matters: both 3s are recorded, so popping one 3 leaves
 * the other 3 as the minimum. With "<" the second 3 would not be recorded and
 * the first pop of a 3 would wrongly make 5 the minimum.
 *
 * Note: no #include or main() - the judge's hidden code includes <stack>,
 * creates a minStack and calls its functions.
 */

class minStack
{
    // Private members (class default): only minStack's own functions use them.
    stack<int> st;     // all values
    stack<int> mins;   // only the values that were a minimum when pushed

public:                // the functions below can be called by the judge
    // Constructor: runs when a minStack is created.
    minStack()
    {
        // two empty stacks - nothing to set up
    }

    // Put num on top; also record it in mins if it is a (tied) minimum.
    void push(int num)
    {
        st.push(num);                 // every value goes into the main stack
        // Record num only if it is a new minimum or equals the current one.
        // mins.empty() is checked first: if mins is empty, || stops there and
        // mins.top() (which would be invalid on an empty stack) is never called.
        if(mins.empty() || num <= mins.top()){
            mins.push(num);
        }
    }

    // Remove the top value and return it; -1 if the stack is empty.
    int pop()
    {
        if(st.empty()){
            return -1;                // nothing to pop
        }
        int val = st.top();        // read it before it is removed
        st.pop();                  // remove it from the main stack
        // If the value leaving is the current minimum, its record leaves too.
        // (mins is never empty here: the first value pushed always went into mins.)
        if(val == mins.top()){
            mins.pop();
        }
        return val;                // the value that was removed
    }

    // The top value without removing it; -1 if empty.
    int top()
    {
        if(st.empty()){
            return -1;
        }
        return st.top();
    }

    // Smallest value currently in the stack: always on top of mins. -1 if empty.
    int getMin()
    {
        if(mins.empty()){
            return -1;
        }
        return mins.top();
    }
};
