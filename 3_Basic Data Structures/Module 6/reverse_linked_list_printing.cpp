#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

void print_reverse(Node* temp){
    if(temp == NULL){
        return;
    }
    print_reverse(temp->next);
    cout << temp->val << endl;
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

    print_reverse(head);

    return 0;
}