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

/*
 * The idea: the STL `list` is a ready-made doubly linked list, so each query
 * is one call:
 *   0 V -> push_front(V)
 *   1 V -> push_back(V)
 *   2 V -> delete the element at index V, but only if 0 <= V < size.
 *          A list has no l[V], so an iterator is stepped V times from
 *          begin() and then erased.
 * After every query (even an ignored delete) the list is printed forward
 * and backward.
 */

// Practice copy of mid_term_question_5_remember_previous_queries.cpp: the same code.

#include <iostream>     // cin, cout, endl
#include <list>         // std::list, the STL doubly linked list (also gives next())
using namespace std;    // write list/cout without std::

// Front to back with an iterator.
// An iterator is like a pointer to a list node: begin() = first element, end() = the
// "one past the last" stop marker, *it = the value, it++ = next node.
// The list is passed by reference (&) so it is not copied on every print.
void print_forward(list<int> &l){
    cout << "L -> ";
    // `auto` = let the compiler figure out the type (list<int>::iterator).
    for(auto it=l.begin(); it!=l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// Back to front, starting at the last element.
void print_backward(list<int> &l){
    cout << "R -> ";
    // Empty list: nothing to print, and size()-1 below would go wrong.
    // (size() is unsigned, so 0 - 1 would wrap round to a huge number.)
    if(l.empty()){
        cout << endl;
        return;
    }

    // at the last element of the list
    // next(it, k) returns an iterator k steps after it; size()-1 steps from begin() = last.
    auto it = next(l.begin(), l.size()-1);

    // Print, stop if this was the first element, otherwise step back.
    // (Testing before printing would skip the first element; stepping back from
    //  begin() is not allowed - hence the test in the middle.)
    while(true){
        cout << *it << " ";
        if(it == l.begin()){
            break;
        }
        it--;               // list iterators can move backwards
    }
    cout << endl;
}

// One query: X picks the operation, V is the value (or the index for X == 2).
// After the operation the list is printed both ways.
void different_queries(list<int> &l, int X, int V){
    if(X == 0){
        l.push_front(V);     // add V at the head
    }
    if(X == 1){
        l.push_back(V);      // add V at the tail
    }
    if(X == 2){
        // Only a real index can be erased; otherwise the query does nothing.
        // V >= 0 is checked first, so comparing int V with the unsigned size() is safe.
        if(V >= 0 && V < l.size()){
            auto it = l.begin();
            // Walk the iterator to index V.
            for(int i=0; i<V; i++){     // V steps
                it++;
            }
            l.erase(it);    // remove the node the iterator stands on
            // Example 50 10 20 30, "2 2": it steps to 20 -> erase -> 50 10 30.
        }
    }

    print_forward(l);
    print_backward(l);
}

int main(){
    int Q;              // number of queries
    cin >> Q;           // cin >> skips whitespace and reads one number
    list<int> l;        // empty list to start

    // while(Q--) runs exactly Q times (Q is tested, then decreased).
    while(Q--){
        int X, V;
        cin >> X >> V;  // read the query type and its value

        different_queries(l, X, V);
    }

    return 0;           // normal exit
}
