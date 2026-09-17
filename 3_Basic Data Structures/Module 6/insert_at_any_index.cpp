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



void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp-> val << endl;
        tmp = tmp->next;
    }
}

void insert_at_tail(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* tmp = head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void insert_at_any_index(Node* &head, int idx, int val){
    Node* newNode = new Node(val);
    Node* tmp = head;

    for(int i=1; i<idx; i++){ // starting from 1 makes it sure that we stop at the previous node of the index
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}


int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    
    head->next = a;
    a->next = b;

    insert_at_any_index(head, 2, 1000);
    insert_at_any_index(head, 2, 2000);
    insert_at_any_index(head, 3, 3000);

    print_linked_list(head);


    return 0;
}

/*

Output:
10
20
2000
3000
1000
30

*/