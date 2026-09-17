/*

Take a singly linked list as input and print the middle element. If there are multiple 
values in the middle print both.

Input:
2 4 6 8 10 -1

Output:
6

Input:
1 2 3 4 5 6 -1

Output:
3 4
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
    
    int size = get_size(head);
    cout << size << endl;

    if(size%2 == 0){
        Node* tmp = head;
        for(int i=0; i<(size/2) -1; i++){
            tmp = tmp->next;
        }
        cout << tmp->val << " " << tmp->next->val;
    } else{
        Node* tmp = head;
        for(int i=0; i<(size/2); i++){
            tmp = tmp->next;
        }
        cout << tmp->val;
    }
}