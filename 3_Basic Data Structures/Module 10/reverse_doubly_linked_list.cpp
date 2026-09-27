/*

Reverse a doubly linked list by walking in from both ends and swapping the
values as you go.

Here every node has a `prev` as well as a `next`, and that changes everything.
You can put one pointer `i` on the head and another `j` on the tail, swap the
two values, then step `i` forward and `j` backward. After half a pass the
whole list is reversed. Not a single arrow is rewired - the boxes stay exactly
where they are and only the numbers change places - which is why this is so
much shorter than the singly-list version, where each arrow had to be turned
one at a time.

When to stop is the part worth thinking about:

  * odd length (say 5 nodes): the pointers meet on the middle node, `i == j`,
    and that node has nothing to be swapped with.
  * even length (say 4 nodes): they never land on the same node. After the
    last useful swap they cross, and at that moment `j` is exactly one step to
    the left of `i` - that is `i->prev == j`.

Both tests are needed. With only `i != j` an even-length list runs past the
crossing point and swaps every pair back again, undoing the work.

This is also the answer to Practice Day problem 2 (reverse a doubly linked
list and print it). For `10 20 30 40 -1` it prints 10 20 30 40 and then
40 30 20 10.

Watch out when writing the input loop: it must be `while(true)` with `break;`
when -1 arrives. The first version here had `while(tail)` - `tail` is still
NULL before the first insert, so that loop never ran - and `return;`, which
would have left `main` before anything was printed. The `_p.cpp` copy still
has that mistake.

Input: the values of the list, ended by -1.

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

// Everything from here down to `delete_at_any_position` is the Module 9
// doubly-linked-list toolkit, copied in unchanged so this file can stand on
// its own. The new work starts at `reverse_doubly` near the bottom.
//
// Print forward along `next`; print backward along `prev`. A doubly list can
// do both, and that is the whole reason `prev` exists.
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

// Inserting: the head and tail cases write two arrows, the middle case four.
// An empty list is the special case in both - the new node becomes head and
// tail at once.
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

// Deleting: unlink, then free. In a doubly list the node before the victim is
// reachable through `prev`, so there is no walk when you already hold the
// node - which is why `delete_at_tail` here is O(1), unlike the singly list.
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

// Swap two ints through references, so the caller's values really change.
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


// Reverse the list by swapping values from both ends towards the middle.
//
// `head` and `tail` are references out of habit; they are never assigned here
// because the boxes never move - only the numbers inside them do, so the
// first and last box stay the first and last box.
void reverse_doubly(Node* &head, Node* &tail){
    // The `for` header does three jobs at once: `i` starts at the head and
    // `j` at the tail; the loop runs while they have not met (`i != j`, odd
    // length) and have not crossed (`i->prev != j`, even length); and each
    // round steps `i` one to the right and `j` one to the left.
    //
    // Reading `i->prev` is safe because the two pointers always stop at each
    // other before either can walk off an end - except on an empty list,
    // where `i` starts out NULL and `i->prev` crashes. Guard with
    // `if(head == NULL) return;` if that can happen.
    for(Node *i=head, *j=tail; i!=j && i->prev != j; i=i->next,j=j->prev){
        // Exchange the two ends of the part that is still unreversed.
        swap(i->val, j->val);
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    // Read until -1. `while(true)`, not `while(tail)`: `tail` is NULL before
    // the first insert, so a `while(tail)` loop would never start.
    while(true){
        cin >> val;
        if(val==-1){
            // `break;` leaves only the loop, so the prints below still run.
            // (`return;` here would end the whole program.)
            break;
        }
        insert_at_tail(head, tail, val);
    }

    print_forward(head);   // 10 20 30 40

    reverse_doubly(head, tail);

    print_forward(head);   // 40 30 20 10
    
    return 0;
}