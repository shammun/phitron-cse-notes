/*

Problem Statement

You need to take a doubly linked list of integer value as input. You need to tell if the 
doubly linked list forms a palindrome or not.

Note: You need to solve this using Doubly Linked List, otherwise you will not get marks.

Input Format
Input will contain the values of the doubly linked list, and will terminate with -1.

Constraints
1 <= N <= 10^6; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output "YES" if it forms a palindrom otherwise output "NO".

Sample Input 0
1 2 3 2 1 -1

Sample Output 0
YES

Sample Input 1
1 2 2 1 -1

Sample Output 1
YES

Sample Input 2
1 -1

Sample Output 2
YES

Sample Input 3
1 2 3 1 -1

Sample Output 3
NO

*/

/*
 * The idea: a doubly linked list can be read from both ends at once. Put `i`
 * on the head and `j` on the tail, compare their values, then move `i`
 * forward and `j` backward. One different pair means NO.
 *
 * When to stop:
 *   odd length  (1 2 3 2 1): the two pointers land on the same middle node,
 *                            `i == j`, and a node always equals itself;
 *   even length (1 2 2 1)  : they never land on the same node - they cross,
 *                            and right after crossing `i->prev == j`.
 * Without the second test an even list would walk right off both ends.
 */

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)
using namespace std;    // write cin/cout without std::

// One node of a DOUBLY linked list: a value plus arrows both ways.
class Node {
    public:             // members usable from outside the class
        int val;        // the number stored
        Node* next;     // right neighbour (NULL at the tail)
        Node* prev;     // left neighbour (NULL at the head)

    // Constructor, runs on `new Node(val)`. `this` points to the node being built;
    // this->val is the member, plain val is the parameter with the same name.
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// Append at the end in O(1), because `tail` is remembered.
// `Node* &head` = reference to main's pointer, so main's head/tail get updated.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);  // `new` makes the node on the heap
    if(head==NULL){                 // empty list: node is head and tail
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;           // old tail -> new
    newNode->prev = tail;           // old tail <- new
    tail = newNode;                 // new tail
}

// Returns true if the values read the same from both ends.
bool is_palindrome(Node* head, Node* tail){
    bool flag = true;   // a palindrome until a mismatch is found
    // A for loop with TWO variables: `Node *i=head, *j=tail` declares both (each needs
    // its own *), and `i=i->next, j=j->prev` moves both each pass (the comma runs
    // both steps). Keep going while they have not met (i != j) and not crossed
    // (i->prev != j). A single-node list stops at once because i == j.
    for(Node *i=head, *j=tail; i!=j && i->prev != j; i=i->next, j=j->prev){
        // Compare the two mirror positions.
        if(i->val != j->val){
            flag = false;   // one mismatch is enough
            break;          // leave the loop early
        }
    }
    // Trace 1 2 3 1: (i,j) = (1,1) equal; (2,3) differ -> NO.
    // Trace 1 2 2 1: (1,1), (2,2) equal; then i = 2nd 2, j = 1st 2 -> i->prev == j -> stop, YES.
    return flag;
}

int main(){
    Node* head1 = NULL;     // empty list to start
    Node* tail1 = NULL;

    int val;
    // Read values until -1.
    while(true){                // repeat until break
        cin >> val;             // read one number (whitespace skipped)
        if(val==-1){            // end marker
            break;
        }
        insert_at_tail(head1, tail1, val);
    }

    bool result = is_palindrome(head1, tail1);

    if(result){                 // true -> palindrome
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;                   // normal exit
}
