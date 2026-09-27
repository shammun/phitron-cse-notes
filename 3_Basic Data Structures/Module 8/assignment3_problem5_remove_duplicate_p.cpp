/*

Problem Statement

You will be given a singly linked list of integer values as input. You need to remove duplicate 
values from the linked list and finally print the linked list.

The process is, for each node N, traverse from that node and delete all nodes where the values are 
same with N.

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain the values of the singly linked list, and will terminate with -1.
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

1 2 4 3 5 6
Sample Input 2

5 5 1 1 2 4 2 4 1 3 5 0 -1
Sample Output 2

5 1 2 4 3 0
Sample Input 3

10 10 10 20 20 20 10 20 -1
Sample Output 3

10 20

*/


/*
 * Keep the first copy of every value, delete every later copy - exactly as the
 * statement describes: for each node `outer`, walk the rest of the list and
 * delete every node whose value equals outer->val.
 *
 * The walker `inner` always stands one node BEFORE the node it is checking
 * (it looks at inner->next). That is what a deletion in a singly list needs:
 * the node before the victim, so its arrow can be bent past the victim.
 * After a deletion `inner` stays put, because its new `next` is a node that
 * has not been checked yet. Two nested walks: O(n^2), fine for n <= 1000.
 *
 * Practice copy of assignment3_problem5_remove_duplicate.cpp; the if/else
 * inside remove_duplicate is written the other way round, same result.
 *
 * Trace with 1 2 1 1 3:
 *   outer on 1: inner on 1 -> next 2 (keep, step) -> next 1 (delete) -> next 1 (delete)
 *               -> next 3 (keep, step) -> next NULL: stop.       list: 1 2 3
 *   outer on 2: nothing after it equals 2.  outer on 3: nothing after it.
 *   output: 1 2 3
 */

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // sort/max/min - not used here
#include <string>     // std::string - not used here
using namespace std;  // lets us write cout instead of std::cout

// One node of a singly linked list: a value plus the address of the next node.
class Node {
    public:            // usable from outside the class
        int val;       // the data
        Node* next;    // next node's address; NULL for the last node

    // Constructor, runs on `new Node(x)`. `this->val` is the member,
    // plain `val` is the parameter with the same name.
    Node(int val) {
        this->val = val;     // store the value
        this->next = NULL;   // not linked yet
    }
};

// Count the nodes from head to NULL. (Not used in this program.)
int get_size(Node* head){
    int size = 0;          // counter
    Node* tmp = head;      // walker
    while(tmp!=NULL){      // one pass per node
        tmp = tmp->next;   // step over a node...
        size++;            // ...and count it
    }
    return size;   // number of nodes counted
}

// Append at the end by walking to the last node (O(n) per value).
// (`tail` is kept up to date but not used to skip the walk; with n <= 1000
// the O(n^2) total is still fast. `tail->next = newNode;` would be O(1).)
// `Node* &` = reference, so main's own head/tail are updated.
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);   // `new` builds the node on the heap, returns its address
    if(head == NULL){                // empty list: first and last node
        head = newNode;   // the new node is the first node...
        tail = newNode;   // ...and the last node
        return;   // leave the function now
    }
    Node* tmp = head;                // walk to the current last node
    while (tmp->next != NULL){       // stops when tmp has no next, i.e. on the last node
        tmp = tmp->next;   // step to the next node
    }
    tmp->next = newNode;             // hook the new node after it
    tail = newNode;                  // and remember it as the last node
}


// Print the values on one line, separated by spaces, then a newline.
void print_linked_list(Node* head){
    Node* tmp = head;                // walker; head is not moved
    while(tmp != NULL){
        cout << tmp-> val << " ";    // `tmp-> val` is the same as `tmp->val`
        tmp = tmp->next;             // next node
    }
    cout << endl;                    // endl = newline + flush
}

// Delete every later copy of each value, keeping the first one.
// `head` is a reference, though the first node is never deleted (it is
// always the first copy of its value), so a plain copy would also work.
void remove_duplicate(Node* &head){
    Node* outer = head;   // the node whose value we are cleaning out of the rest

    // One pass of this loop = remove every later copy of outer->val.
    while(outer != NULL){
        // `inner` starts on `outer` and inspects the node after it.
        Node* inner = outer;   // start one node before the first node to check
        // Runs until inner is the last node (nothing after it to check).
        while(inner->next != NULL){
            if(inner->next->val == outer->val){
                // A copy: bend inner's arrow past it and free it. `inner` does not move.
                Node* deleteNode = inner->next;    // 1. save the victim
                inner->next = inner->next->next;   // 2. bend the arrow past it
                delete deleteNode;                 // 3. free its memory (`delete` undoes `new`)
            } else{
                // Not a copy of outer->val: step forward.
                inner = inner->next;   // keep this node, move on
            }
        }
        // All later copies of outer->val are gone; move to the next value.
        outer = outer->next;   // next value to clean up
    }
}

int main(){
    Node* head = NULL;   // empty list
    Node* tail = NULL;   // last node (none yet)

    int val;   // holds each number as it is read
    // Read values until -1 (a stop sign, not stored).
    while(true){
        cin >> val;          // next integer; spaces/newlines skipped
        if(val == -1){
            break;   // leave the loop; the -1 is not stored
        }
        insert_at_tail(head, tail, val);   // append at the end, keeping input order
    }

    remove_duplicate(head);     // keep first copies only

    print_linked_list(head);    // e.g. 1 2 4 3 5 6

    return 0;   // normal exit
}

