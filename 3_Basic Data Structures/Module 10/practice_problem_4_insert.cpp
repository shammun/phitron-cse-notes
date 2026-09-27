/*

You have a doubly linked list which is empty initially. You need to 
take a value Q which refers to queries. For each query you will be 
given X and V. You will insert the value V to the Xth index of the 
doubly linked list and print the list in both left to right and 
right to left. If the index is invalid then print “Invalid”.

*/

/*

How it is solved: keep a doubly linked list, start it empty, and for each
query `X V` first ask whether X is a legal index and only then insert.

"Legal" means 0 <= X <= size. The upper end is `size`, not `size-1`, because
inserting one step past the last element is exactly how a list grows at the
end. On an empty list, therefore, only X = 0 is legal.

After each successful insert the list is printed twice: left to right from
`head` along `next`, then right to left from `tail` along `prev`. The second
line must be the exact mirror of the first; if it is not, a `prev` arrow was
written wrong.

Three mistakes from the first version are fixed here (the `_p.cpp` copy still
has the first two): `insert_at_tail` was defined twice, which C++ rejects
("redefinition of ..."); `Q` was never read, so `while(Q--)` ran on garbage;
and only the forward print was called.

Input: Q, then Q lines of `X V`.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 

// A doubly linked node: the value, an arrow forward and an arrow back.
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

// Append at the end. On an empty list the new node is both head and tail;
// otherwise two arrows are written - old tail -> new, and new -> old tail.
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

// Insert at the front, the mirror image of the above.
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

// Count the nodes by walking the whole list - O(n) every time it is called.
// It is needed because the list keeps no size counter of its own.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

// Print left to right, following `next`.
void print_forward(Node* head){
    Node* tmp = head;
    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Print backwards by recursion: print everything after me first, then me.
// It works on a singly list too, since it never uses `prev`. Not called here.
void print_reverse(Node* temp){
    if(temp == NULL){
        return;
    }
    print_reverse(temp->next);
    cout << temp->val << endl;
}

// Print right to left the easy way, following `prev` from the tail.
void print_backward(Node* tail){
    Node* tmp = tail;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

// Insert `val` so that it ends up at 0-based index `pos`. Three cases:
//     pos == 0      -> it becomes the new head
//     pos == size   -> it becomes the new tail
//     in between    -> it goes between two existing nodes, and then *four*
//                      arrows have to be written, not two.
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    Node* newNode = new Node(val);
    // Note that `newNode` above is already allocated, and on the two
    // shortcut paths below it is never linked to anything - the helpers make
    // their own node. Harmless here, but it is a small memory leak.
    if(pos==0){
        insert_at_head(head, tail, val);
        return;
    }
    Node* tmp = head;
    // The same "stop one node early" walk as deleting: after this loop `tmp`
    // stands on index pos-1, the node the new one has to come after.
    for(int i=1; i<pos; i++){
        tmp = tmp->next;
    }
    // `tmp` turned out to be the last node, so this insert is an append.
    if(tmp->next == NULL){
        insert_at_tail(head, tail, val);
        return;
    }
    // The middle case. Four links, and the order matters: the new node's own
    // two arrows are written first, while `tmp->next` still points at the old
    // right-hand neighbour. Overwrite `tmp->next` too early and that
    // neighbour is unreachable.
    newNode->next = tmp->next;        // new -> right neighbour
    tmp->next->prev = newNode;        // right neighbour -> new
    tmp->next = newNode;             // left neighbour -> new
    newNode->prev = tmp;            // new -> left neighbour
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int Q;
    cin >> Q;   // without this, `while(Q--)` would test an uninitialised value
    // `Q--` tests Q, then decreases it: the loop runs exactly Q times.
    while(Q--){
        int X, V;
        cin >> X >> V;

        // Reject the index before touching the list. `X == size` is allowed
        // on purpose - that is an append. Each check walks the list, so a
        // query costs O(n).
        if(X < 0 || X > get_size(head)){
            cout << "Invalid" << endl;
            continue;      // skip the insert, go straight to the next query
        }

        insert_at_any_position(head, tail, X, V);
        // The task wants both directions.
        print_forward(head);
        print_backward(tail);
    }
}


