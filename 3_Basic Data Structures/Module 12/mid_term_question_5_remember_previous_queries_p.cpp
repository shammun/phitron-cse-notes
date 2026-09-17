/*

Problem Statement

You have a doubly linked list which is empty initially. Then you will be given Q queries. In 
each query you will be given two values X and V.

If X is 0 that means you will insert the value V to the head of the linked list.
If X is 1 then you will insert the value V to the tail of the linked list.
If X is 2 then you will delete the value Vth index of the linked list. Assume that index 
starts from 0. If the index is invalid, then you shouldn't perform the deletion.
After each query you need to print the linked list from both left to right and right to left.
Note: You must use STL List, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 1000;
0 <= X <= 2;
0 <= V <= 10^9
Output Format

For each query print the linked list from left to right and right to left.
Print "L -> " before printing the linked list from left to right.
Print "R -> " before printing the linked list from right to left.

Sample Input 0
4
0 10
1 20
1 30
0 40

Sample Output 0
L -> 10 
R -> 10 
L -> 10 20 
R -> 20 10 
L -> 10 20 30 
R -> 30 20 10 
L -> 40 10 20 30 
R -> 30 20 10 40 

Sample Input 1
9
0 10
2 1
2 0
1 20
0 10
2 2
2 1
2 2
2 0

Sample Output 1
L -> 10 
R -> 10 
L -> 10 
R -> 10 
L -> 
R -> 
L -> 20 
R -> 20 
L -> 10 20 
R -> 20 10 
L -> 10 20 
R -> 20 10 
L -> 10 
R -> 10 
L -> 10 
R -> 10 
L -> 
R -> 

Sample Input 2
11
0 10
2 5
1 20
1 30
0 40
2 0
0 50
2 2
1 60
2 3
2 3

Sample Output 2
L -> 10 
R -> 10 
L -> 10 
R -> 10 
L -> 10 20 
R -> 20 10 
L -> 10 20 30 
R -> 30 20 10 
L -> 40 10 20 30 
R -> 30 20 10 40 
L -> 10 20 30 
R -> 30 20 10 
L -> 50 10 20 30 
R -> 30 20 10 50 
L -> 50 10 30 
R -> 30 10 50 
L -> 50 10 30 60 
R -> 60 30 10 50 
L -> 50 10 30 
R -> 30 10 50 
L -> 50 10 30 
R -> 30 10 50 

Sample Input 3
10
1 4
2 1
0 9
0 10
2 2
1 5
2 0
2 1
2 5
2 2

Sample Output 3
L -> 4 
R -> 4 
L -> 4 
R -> 4 
L -> 9 4 
R -> 4 9 
L -> 10 9 4 
R -> 4 9 10 
L -> 10 9 
R -> 9 10 
L -> 10 9 5 
R -> 5 9 10 
L -> 9 5 
R -> 5 9 
L -> 9 
R -> 9 
L -> 9 
R -> 9 
L -> 9 
R -> 9 

*/

#include <iostream>
#include <list>
using namespace std;

void print_forward(list<int> &l){
    cout << "L -> ";
    for(auto it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void print_backward(list<int> &l){
    cout << "R -> ";
    if(l.empty()){
        cout << endl;
        return;
    }

    // at the last element of the list
    auto it = next(l.begin(), l.size()-1);

    while(true){
        cout << *it << " ";
        if(it == l.begin()){
            break;
        }
        it--;
    }
    cout << endl;
}

void different_queries(list<int> &l, int X, int V){
    if(X == 0){
        l.push_front(V);
    }
    if(X == 1){
        l.push_back(V);
    }
    if(X == 2){
        if(V >= 0 && V < l.size()){
            auto it = l.begin();
            for(int i=0; i<V; i++){
                it++;
            }
            l.erase(it);
        }
    }

    print_forward(l);
    print_backward(l);
}

int main(){
    int Q;
    cin >> Q;
    list<int> l;

    while(Q--){
        int X, V;
        cin >> X >> V;

        different_queries(l, X, V);
    }

    return 0;
}
