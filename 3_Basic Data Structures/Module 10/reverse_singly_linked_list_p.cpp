/*

Practice copy of reverse_singly_linked_list.cpp, re-typed from memory.

The functions came out identical to the original. The one difference is in
`main`, and it stops the compiler:

    Node* temp = head;
    reverse_linked_list(head, temp);      // only two arguments

`reverse_linked_list` is declared `(Node* &head, Node* &tail, Node* temp)` and
needs three - "too few arguments to function reverse_linked_list". The two
references are the list ends that the reversal has to update; the third is the
node the current call is standing on. Fix: drop the `temp` line and call
`reverse_linked_list(head, tail, head);`, which starts the walk at the head.

The idea being practised: walk to the last node, make it the new head, and
turn one arrow per node on the way back out. The node in front has to be
reachable at the moment the arrow is turned - in the loop version you save it
in a `next` pointer first, here the untouched `temp->next` plays that part.

*/

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
#include <list>   // std::list - the STL doubly linked list
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

class Node {   // one node: a value plus a link to the next node
    public:   // members below are usable from outside the class
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        Node(int val) {   // constructor: runs on `new Node(x)`
            this->val = val;  // Assign the provided value to the 'val' member.
            this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
        }
};

// Hang a new node after the last node - O(1), because `tail` is already known.
// `Node* &head` = a reference to main's pointer, so main sees head/tail change.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head == NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    
    tail->next = newNode;   // old last node points at the new node
    tail = newNode; // or tail = tail->next
}

void print_linked_list(Node* head){   // print every value from head to the end
    Node* tmp = head;   // walker from the first node
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp-> val << endl;   // one value per line; `tmp-> val` is the same as `tmp->val`
        tmp = tmp->next;   // step one node forward
    }
}

// Prints the values backwards without touching a single arrow - the opposite
// approach to the function below, which rewires the list for real.
void print_reverse(Node* temp){
    if(temp == NULL){   // base case: walked past the last node
        return;   // leave the function now
    }
    print_reverse(temp->next);   // print everything after this node first
    cout << temp->val << endl;   // then this node
}

// Reverse the links themselves. `temp` walks forward with the calls.
void reverse_linked_list(Node* &head, Node* &tail, Node* temp){
    // Base case: the old last node becomes the new head.
    if(temp->next == NULL){   // temp is the old last node
        head = temp;   // it becomes the new first node
        return;   // leave the function now
    }
    // Reverse the rest first. `temp->next` is still untouched when we come
    // back, so it is our saved pointer to the node in front.
    reverse_linked_list(head, tail, temp->next);   // reverse everything after temp first
    // Turn one arrow: the node in front now points back at me...
    temp->next->next = temp;   // the node in front now points back at temp
    // ...and my own forward arrow is cut, so the list has a proper end.
    temp->next = NULL;   // cut temp's old forward arrow
    // The old head ends up as the new tail.
    tail = temp;   // temp is (for now) the last node
}

// main: read the list until -1, print it, reverse it, print it again.
int main(){
    Node* head = NULL;   // first node (none yet: the list starts empty)
    Node* tail = NULL;   // last node (none yet)
    
    int val;   // holds each number as it is read
    while(true){   // repeat until -1
        cin >> val;   // read the next integer (spaces/newlines are skipped)
        if(val == -1){   // -1 ends the input
            break;   // leave the loop
        }
        insert_at_tail(head, tail, val);   // append, keeping input order
    }

    cout << endl;   // an empty line

    cout << "Before reversing: The linked list is :" << endl;   // a heading line
    
    print_linked_list(head);   // one value per line

    // BUG: these two lines are the mistake: `temp` is not needed, and the call
    // is one argument short ("too few arguments"). Fix: replace both lines with
    // `reverse_linked_list(head, tail, head);`.
    Node* temp = head;   // not needed (see BUG above)
    reverse_linked_list(head, temp);   // BUG: only 2 of the 3 arguments - does not compile

    cout << "After reversing: The linked list is :" << endl;   // a heading line
    print_linked_list(head);   // one value per line

    return 0;   // 0 = the program ended normally
}