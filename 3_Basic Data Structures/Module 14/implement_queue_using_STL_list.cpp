#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std; 

class myQueue{
    public:
        list<int> l;

        void push(int val){
            l.push_back(val); // O(1)
        }

        void pop(){
            l.pop_front(); // O(1)
        }

        int front(){ // O(1)
            return l.front();
        }

        int back(){ // O(1)
            return l.back();
        }

        int size(){ // O(1)
            return l.size();
        }

        bool empty(){ // O(1)
            return l.empty();
            // return size == 0;
        }
};

int main(){
    myQueue q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        q.push(val);
    }

    cout << q.front() << " " << q.back() << " " << q.size() <<  endl;

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}