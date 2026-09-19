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

Input: the values of the list, ended by -1.

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

        Node(int val) {
            this->val = val;  
            this->next = NULL; 
        }
};

// Append a value in O(1), because the last node is remembered in `tail`.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = newNode; // or tail = tail->next
}

// Print forward: start at the head and follow `next` until it is NULL.
void print_linked_list(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

// Swap two ints. Both parameters are references, so the change is made in the
// caller's variables and not in two copies that vanish at the closing brace.
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
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
void sort_linked_list(Node* head){
    // Stop at the last node: there is nothing after it left to compare with.
    for(Node* i=head; i->next != NULL; i=i->next){
        // `j` starts at `i->next`, never at the head - everything before `i`
        // is already in its final place.
        for(Node* j=i->next; j!=NULL; j=j->next){
            if(i->val > j->val){
                swap(i->val, j->val);
            }
        }
    }
}

int main(){
    Node* head = NULL;
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
    sort_linked_list(head);
    print_linked_list(head);   // 1 2 4 5 6 8 - sorted, not reversed

    return 0;
}