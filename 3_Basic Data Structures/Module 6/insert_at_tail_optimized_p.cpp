#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val = val;
            this->next = next;
        }
};

void insert_at_tail_optimized(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->next = b;

    insert_at_tail_optimized(head, tail, 100);
    insert_at_tail_optimized(head, tail, 200);
    insert_at_tail_optimized(head, tail, 300);
    print_linked_list(head);

    return 0;
}