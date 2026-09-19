/*

Practice copy of reverse_doubly_linked_list.cpp, re-typed from memory.

What is new here: a second way to reverse, `reverse_doubly_1`, which turns the
list around for real instead of moving values about. For every node it swaps
the two pointer fields - `next` becomes `prev` and `prev` becomes `next` - and
then swaps `head` with `tail`. The value-swapping version from the original is
kept as `reverse_doubly_2`, and that is the one `main` calls, so the output is
the same as the original's.

Two things to watch:

  * `reverse_doubly_1` takes `Node* head, Node* tail` *by value*, so its
    closing `swap(head, tail)` only swaps two local copies and `main`'s head
    and tail are left pointing at the wrong ends of the list. It needs
    `Node* &head, Node* &tail`.
  * the `while(tail)` input-loop bug of the original is still here, so this
    file also reads nothing and prints two empty lines.

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

// Everything down to `delete_at_any_position` is the Module 9 doubly-list
// toolkit, unchanged. The two reversal functions are near the bottom.
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

// Swap two ints. Note: this one only matches `int` arguments - see below.
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


// Reversal, approach 1: rewire the list properly. Every node's two arrows
// change places, and the two ends of the list change places with them.
void reverse_doubly_1(Node* head, Node* tail){
    Node* tmp = head;
    while(tmp != NULL){
        // This is the standard library's `swap` from <algorithm>, not the
        // `swap(int&, int&)` above: these arguments are `Node*`, not `int`.
        // After it, the node's `next` holds what used to be its `prev`.
        swap(tmp->next, tmp->prev);
        // Move on through `prev`, because `prev` is now carrying the old
        // `next` - the direction we still have to travel. Using `tmp->next`
        // here would send us straight back the way we came.
        tmp = tmp->prev;
    }
    // The first node is now the last one, so the two ends must trade places
    // too. Except that `head` and `tail` were passed by value, so this swaps
    // two copies and `main` never sees it. `Node* &head, Node* &tail` fixes it.
    swap(head, tail);
}

// Reversal, approach 2: leave every arrow alone and swap the values instead.
// `i` comes in from the head, `j` from the tail; they stop when they meet
// (`i == j`, odd length) or cross (`i->prev == j`, even length). Both tests
// are needed, or an even-length list gets swapped back to where it started.
void reverse_doubly_2(Node* &head, Node* &tail){
    for(Node* i=head, *j=tail; i!=j && i->prev != j; i=i->next, j=j->prev){
        swap(i->val, j->val);
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    // Same bug as the original: `tail` is NULL here, so nothing is ever read.
    // `while(true)` with `break;` on -1 is what was meant.
    while(tail){
        cin >> val;
        if(val==-1){
            return;
        }
        insert_at_tail(head, tail, val);
    }

    print_forward(head);

    // The value-swap version; `reverse_doubly_1` above is left unused.
    reverse_doubly_2(head, tail);

    print_forward(head);
    
    return 0;
}