/*

https://leetcode.com/problems/min-stack/description/

155. Min Stack
Solved
Medium
Topics
Companies
Hint
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.

*/
/*
 * Idea
 *
 * Finding the minimum by scanning the stack would be O(n). Instead keep a
 * second stack `min_st` whose top is always the minimum of everything in `st`.
 *
 *  - push(val): val goes on `st`. If val is a new minimum (or ties the current
 *    one), it also goes on `min_st`.
 *  - pop(): if the value leaving `st` is the current minimum, it leaves
 *    `min_st` too, and the older minimum underneath becomes the answer again.
 *
 *   push -2, 0, -3   st: -2 0 -3   min_st: -2 -3   getMin = -3
 *   pop              st: -2 0      min_st: -2      getMin = -2
 *
 * Every operation is O(1).
 */
// (No #include: LeetCode's hidden code already includes the standard library
//  and `using namespace std;`, so `stack` works directly.)
class MinStack {
public:     // callable by the judge
    stack<int> st, min_st;   // st = all values; min_st = the minimums, newest on top
    // Constructor: nothing to do, both stacks start empty.
    MinStack() {

    }

    // Put val on top; also remember it in min_st if it is a new minimum.
    void push(int val) {
        st.push(val);
        // `>=` and not `>`: a value equal to the minimum is pushed again, so
        // popping one copy still leaves the other copy as the minimum.
        // (min_st.empty() is tested first, so top() is never called on an empty stack.)
        if(min_st.empty() || min_st.top() >= val){
            min_st.push(val);
        }
    }

    // Remove the top value (always called on a non-empty stack).
    void pop() {
        // The value leaving is the current minimum: drop it from min_st too.
        if(st.top() == min_st.top()){
            min_st.pop();
        }
        st.pop();
    }

    // Read the top value.
    int top() {
        return st.top();
    }

    // The top of min_st is the smallest value still in the stack.
    int getMin() {
        return min_st.top();
    }
};