/*

Practice problem 2: print the linked list in reverse order.

Careful - this file does not do that. What it actually does is sort the list
into ascending order with selection sort. For the input 5 4 8 6 2 1 it prints
1 2 4 5 6 8, while a true reverse would print 1 2 6 8 4 5. Sorting and
reversing only agree on input that happens to arrive in descending order.

The code is left exactly as it was written; the comments below mark the spot.
The real answer is three lines of recursion:

    void print_reverse(Node* node){
        if(node == NULL) return;      // walked past the end: turn back
        print_reverse(node->next);    // print everything after me first
        cout << node->val << endl;    // and only then print me
    }

Each call waits for the rest of the list to finish printing before it prints
its own value, so the values come out last-first. Nothing is rewired and the
list is left alone - which is the difference between *printing* in reverse and
*reversing* the list. Module 10 does the second one.
The working program is practice_problem_2_print_reverse.cpp.

Input: the values of the list, ended by -1.

*/

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // has std::swap too; our own swap below is picked because a plain function beats a template
#include <string>     // std::string - not used here
using namespace std;  // lets us write cout instead of std::cout


// One node of a singly linked list.
class Node {
    public:
        int val;      // the data
        Node* next;   // address of the next node; NULL = last node

        // Constructor, runs on `new Node(x)`: `this->val` is the member,
        // `val` the parameter.
        Node(int val) {
            this->val = val;     // store the value
            this->next = NULL;   // not linked yet
        }
};

// Append a value in O(1), because the last node is remembered in `tail`.
// References (`&`) let the function change main's own head and tail.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new heap node
    if(head == NULL){                // empty list: first and last
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;   // link after the old last node
    tail = newNode; // or tail = tail->next
}

// Print forward: start at the head and follow `next` until it is NULL.
void print_linked_list(Node* head){
    Node* tmp = head;               // walker (copy of head)
    while(tmp != NULL){
        cout << tmp->val << endl;   // one value per line
        tmp = tmp->next;            // next node
    }
}

// Swap two ints. Both parameters are references, so the change is made in the
// caller's variables and not in two copies that vanish at the closing brace.
void swap(int &a, int &b){
    int temp = a;   // keep a's old value
    a = b;          // a gets b
    b = temp;       // b gets a's old value
}

// Selection sort, written with node pointers where an array would use indexes.
//
// `i` is the position being settled and `j` walks over every node after `i`.
// Whenever a later value is smaller, the two values change places, so when the
// inner loop ends `i->val` holds the smallest value in the whole remaining
// part of the list. Then `i` moves on and the next smallest settles behind it.
//
// Only the numbers move: the nodes and their arrows are never touched. That is
// what keeps this short - swapping the nodes themselves would mean rewiring
// several links each time.
//
// Two nested walks, so O(n^2) time and O(1) extra space.
// Trap: `i->next` is read before the first test, so an empty list crashes.
// Tiny trace with 5 4 8: i=5: j=4 swap -> 4 5 8; j=8 no swap. i=5: j=8 no swap.
void sort_linked_list(Node* head){
    // Stop at the last node: there is nothing after it left to compare with.
    for(Node* i=head; i->next != NULL; i=i->next){
        // `j` starts at `i->next`, never at the head - everything before `i`
        // is already in its final place.
        for(Node* j=i->next; j!=NULL; j=j->next){
            if(i->val > j->val){          // a smaller value is further on
                swap(i->val, j->val);     // exchange the two values
            }
        }
    }
}

int main(){
    Node* head = NULL;   // empty list
    Node* tail = NULL;

    int val;
    // Read values until -1; the -1 is only a stop sign and is not stored.
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }
    print_linked_list(head);   // the list as it was typed: 5 4 8 6 2 1
    // This is where a reverse was wanted. What happens instead is a sort.
    // BUG: sorts instead of printing in reverse (5 4 8 6 2 1 -> 1 2 4 5 6 8,
    // expected 1 2 6 8 4 5). Fix: call a recursive print_reverse(head) like
    // the one in the header comment, instead of these two lines.
    sort_linked_list(head);
    print_linked_list(head);   // 1 2 4 5 6 8 - sorted, not reversed

    return 0;
}
