/*

https://leetcode.com/problems/implement-queue-using-stacks/description/

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> st2;
        int val;
        while(!st.empty()){
            val = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            st2.push(val);
        }

        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return val;
    }
    
    int peek() {
        stack<int> st3;
        int val;
        while(!st.empty()){
            val = st.top();
            st.pop();
            st3.push(val);
        }

        while(!st3.empty()){
            st.push(st3.top());
            st3.pop();
        }
        return val;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */