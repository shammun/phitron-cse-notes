/*

Practice Day 01, problem 1: are two doubly linked lists the same?

Read two doubly linked lists (each one is a line of values ended by -1) and
print YES when they hold the same values in the same order, otherwise NO.

Example
input
10 20 30 -1
10 20 30 -1
output
YES

input
10 20 30 -1
30 20 10 -1
output
NO     (same size, but the order differs)

*/

/*
 * The idea: "the same list" means two things, and we check them in order.
 *
 *   1. Same number of nodes. If the sizes differ the answer is NO at once,
 *      no need to look at a single value. (This is all that
 *      practice_problem_1_same_size_doubly.cpp checked.)
 *   2. Same value at every position. Put one pointer on each head and walk
 *      both lists together, one step each per round. The first pair that
 *      differs gives NO. If the walk ends with no difference, it is YES.
 *
 * Because step 1 already made the sizes equal, both pointers reach NULL in
 * the same round, so the walk never reads past the end of either list.
 */

#include <iostream>   // cin (keyboard input) and cout (screen output)
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

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

// Append at the end in O(1), because `tail` is remembered.
// `Node* &head` = a reference to the caller's pointer (not a copy), so the
// function can move main's own head/tail.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new node on the heap; its links start as NULL
    if(head == NULL){        // empty list: the new node is head and tail
        head = newNode;   // the only node is the first node...
        tail = newNode;   // ...and also the last node
        return;   // done - skip the rest of the function
    }
    tail->next = newNode;    // old tail -> new node
    newNode->prev = tail;    // new node -> old tail
    tail = newNode;   // the new node is the last node now
}

// Read values until -1 and build a list from them.
// `break;` (not `return;`) leaves only the loop, so the caller carries on.
void input_list(Node* &head, Node* &tail){
    int val;   // each value read
    while(true){   // repeat until `break`
        cin >> val;   // read the next integer (spaces/newlines are skipped)
        if(val == -1){   // -1 ends this list
            break;   // leave the loop, not the function
        }
        insert_at_tail(head, tail, val);   // append, keeping input order
    }
}

// Count the nodes by walking from head to the end.
int get_size(Node* head){
    int size = 0;   // counter
    Node* tmp = head;   // walker
    while(tmp != NULL){   // stop after walking off the end
        size++;   // count one more node
        tmp = tmp->next;   // step to the next node
    }
    return size;   // the number of nodes
}

// true when both lists hold the same values in the same order.
bool same_list(Node* head1, Node* head2){
    // Step 1: different sizes can never be the same list.
    if(get_size(head1) != get_size(head2)){
        return false;   // sizes differ
    }

    // Step 2: walk both lists side by side and compare each pair.
    Node* a = head1;   // walker on list 1
    Node* b = head2;   // walker on list 2
    while(a != NULL){          // b becomes NULL in the same round, sizes are equal
        if(a->val != b->val){   // values at this position differ?
            return false;      // the first mismatch settles it
        }
        a = a->next;   // both walkers move one node forward
        b = b->next;   // (b moves with a)
    }
    return true;               // every position matched
}

// main: read two lists, print YES if they are the same list, else NO.
int main(){
    Node* head1 = NULL;   // list 1: first node (none yet)
    Node* tail1 = NULL;   // list 1: last node (none yet)
    Node* head2 = NULL;   // list 2: first node (none yet)
    Node* tail2 = NULL;   // list 2: last node (none yet)

    input_list(head1, tail1);  // first line
    input_list(head2, tail2);  // second line

    if(same_list(head1, head2)){   // same size and same values?
        cout << "YES" << endl;   // endl = newline + flush
    }
    else{
        cout << "NO" << endl;   // endl = newline + flush
    }

    return 0;   // 0 = the program ended normally
}
