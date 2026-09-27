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
    the list in both directions, which is what the task asked for. (The first
    version of the original only printed forward; it has since been fixed.)

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

// Reminder: `Node* &head` in a parameter list is a reference to the caller's
// pointer, so a function can move main's own head/tail. `new Node(x)` makes a
// node on the heap and returns its address.

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
using namespace std;   // lets us write cout, list ... instead of std::cout, std::list ...

class Node {   // one node: a value plus links to the next AND the previous node
    public:   // members below are usable from outside the class
        int val;   // the value this node carries
        Node* next;   // address of the node after this one (NULL = none)
        Node* prev;   // address of the node before this one (NULL = none)

    Node(int val) {   // constructor: runs on `new Node(x)`
        this->val = val;   // `this->val` = the member, plain `val` = the parameter
        this->next = NULL;   // not linked to anything yet
        this->prev = NULL;   // not linked to anything yet
    }
};

// Append at the end: on an empty list the node becomes head and tail at once.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;   // old last node points forward to the new node
    newNode->prev = tail;   // new node points back to the old last node
    tail = newNode;   // the new node is the last node now
}

// Insert at the front - the mirror image.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    newNode->next = head;   // new node points forward to the old first node
    head->prev = newNode;   // old first node points back to the new node
    head = newNode;   // the new node is the first node now
}

// BUG: the duplicate definition that stops the compiler ("redefinition of
// 'void insert_at_tail(...)'"). Fix: delete this second copy.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head==NULL){   // empty list?
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;   // old last node points forward to the new node
    newNode->prev = tail;   // new node points back to the old last node
    tail = newNode;   // the new node is the last node now
}

// Walk the list to count it - O(n), because no size is kept anywhere.
int get_size(Node* head){
    int size = 0;   // counter
    Node* tmp = head;   // walker from the first node
    while(tmp!=NULL){   // stop after walking off the end
        tmp = tmp->next;   // step one node forward
        size++;   // count one more node
    }
    return size;   // the number of nodes
}

// Left to right, along `next`.
void print_forward(Node* head){   // print from the first node to the last, on one line
    Node* tmp = head;   // walker from the first node
    while(tmp!=NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->next;   // step one node forward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

// Backwards by recursion; works without `prev`, so it suits a singly list.
// Not used here - `print_backward` below is the simpler choice for this list.
void print_reverse(Node* temp){
    if(temp == NULL){   // base case: walked past the last node
        return;   // leave the function now
    }
    print_reverse(temp->next);   // first print everything after this node (backwards)
    cout << temp->val << endl;   // then this node
}

// Right to left, along `prev` from the tail.
void print_backward(Node* tail){   // print from the last node back to the first, on one line
    Node* tmp = tail;   // walker, starting at the last node
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->prev;   // step one node backward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

// Insert V at index X. Three cases: the head, the tail, and the middle -
// where four arrows have to be rewritten instead of two.
void insert_at_any_position(Node* &head, Node* &tail, int X, int V){
    Node* newNode = new Node(V);   // new node on the heap; its links start as NULL
    if(X == 0){   // index 0 has no node before it
        insert_at_head(head, tail, V);   // index 0 = an insert at the head
        return;   // leave the function now
    }
    Node* tmp = head;   // walker from the first node
    // Stop one node early: `tmp` ends on index X-1.
    for(int i=1; i<X; i++){   // X-1 steps
        tmp = tmp->next;   // step one node forward
    }
    // `tmp` is the last node, so this is really an append.
    if(tmp->next == NULL){   // tmp is the last node?
        insert_at_tail(head, tail, V);   // then this is really an append
        return;   // leave the function now
    }
    // The middle case: write the new node's own two arrows first, while
    // `tmp->next` still points at the old right-hand neighbour.
    newNode->next = tmp->next;   // new node points forward to the old next node
    tmp->next->prev = newNode;   // old next node points back to the new node
    tmp->next = newNode;   // node before points forward to the new node
    newNode->prev = tmp;   // new node points back to the node before
}

// main: read Q queries "X V"; insert V at index X if legal, then print
// the list both ways; otherwise print Invalid.
int main(){
    Node* head = NULL;   // first node (none yet: the list starts empty)
    Node* tail = NULL;   // last node (none yet)

    int Q;   // number of queries
    // BUG: `Q` is never read, so this loop runs on whatever value happened
    // to be in that memory (undefined behaviour). Fix: add `cin >> Q;` above.
    while(Q--){
        int X, V;   // X = index to insert at, V = value
        cin >> X >> V;   // read both numbers of this query

        // 0 <= X <= size, and the size is recounted on every query.
        if(X < 0 || X > get_size(head)){   // `||` = OR: index outside 0..size?
            cout << "Invalid" << endl;   // endl = newline + flush
            continue;   // skip the insert, go to the next query
        }

        insert_at_any_position(head, tail, X, V);   // X is legal: insert
        // Both directions, as the task asks - this is what the original
        // forgot.
        print_forward(head);   // left to right
        print_backward(tail);   // right to left
    }
}


