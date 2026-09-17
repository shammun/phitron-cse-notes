
/*

Priority Queue in C++

*/

#include<iostream>
#include <vector>
#include <queue>



using namespace std;

int main(){
    
    // Maximum Priority Queue

    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(30);

    cout << pq.top() << endl; // 30
    pq.pop();
    cout << pq.top() << endl; // 10

    pq.push(100);
    cout << pq.top() << endl; // 100

    pq.push(21);
    cout << pq.top() << endl; // 100 -- it is still 100

    cout << pq.empty() << endl; // 0

    // Minimum Priority Queue

    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(10);
    pq2.push(5);
    pq2.push(30);

    cout << pq2.top() << endl; // 5
    pq2.pop();
    cout << pq2.top() << endl; // 10

    pq2.push(100);
    cout << pq2.top() << endl; // 5

    pq2.push(21);
    cout << pq2.top() << endl; // 5

    pq2.push(3);
    cout << pq2.top() << endl; // 3

    cout << pq.empty() << endl; // 0

    return 0;
}