/*

You have a doubly linked list which is empty initially. You need to 
take a value Q which refers to queries. For each query you will be 
given X and V. You will insert the value V to the Xth index of the 
doubly linked list and print the list in both left to right and 
right to left. If the index is invalid then print “Invalid”.

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
        Node* prev;

    Node(int val) {
        this->val = val; 
        this->next = NULL;
        this->prev = NULL;
    }
};

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

int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

void print_forward(Node* head){
    Node* tmp = head;
    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_reverse(Node* temp){
    if(temp == NULL){
        return;
    }
    print_reverse(temp->next);
    cout << temp->val << endl;
}

void print_backward(Node* tail){
    Node* tmp = tail;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void insert_at_any_position(Node* &head, Node* &tail, int X, int V){
    Node* newNode = new Node(V);
    if(X == 0){
        insert_at_head(head, tail, V);
        return;
    }
    Node* tmp = head;
    for(int i=1; i<X; i++){
        tmp = tmp->next;
    }
    if(tmp->next == NULL){
        insert_at_tail(head, tail, V);
        return;
    }
    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int Q;
    while(Q--){
        int X, V;
        cin >> X >> V;

        if(X < 0 || X > get_size(head)){
            cout << "Invalid" << endl;
            continue;
        }

        insert_at_any_position(head, tail, X, V);
        print_forward(head);
        print_backward(tail);
    }
}


