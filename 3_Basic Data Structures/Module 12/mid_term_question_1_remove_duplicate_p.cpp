/*

Problem Statement

You will be given a linked list of integer values as input. You need to remove duplicate
values from the linked list and finally print the linked list in ascending order.

Note: You need to solve this using STL List, otherwise you will not get marks.

Input Format

First line will contain the values of the linked list, and will terminate with -1.
Constraints

1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output the final linked list where there will be no duplicate values.
Sample Input 0

1 2 3 4 5 -1
Sample Output 0

1 2 3 4 5
Sample Input 1

1 2 4 2 3 5 1 4 5 2 6 1 -1
Sample Output 1

1 2 3 4 5 6
Sample Input 2

5 5 1 1 2 4 2 4 1 3 5 0 -1
Sample Output 2

0 1 2 3 4 5
Sample Input 3

10 10 10 20 20 20 10 20 -1
Sample Output 3

10 20

*/

/*
 * The idea: the STL `list` already knows how to do both jobs.
 *   sort()   puts equal values next to each other (and in ascending order),
 *   unique() then deletes every value that equals the one right before it.
 * The order of the two calls matters: unique() only looks at neighbours, so
 * on the unsorted list 1 2 1 it would remove nothing.
 * For 5 5 1 1 2 4 2 4 1 3 5 0:  sort -> 0 1 1 1 2 2 3 4 4 5 5 5
 *                               unique -> 0 1 2 3 4 5
 */

// Practice copy of mid_term_question_1_remove_duplicate.cpp: the same code,
// only the list is called `myList`.

#include <iostream>     // cin, cout, endl
#include <list>         // std::list - the STL doubly linked list
using namespace std;    // write list/cin/cout without std::

int main(){
    list<int> myList;   // empty linked list of ints
    int val;            // holds one input value
    // Read values until -1 and append each one at the back.
    while(true){                // repeat until break
        cin >> val;             // read one number
        if(val==-1){            // end marker
            break;
        }
        myList.push_back(val);  // new node at the end, O(1)
    }

    myList.sort();     // equal values become neighbours, smallest first
    myList.unique();   // drop every value equal to the one before it
    // Trace 10 10 10 20 20 20 10 20: sort -> 10 10 10 10 20 20 20 20, unique -> 10 20.

    // Range-for walks the list from front to back.
    // `int val` is a fresh loop variable (hides the outer val) holding a copy of each element.
    for(int val : myList){
        cout << val << " ";
    }
    cout << endl;       // end the output line

    return 0;           // normal exit
}