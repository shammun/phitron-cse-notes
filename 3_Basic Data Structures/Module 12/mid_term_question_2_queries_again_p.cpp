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

// Practice copy of mid_term_question_2_queries_again.cpp. Two differences:
// the labels are `L -->` / `R -->` (the judge wants `L -> ` / `R -> `), and
// `insert_at_head` has the wrong body (see the note above it).

#include <iostream>     // cin, cout, endl
#include <vector>       // not used here (template leftover)
#include <algorithm>    // not used here (template leftover)
#include <string>       // not used here (template leftover)

using namespace std;    // write cin/cout without std::

// One node of a DOUBLY linked list: a value plus arrows both ways.
class Node{
    public:             // accessible from outside the class
        int val;        // the number stored
        Node* next;     // right neighbour (NULL at the tail)
        Node* prev;     // left neighbour (NULL at the head)

        // Constructor, runs on `new Node(val)`. this->val is the member; plain val is
        // the parameter (same name, so `this->` is needed to tell them apart).
        Node(int val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

// Left to right, following `next` from the head.
void print_forward(Node* head){
    cout << "L --> ";           // (judge expects "L -> ", see note at the top)
    Node* tmp = head;           // walker
    while(tmp != NULL){         // one pass per node
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Right to left, following `prev` from the tail.
void print_backward(Node* tail){
    cout << "R --> ";           // (judge expects "R -> ")
    Node* tmp = tail;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;        // step left
    }
    cout << endl;
}

// Count the nodes; needed to know which indexes are legal.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp != NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

// BUG: the body below is the tail-insert body, so a value
// meant for index 0 is appended at the end. It should be
//     newNode->next = head; head->prev = newNode; head = newNode;
// (Sample 1 query "0 30" on list 10 20 prints 10 20 30 instead of 30 10 20.)
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);  // node on the heap
    if(head == NULL){           // empty list: this part is correct
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;       // BUG: links after the TAIL, not before the head
    newNode->prev = tail;
    tail = newNode;
}

// New last node: two arrows between the old tail and it.
// `Node* &head` = reference to main's pointer, so main sees the change.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;       // old tail -> new
    newNode->prev = tail;       // old tail <- new
    tail = newNode;             // new tail
}

// One query: insert val at index pos and print, or print Invalid.
void insert_at_any_position(Node* &head, Node* &tail, int pos, int val){
    int size = get_size(head);
    // Reject the index before touching the list. Legal indexes: 0..size.
    if(pos < 0 || pos > size){
        cout << "Invalid" << endl;
        return;
    }

    if(pos == 0){
        insert_at_head(head, tail, val);   // new first node (buggy here, see above)
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
    // Four arrows. The first two read tmp->next (the right-hand neighbour), so they
    // must run before line 3 overwrites tmp->next.
    newNode->next = tmp->next;         // new -> right neighbour
    tmp->next->prev = newNode;         // right neighbour -> new
    tmp->next = newNode;               // left neighbour (tmp) -> new
    newNode->prev = tmp;               // new -> left neighbour
    print_forward(head);
    print_backward(tail);
    return;                            // (not needed at the end of a void function)
}

int main(){
    int Q;              // number of queries
    cin >> Q;

    Node* head = NULL;  // empty list
    Node* tail = NULL;

    // Runs Q times: Q is tested, then decreased.
    while(Q--){
        int X, V;
        cin >> X >> V;     // insert value V at index X
        insert_at_any_position(head, tail, X, V);
    }

    return 0;           // normal exit
}