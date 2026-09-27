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

#include <iostream>     // cin, cout, endl
#include <list>         // std::list - the STL doubly linked list
using namespace std;    // write list/cin/cout without std::

int main(){
    list<int> l;        // an empty linked list that holds ints

    int val;            // one input value at a time
    // Read values until -1 and append each one at the back.
    while(true){                // loop forever; `break` is the exit
        cin >> val;             // read the next number (spaces/newlines skipped)
        if(val == -1){          // -1 is the end marker, not a value
            break;
        }
        l.push_back(val);       // add val as a new node at the end, O(1)
    }

    l.sort();     // equal values become neighbours, smallest first (list has its own sort; std::sort needs [] access)
    l.unique();   // drop every value equal to the one before it

    // Range-for walks the list from front to back.
    // `int val` here is a NEW variable local to the loop (it hides the outer val);
    // each pass it holds a copy of the next element.
    for(int val: l){
        cout << val << " ";     // value followed by a space, as the sample output shows
    }

    cout << endl;       // finish the line

    return 0;           // normal exit
}