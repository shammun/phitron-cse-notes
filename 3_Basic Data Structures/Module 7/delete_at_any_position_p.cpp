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

void delete_head(Node* &head){
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void delete_at_any_position(Node* &head, int idx){
    Node* tmp = head;
    for(int i=1; i<idx; i++){
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
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

    print_linked_list(head);

    delete_at_any_position(head, 2);

    print_linked_list(head);

    return 0;
}