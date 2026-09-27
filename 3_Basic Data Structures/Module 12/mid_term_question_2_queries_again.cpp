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

/*
 * The idea: this is Module 9's "insert at any position" in a doubly linked
 * list, plus one check before it.
 *
 *   * A legal index is 0..size. `size` itself is allowed because inserting
 *     just after the last node is how a list grows; anything else is Invalid.
 *   * pos == 0     -> insert_at_head
 *     pos == size  -> insert_at_tail
 *     otherwise    -> walk to the node just before `pos` and write the four
 *                     arrows of a middle insert.
 *   * After every successful insert, print left-to-right from `head` along
 *     `next`, then right-to-left from `tail` along `prev`. The R line must be
 *     the exact mirror of the L line; if it is not, a `prev` arrow is wrong.
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

// Left to right, following `next` from the head.
void print_forward(Node* head){
    cout << "L -> ";
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Right to left, following `prev` from the tail.
void print_backward(Node* tail){
    cout << "R -> ";
    Node* tmp = tail;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

// Count the nodes; needed to know which indexes are legal.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

// New first node: two arrows between it and the old head.
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

// New last node: two arrows between the old tail and it.
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
    // Reject the index before touching the list.
    if(pos > size || pos < 0){
        cout << "Invalid" << endl;
        return;
    }

    if(pos==0){
        insert_at_head(head, tail, val);   // new first node
        print_forward(head);
        print_backward(tail);
        return;
    }

    if(pos == size){
        insert_at_tail(head, tail, val);   // new last node
        print_forward(head);
        print_backward(tail);
        return;
    }

    Node* tmp = head;
    // Stop one node early: tmp ends on index pos-1, the node before the gap.
    for(int i=1; i<pos; i++){
        tmp = tmp->next;
    }
    
    Node* newNode = new Node(val);
    // Four arrows. The new node's own two first, while tmp->next still
    // points at the right-hand neighbour.
    newNode->next = tmp->next;         // new -> right neighbour
    tmp->next->prev = newNode;         // right neighbour -> new
    tmp->next = newNode;               // left neighbour (tmp) -> new
    newNode->prev = tmp;               // new -> left neighbour
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
        cin >> X >> V;     // insert value V at index X
        insert_at_any_position(head, tail, X, V);
    }

    return 0;
}