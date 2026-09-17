#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 

class Node {
    public:
        int val;     
        Node* next;
        Node* prev;

    Node(int val) {
        this->val = val; 
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_forward(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backward(Node* tail){
    Node* tmp = tail;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    Node* newNode = new Node(val);
    if(pos==0){
        insert_at_head(head, tail, val);
        return;
    }
    Node* tmp = head;
    for(int i=1; i<pos; i++){
        tmp = tmp->next;
    }
    if(tmp->next == NULL){
        insert_at_tail(head, tail, val);
        return;
    }
    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}

void delete_at_head(Node* &head, Node* & tail){
    if(head==NULL){
        return;
    }
    if(head->next == NULL){
        delete head;
        // head = NULL; 
        // setting head = NULL is not needed after we delete the head, it will be automatically 
        // null but setting head to NULL is a good practice and it will make the code more 
        // readable there is no harm in setting head to NULL after deleting the head
        
        tail = NULL;
        return;
    }
    Node* deleteNode = head;
    head = head->next;
    head->prev = NULL;
    delete deleteNode;
}

void delete_at_tail(Node* &head, Node* &tail){
    Node* deleteNode = tail;
    if(head == tail){
        delete deleteNode;
        head = NULL;
        tail = NULL; // this line is not necessary because tail will be 
        //automatically null after deleting the tail
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
    delete deleteNode;
}

void delete_at_any_position(Node* &head, Node* &tail, int pos){
    if(pos == 0){
        delete_at_head(head, tail);
        return;
    }
    Node* tmp = head;
    for(int i=1; i<pos; i++){
        tmp = tmp->next;
    }
    if(tmp->next == NULL){
        delete_at_tail(head, tail);
        return;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete deleteNode;
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    print_forward(head); // 10 20 30
    // print_backward(tail);

    insert_at_tail(head, tail, 100);

    print_forward(head); // 10 20 30 100

    insert_at_tail(head, tail, 100); //  10 20 30 100 100

    print_forward(head);

    insert_at_any_position(head, tail, 2, 200); // 10 20 200 30 100 100

    print_forward(head);

    insert_at_any_position(head, tail, 0, 300); // 300 10 20 200 30 100 100

    print_forward(head);

    insert_at_any_position(head, tail, 5, 400); // 300 10 20 200 30 400 100 100

    print_forward(head);

    delete_at_head(head, tail); // 10 20 200 30 400 100 100

    print_forward(head); // 10 20 200 30 400 100 100

    delete_at_head(head, tail); // 20 200 30 400 100 100

    print_forward(head); // 20 200 30 400 100 100

    delete_at_tail(head, tail); // 20 200 30 400 100

    print_forward(head); // 20 200 30 400 100

    delete_at_tail(head, tail); // 20 200 30 400

    print_forward(head); // 20 200 30 400

    delete_at_tail(head, tail); // 20 200 30

    print_forward(head); // 20 200 30

    delete_at_any_position(head, tail, 2); // 20 200

    print_forward(head); // 20 200

    insert_at_any_position(head, tail, 1, 300); // 20 300 200

    print_forward(head); // 20 300 200

    insert_at_any_position(head, tail, 1, 400); // 20 400 300 200

    print_forward(head); // 20 400 300 200

    delete_at_any_position(head, tail, 2); // 20 400 200
    
    return 0;
}