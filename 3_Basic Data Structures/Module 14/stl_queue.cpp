#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        q.push(val);
    }

    cout << q.front() << " " << q.back() << " " << q.size() <<  endl;

    // Always check if the queue is empty or not before using pop() or 
    // using front() or back()

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}