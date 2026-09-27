/*

Take two singly linked lists as input and check if their sizes are same or not.

Input:
2 1 5 3 4 9 -1
1 2 3 4 5 6 -1

Output:
YES

Input:
5 1 4 5 -1
5 1 4 -1

Output:
NO


*/

/*
 * Two lists have the same size when they hold the same number of nodes; the
 * values do not matter. So: read the first list until -1, count it; read the
 * second list the same way, count it; compare the two counts.
 * Example 1: sizes 6 and 6 -> YES.  Example 2: sizes 4 and 3 -> NO.
 */

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // sort/max/min - not used here
#include <string>     // std::string - not used here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// One node of a singly linked list: a value and the address of the next node.
class Node{
    public:            // usable from outside the class
        int val;       // the data
        Node* next;    // next node's address; NULL = last node

    // Constructor, runs on `new Node(x)`. `this->val` = member, `val` = parameter.
    Node(int val){
        this->val = val;     // store the value
        this->next = NULL;   // not linked to anything yet
    }
};

// Append `val` at the end in O(1). `Node* &` = reference to main's pointer,
// so main's own head/tail get updated.
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);   // `new` builds the node on the heap and returns its address
    if(head==NULL){                  // empty list: first and last node at once
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode; // link after the last node...
    tail = newNode;       // ...and make the new node the last one
}

// Walk from head to NULL and add 1 for every node passed.
// Returns the number of nodes (0 for an empty list).
int get_size(Node* head){
    int size = 0;          // counter
    Node* tmp = head;      // walker
    while(tmp!=NULL){      // one pass per node; stops past the last node
        tmp = tmp->next;   // step forward
        size++;            // count the node we just stepped over
    }
    return size;
}

int main(){
    Node* head = NULL;   // first list, empty for now
    Node* tail = NULL;

    // First list: values until the stop sign -1 (not stored).
    int val;
    while(true){                 // loop until `break`
        cin >> val;              // read the next integer (spaces/newlines skipped)
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }
    int size_1 = get_size(head);   // how many nodes in list 1

    // Second list: its own head and tail, filled the same way.
    Node* head2 = NULL;
    Node* tail2 = NULL;

    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head2, tail2, val);
    }
    int size_2 = get_size(head2);   // how many nodes in list 2

    // Only the counts are compared, never the values.
    if(size_1 == size_2){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;   // normal exit
}

