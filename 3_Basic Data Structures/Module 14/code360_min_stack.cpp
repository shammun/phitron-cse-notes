/*

https://www.naukri.com/code360/problems/min-stack_3843991?leftPanelTabValue=PROBLEM

Min Stack (Code360)

Same task as LeetCode 155: a stack that also reports its smallest value in
O(1). The Code360 version returns -1 instead of failing when the stack is
empty, and its pop() returns the removed value.

Example: push 3, push 1, getMin() -> 1, pop() -> 1, getMin() -> 3.

*/

/*
 * Idea (same as leetcode_min_stack.cpp)
 *
 * A second stack `min_st` holds the minimums: a pushed value also goes on
 * `min_st` when it is <= the current minimum, and a popped value also leaves
 * `min_st` when it IS the current minimum. The top of `min_st` is then always
 * the smallest value still in `st`.
 */


#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		
		stack<int> st, min_st;   // all values, and the minimums (newest on top)
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			st.push(num);
            // A new minimum (or a tie with it) is also remembered in min_st.
            if (min_st.empty() || min_st.top() >= num) {
				min_st.push(num);
			}
        }
		
		// Function to remove the top element of the stack.
		int pop()
		{
            // Nothing to remove: the problem asks for -1.
            if (st.empty()) {
                return -1;       
			}
            // Write your code here.
            // The value leaving is the current minimum: it leaves min_st too.
            if (st.top() == min_st.top()) {
				min_st.pop();
			}
			// Save the top before popping so it can be returned.
			int val = st.top();
			st.pop();
			return val; 
        }
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if (st.empty()) {
				return -1;
			}
            return st.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            // min_st is empty exactly when st is empty.
            if (min_st.empty()) {
				return -1;
			}
            return min_st.top();   // smallest value still in the stack
		}
};