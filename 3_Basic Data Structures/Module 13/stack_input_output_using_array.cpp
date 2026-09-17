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