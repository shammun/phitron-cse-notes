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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        Node(int val) {
            this->val = val;  // Assign the provided value to the 'val' member.
            this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
        }
};

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = newNode; // or tail = tail->next
}

void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp-> val << endl;
        tmp = tmp->next;
    }
}

// Prints the values backwards without touching a single arrow - the opposite
// approach to the function below, which rewires the list for real.
void print_reverse(Node* temp){
    if(temp == NULL){
        return;
    }
    print_reverse(temp->next);
    cout << temp->val << endl;
}

// Reverse the links themselves. `temp` walks forward with the calls.
void reverse_linked_list(Node* &head, Node* &tail, Node* temp){
    // Base case: the old last node becomes the new head.
    if(temp->next == NULL){
        head = temp;
        return;
    }
    // Reverse the rest first. `temp->next` is still untouched when we come
    // back, so it is our saved pointer to the node in front.
    reverse_linked_list(head, tail, temp->next);
    // Turn one arrow: the node in front now points back at me...
    temp->next->next = temp;
    // ...and my own forward arrow is cut, so the list has a proper end.
    temp->next = NULL;
    // The old head ends up as the new tail.
    tail = temp;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    cout << endl;

    cout << "Before reversing: The linked list is :" << endl;
    
    print_linked_list(head);

    // These two lines are the mistake: `temp` is not needed, and the call is
    // one argument short. It should be `reverse_linked_list(head, tail, head);`.
    Node* temp = head;
    reverse_linked_list(head, temp);

    cout << "After reversing: The linked list is :" << endl;
    print_linked_list(head);

    return 0;
}