/*

Problem Statement

You have a doubly linked list which is empty initially. Then you will be given Q queries. In 
each query you will be given two values X and V.

You need to insert the value V at index X. Assume that index starts from 0.
After that for each query you need to print the linked list from left to right and right to left.
If the index is invalid, then print "Invalid".
Note: You must use Doubly Linked List, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 1000;
0 <= X <= 1000;
0 <= V <= 1000
Output Format

For each query print the linked list from left to right and right to left or print "Invalid" 
as asked.
Print "L -> " before printing the linked list from left to right.
Print "R -> " before printing the linked list from right to left.

Sample Input 0
5
1 10
0 10
1 20
3 30
2 30

Sample Output 0
Invalid
L -> 10 
R -> 10 
L -> 10 20 
R -> 20 10 
Invalid
L -> 10 20 30 
R -> 30 20 10 

Sample Input 1
10
0 10
1 20
0 30
1 40
6 50
0 60
4 70
4 80
2 90
1 100

Sample Output 1
L -> 10 
R -> 10 
L -> 10 20 
R -> 20 10 
L -> 30 10 20 
R -> 20 10 30 
L -> 30 40 10 20 
R -> 20 10 40 30 
Invalid
L -> 60 30 40 10 20 
R -> 20 10 40 30 60 
L -> 60 30 40 10 70 20 
R -> 20 70 10 40 30 60 
L -> 60 30 40 10 80 70 20 
R -> 20 70 80 10 40 30 60 
L -> 60 30 90 40 10 80 70 20 
R -> 20 70 80 10 40 90 30 60 
L -> 60 100 30 90 40 10 80 70 20 
R -> 20 70 80 10 40 90 30 100 60 

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

void print_forward(Node* head){
    cout << "L -> ";
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backward(Node* tail){
    cout << "R -> ";
    Node* tmp = tail;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
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
    int size = get_size(head);
    if(pos > size || pos < 0){
        cout << "Invalid" << endl;
        return;
    }

    if(pos==0){
        insert_at_head(head, tail, val);
        print_forward(head);
        print_backward(tail);
        return;
    }

    if(pos == size){
        insert_at_tail(head, tail, val);
        print_forward(head);
        print_backward(tail);
        return;
    }

    Node* tmp = head;
    for(int i=1; i<pos; i++){
        tmp = tmp->next;
    }
    
    Node* newNode = new Node(val);
    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
    print_forward(head);
    print_backward(tail);
}


int main(){
    int Q;
    cin >> Q;

    Node* head = NULL;
    Node* tail = NULL;

    while(Q--){
        int X, V;
        cin >> X >> V;
        insert_at_any_position(head, tail, X, V);
    }

    return 0;
}