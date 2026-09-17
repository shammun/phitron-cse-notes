#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std; 

class myStack{
    public:
        list<int> l; // list uses doubly linked list internally

        void push(int val){
            l.push_back(val); // O(1)
        }

        void pop(){
            l.pop_back(); // O(1)
        }

        int top(){
            return l.back(); // O(1)
        }

        int size(){
            return l.size(); // O(1)
        }

        bool empty(){
            return l.empty(); // O(1)
        }
};


int main(){
    myStack s;

    // get the input for stack
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.push(x);
    }

    // print the stack
    while(s.empty() == false){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;    
}