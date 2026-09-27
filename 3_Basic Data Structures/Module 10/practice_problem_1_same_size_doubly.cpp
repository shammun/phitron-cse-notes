
/*

Take two doubly linked lists as input and check if they are the same or not.

Input:
10 20 30 40 50 -1
10 20 30 40 50 -1

Output:
YES

Input:
10 20 30 40 50 -1
10 20 30 40 -1

Output:
NO

*/

/*
 * What this file does: it builds two doubly linked lists from the input and
 * answers YES when they have the same number of nodes.
 *
 * Two things stand between it and the real task:
 *
 *   * it does not even compile: `return;` with no value is not allowed in
 *     `int main` ("return-statement with no value"). And the idea is wrong
 *     too - `return` would leave `main` the moment -1 is read, so nothing
 *     would be printed. `break;` was meant.
 *     The second loop is `while(tail2)`, and `tail2` is NULL at that point,
 *     so it would never read anything even after the first fix; it should
 *     be `while(true)` as well.
 *   * the task asks whether the lists are the *same*, and equal size is only
 *     the first half of that. `10 20 30` and `30 20 10` have the same size
 *     but are different lists. practice_problem_1_same_doubly_lists.cpp
 *     finishes the job: size first, then a value-by-value walk.
 */

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
using namespace std;   // lets us write cout, list ... instead of std::cout, std::list ...

// A doubly linked node: the value, an arrow forward and an arrow back.
class Node {   // one node: a value plus links to the next AND the previous node
    public:   // members below are usable from outside the class
        int val;   // the value this node carries
        Node* next;   // address of the node after this one (NULL = none)
        Node* prev;   // address of the node before this one (NULL = none)

    Node(int val) {   // constructor: runs on `new Node(x)`
        this->val = val;   // `this->val` = the member, plain `val` = the parameter
        this->next = NULL;   // not linked to anything yet
        this->prev = NULL;   // not linked to anything yet
    }
};


// Append at the end. `tail` is kept so this is O(1) instead of a walk.
// `Node* &head` = a reference to the caller's pointer (not a copy), so the
// function can move main's own head/tail.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){          // empty list: the new node is head and tail
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;    // old tail -> new node
    newNode->prev = tail;    // new node -> old tail (the arrow back)
    tail = newNode;          // the new node is the tail now
}

// Count the nodes by walking from head until we fall off the end.
int get_size(Node* head){
    int size = 0;   // counter
    Node* tmp = head;   // walker
    while(tmp!=NULL){   // one pass per node
        tmp = tmp->next;   // step to the next node
        size++;   // count one more node
    }
    return size;   // the number of nodes
}

// main: read two lists and compare their sizes.
int main(){
    Node* head1 = NULL;   // list 1: first node (none yet)
    Node* tail1 = NULL;   // list 1: last node (none yet)

    // First list: read values until -1.
    int val;   // each value of list 1
    while(true){   // repeat until `break`
        cin >> val;   // read the next integer (spaces/newlines are skipped)
        if(val==-1){   // -1 ends list 1
            // BUG: a bare `return;` in `int main` does not compile, and even
            // `return 0;` would end the program here, before the second list is
            // read or anything is printed. Fix: `break;`
            return;   // leave the function now
        }
        insert_at_tail(head1, tail1, val);   // append to list 1
    }

    Node* head2 = NULL;   // list 2: first node (none yet)
    Node* tail2 = NULL;   // list 2: last node (none yet)
    int val2;   // each value of list 2
    // BUG: `tail2` is NULL, so this loop never starts. Fix: `while(true)`.
    while(tail2){
        cin >> val2;   // read the next integer
        if(val2==-1){   // -1 ends list 2
            // BUG: same bare `return;` as above. Fix: `break;`
            return;   // leave the function now
        }
        insert_at_tail(head2, tail2, val2);   // append to list 2
    }

    // Compare only the sizes. For "same list" you would also have to walk
    // both lists together and compare each pair of values.
    int size1 = get_size(head1);   // nodes in list 1
    int size2 = get_size(head2);   // nodes in list 2
    if(size1 == size2){   // only the sizes are compared
        cout << "YES" << endl;   // endl = newline + flush
    }
    else{
        cout << "NO" << endl;   // endl = newline + flush
    }

    return 0;   // 0 = the program ended normally
}