/*

You have a doubly linked list which is empty initially. You need to 
take a value Q which refers to queries. For each query you will be 
given X and V. You will insert the value V to the Xth index of the 
doubly linked list and print the list in both left to right and 
right to left. If the index is invalid then print “Invalid”.

*/

/*

Practice copy of practice_problem_4_insert.cpp, re-typed from memory.

What differs from the original:

  * `insert_at_any_position` names its two parameters `X` and `V`, matching
    the wording of the problem. The code itself is the same.
  * `main` also calls `print_backward(tail)`, so this copy really does print
    the list in both directions, which is what the task asked for. The
    original only printed forward.

What is still wrong, exactly as in the original:

  * `insert_at_tail` is defined twice, so the file does not compile:
    "redefinition of 'void insert_at_tail(Node*&, Node*&, int)'". Delete the
    second copy.
  * `int Q;` is never read, so `while(Q--)` runs on an uninitialised value.
    Add `cin >> Q;` before the loop.

The rule being practised: an index X is legal when 0 <= X <= size. The upper
end is the size itself, because inserting one place past the last element is
how the list grows at the end; on an empty list only X = 0 is legal.

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

// Append at the end: on an empty list the node becomes head and tail at once.
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

// Insert at the front - the mirror image.
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

// The duplicate definition that stops the compiler. Delete it.
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

// Walk the list to count it - O(n), because no size is kept anywhere.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

// Left to right, along `next`.
void print_forward(Node* head){
    Node* tmp = head;
    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Backwards by recursion; works without `prev`, so it suits a singly list.
// Not used here - `print_backward` below is the simpler choice for this list.
void print_reverse(Node* temp){
    if(temp == NULL){
        return;
    }
    print_reverse(temp->next);
    cout << temp->val << endl;
}

// Right to left, along `prev` from the tail.
void print_backward(Node* tail){
    Node* tmp = tail;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

// Insert V at index X. Three cases: the head, the tail, and the middle -
// where four arrows have to be rewritten instead of two.
void insert_at_any_position(Node* &head, Node* &tail, int X, int V){
    Node* newNode = new Node(V);
    if(X == 0){
        insert_at_head(head, tail, V);
        return;
    }
    Node* tmp = head;
    // Stop one node early: `tmp` ends on index X-1.
    for(int i=1; i<X; i++){
        tmp = tmp->next;
    }
    // `tmp` is the last node, so this is really an append.
    if(tmp->next == NULL){
        insert_at_tail(head, tail, V);
        return;
    }
    // The middle case: write the new node's own two arrows first, while
    // `tmp->next` still points at the old right-hand neighbour.
    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int Q;
    // Bug kept from the original: `Q` was never read, so this loop runs on
    // whatever value happened to be in that memory. Add `cin >> Q;` above.
    while(Q--){
        int X, V;
        cin >> X >> V;

        // 0 <= X <= size, and the size is recounted on every query.
        if(X < 0 || X > get_size(head)){
            cout << "Invalid" << endl;
            continue;
        }

        insert_at_any_position(head, tail, X, V);
        // Both directions, as the task asks - this is what the original
        // forgot.
        print_forward(head);
        print_backward(tail);
    }
}


