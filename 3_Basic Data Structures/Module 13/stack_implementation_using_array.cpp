#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;


class myStack{
    public:
        vector<int> v;

        void push(int val){
            v.push_back(val);
        }

        void pop(){
            v.pop_back();
        }

        int top(){
            return v.back();
        }

        int size(){
            return v.size();
        }

        bool empty(){
            return v.empty();
        }
};

int main(){
    myStack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    if(s.empty() == false){
        cout << s.top() << endl;
    }

    // Before doing top and pop, first check 
    // whether the stack is empty or not
    if(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    // print the stack
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}