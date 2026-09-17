#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>


using namespace std;


int main(){
    stack<int> s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // push, pop, top, size, empty -- main 5 functions

    // get the input for stack
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.push(x);
    }

    // Always check whether the stack is empty or not before doing pop and top

    // print the stack
    while(!s.empty()){
    // while(s.empty() == false){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;    
}