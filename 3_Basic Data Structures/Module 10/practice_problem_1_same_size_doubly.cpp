
/*

Take two doubly linked lists as input and check if they are the same or not.

Input:
10 20 30 40 50 -1
10 20 30 40 50 -1

Output:
YES

Input:
10 20 30 40 50 -1
10 20 30 40 -1

Output:
NO

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
    Node* head1 = NULL;
    Node* tail1 = NULL;

    int val;
    while(true){
        cin >> val;
        if(val==-1){
            return;
        }
        insert_at_tail(head1, tail1, val);
    }

    Node* head2 = NULL;
    Node* tail2 = NULL;
    int val2;
    while(tail2){
        cin >> val2;
        if(val2==-1){
            return;
        }
        insert_at_tail(head2, tail2, val2);
    }

    int size1 = get_size(head1);
    int size2 = get_size(head2);
    if(size1 == size2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}