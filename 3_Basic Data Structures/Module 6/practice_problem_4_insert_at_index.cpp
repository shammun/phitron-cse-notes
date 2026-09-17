/*

Take a singly linked list as input, then take q queries. In each query 
you will be given an index and value. You need to insert those values in 
the given index and print the linked list. If the index is invalid 
print “Invalid”.

Input:
10 20 30 -1
1 40
5 50
4 50
0 100
7 40
1 110
7 40

Output:
10 40 20 30
Invalid
10 40 20 30 50
100 10 40 20 30 50
Invalid
100 110 10 40 20 30 50
100 110 10 40 20 30 50 40


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

void insert_at_head(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

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

void insert_at_any_index(Node* &head, int idx, int val){
    Node* newNode = new Node(val);
    Node* tmp = head;

    for(int i=1; i<idx; i++){
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
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

void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " " << endl;
        tmp = tmp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while(true){
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    int idx;
    while(cin >> idx >> val){
        int size = get_size(head);
        if(idx < 0 || idx > size){
            cout << "Invalid" << endl;
        }
        if(idx == 0){
            insert_at_head(head, val);
        }
        if(idx == size){
            insert_at_tail(head, tail, val);
        }
        if(idx > 0 && idx < size){
            insert_at_any_index(head, idx, val);
        }
    }

    print_linked_list(head);

    return 0;
}    
    
