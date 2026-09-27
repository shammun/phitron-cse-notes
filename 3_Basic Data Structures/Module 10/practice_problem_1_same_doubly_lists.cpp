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

#include <iostream>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

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

// Append at the end in O(1), because `tail` is remembered.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){        // empty list: the new node is head and tail
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;    // old tail -> new node
    newNode->prev = tail;    // new node -> old tail
    tail = newNode;
}

// Read values until -1 and build a list from them.
// `break;` (not `return;`) leaves only the loop, so the caller carries on.
void input_list(Node* &head, Node* &tail){
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }
}

// Count the nodes by walking from head to the end.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp != NULL){
        size++;
        tmp = tmp->next;
    }
    return size;
}

bool same_list(Node* head1, Node* head2){
    // Step 1: different sizes can never be the same list.
    if(get_size(head1) != get_size(head2)){
        return false;
    }

    // Step 2: walk both lists side by side and compare each pair.
    Node* a = head1;
    Node* b = head2;
    while(a != NULL){          // b becomes NULL in the same round, sizes are equal
        if(a->val != b->val){
            return false;      // the first mismatch settles it
        }
        a = a->next;
        b = b->next;
    }
    return true;               // every position matched
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    input_list(head1, tail1);  // first line
    input_list(head2, tail2);  // second line

    if(same_list(head1, head2)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
