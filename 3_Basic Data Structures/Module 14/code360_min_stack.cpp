/*

https://www.naukri.com/code360/problems/min-stack_3843991?leftPanelTabValue=PROBLEM

*/


#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		
		stack<int> st, min_st;
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
            if (min_st.empty() || min_st.top() >= num) {
				min_st.push(num);
			}
        }
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if (st.empty()) {
                return -1;       
			}
            // Write your code here.
            if (st.top() == min_st.top()) {
				min_st.pop();
			}
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
            if (min_st.empty()) {
				return -1;
			}
            return min_st.top();
		}
};