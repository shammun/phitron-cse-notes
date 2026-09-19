/*

Practice copy of delete_at_any_position.cpp, re-typed from memory.

The one difference from the original: here `delete_at_any_position` takes
`Node* &head` - a reference - instead of `Node* head`. Everything else, and
the output, is the same. The reference costs nothing but is not needed either,
because this function never moves the first node. It would start to matter the
day the function also handled `idx = 0`, since then `head` itself changes.

The rule being practised: stand on the node before the victim, bend the arrow
past it, then delete the box - in that order.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 


class Node {
    public:
        int val;     
        Node* next;  

    Node(int val) {
        this->val = val;  
        this->next = NULL;
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

// Kept from the previous lesson for comparison: removing the first node needs
// no walk at all, only `head = head->next` - O(1) instead of O(n).
void delete_head(Node* &head){
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}

// Remove the node at 0-based index `idx`, by standing on index idx-1.
void delete_at_any_position(Node* &head, int idx){
    Node* tmp = head;
    // Stop one node early: after the loop `tmp` is on index idx-1.
    for(int i=1; i<idx; i++){
        tmp = tmp->next;
    }
    // Save, then relink, then free. Never the other way round.
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;   // the victim's neighbours are joined together
    delete deleteNode;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    int val;
    while(true){
        // -1 ends the input and is not stored.
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    print_linked_list(head);

    delete_at_any_position(head, 2);   // delete the third node (index 2, value 30)

    print_linked_list(head);

    return 0;
}