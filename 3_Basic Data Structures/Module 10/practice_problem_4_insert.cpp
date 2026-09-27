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

// Reminder: `Node* &head` in a parameter list is a reference to the caller's
// pointer, so a function can move main's own head/tail. `new Node(x)` makes a
// node on the heap and returns its address.

#include <iostream>   // cin (keyboard input) and cout (screen output)
#include <vector>   // std::vector (a resizable array) - not used in this file
#include <algorithm>   // sort, reverse, swap, max, min ... - not used in this file
#include <string>   // std::string - not used in this file
using namespace std;   // lets us write cout, list ... instead of std::cout, std::list ...

// A doubly linked node: the value, an arrow forward and an arrow back.
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

// Append at the end. On an empty list the new node is both head and tail;
// otherwise two arrows are written - old tail -> new, and new -> old tail.
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

// Insert at the front, the mirror image of the above.
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

// Count the nodes by walking the whole list - O(n) every time it is called.
// It is needed because the list keeps no size counter of its own.
int get_size(Node* head){
    int size = 0;   // counter
    Node* tmp = head;   // walker from the first node
    while(tmp!=NULL){   // stop after walking off the end
        tmp = tmp->next;   // step one node forward
        size++;   // count one more node
    }
    return size;   // the number of nodes
}

// Print left to right, following `next`.
void print_forward(Node* head){   // print from the first node to the last, on one line
    Node* tmp = head;   // walker from the first node
    while(tmp!=NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->next;   // step one node forward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

// Print backwards by recursion: print everything after me first, then me.
// It works on a singly list too, since it never uses `prev`. Not called here.
void print_reverse(Node* temp){
    if(temp == NULL){   // base case: walked past the last node
        return;   // leave the function now
    }
    print_reverse(temp->next);   // first print everything after this node (backwards)
    cout << temp->val << endl;   // then this node
}

// Print right to left the easy way, following `prev` from the tail.
void print_backward(Node* tail){   // print from the last node back to the first, on one line
    Node* tmp = tail;   // walker, starting at the last node
    while(tmp != NULL){   // stop after walking off the end
        cout << tmp->val << " ";   // print this node's value and a space
        tmp = tmp->prev;   // step one node backward
    }
    cout << endl;   // end the line (endl = newline + flush)
}

// Insert `val` so that it ends up at 0-based index `pos`. Three cases:
//     pos == 0      -> it becomes the new head
//     pos == size   -> it becomes the new tail
//     in between    -> it goes between two existing nodes, and then *four*
//                      arrows have to be written, not two.
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    // Note that `newNode` above is already allocated, and on the two
    // shortcut paths below it is never linked to anything - the helpers make
    // their own node. Harmless here, but it is a small memory leak.
    if(pos==0){   // index 0 has no node before it
        insert_at_head(head, tail, val);   // index 0 = an insert at the head
        return;   // leave the function now
    }
    Node* tmp = head;   // walker from the first node
    // The same "stop one node early" walk as deleting: after this loop `tmp`
    // stands on index pos-1, the node the new one has to come after.
    for(int i=1; i<pos; i++){   // pos-1 steps
        tmp = tmp->next;   // step one node forward
    }
    // `tmp` turned out to be the last node, so this insert is an append.
    if(tmp->next == NULL){   // tmp is the last node?
        insert_at_tail(head, tail, val);   // then this is really an append
        return;   // leave the function now
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

// main: read Q queries "X V"; insert V at index X if legal, then print
// the list both ways; otherwise print Invalid.
int main(){
    Node* head = NULL;   // first node (none yet: the list starts empty)
    Node* tail = NULL;   // last node (none yet)

    int Q;   // number of queries
    cin >> Q;   // without this, `while(Q--)` would test an uninitialised value
    // `Q--` tests Q, then decreases it: the loop runs exactly Q times.
    while(Q--){
        int X, V;   // X = index to insert at, V = value
        cin >> X >> V;   // read both numbers of this query

        // Reject the index before touching the list. `X == size` is allowed
        // on purpose - that is an append. Each check walks the list, so a
        // query costs O(n).
        if(X < 0 || X > get_size(head)){   // `||` = OR: index outside 0..size?
            cout << "Invalid" << endl;   // endl = newline + flush
            continue;      // skip the insert, go straight to the next query
        }

        insert_at_any_position(head, tail, X, V);   // X is legal: insert
        // The task wants both directions.
        print_forward(head);   // left to right
        print_backward(tail);   // right to left
    }
}


