/*

Take a singly linked list as input and print the size of the linked list.

Input:
2 1 5 3 4 8 9 -1

Output:
7

Input:
5 1 4 5 -1

Output:
4

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

class Node{
    public:
        int val;
        Node* next;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
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
    cout << get_size(head);

    return 0;
}
