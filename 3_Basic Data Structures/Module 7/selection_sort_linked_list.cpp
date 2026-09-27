/*

Selection sort on a singly linked list.

Input : values ended by -1.
Output: the list as read (one value per line), then the sorted list.

It is the same algorithm as selection_sort_array.cpp, but with node pointers
in place of indexes: `i` is the node being settled, `j` walks every node
after it, and whenever `j` holds a smaller value the two VALUES are swapped.
The nodes and their `next` arrows never move - only numbers do. O(n^2) time,
O(1) extra space.

Example: 30 10 20 -1
    i on 30: j=10 smaller -> swap -> 10 30 20; j=20 smaller -> swap -> 10 20 30
    i on 20: j=30 not smaller                                       -> 10 20 30

*/

#include <iostream>   // cin and cout
#include <vector>     // std::vector - not used here
#include <algorithm>  // brings in std::swap, which sort_linked_list ends up calling
#include <string>     // std::string - not used here
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node class represents a single element in a linked list.
class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        // Runs on `new Node(x)`; `this->val` is the member, `val` the parameter.
    Node(int val) {
        this->val = val;  // Assign the provided value to the 'val' member.
        this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
    }
};

// Append in O(1) using the remembered tail. `Node* &` = reference, so main's
// own head/tail are updated.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // `new` creates the node on the heap
    if(head == NULL){                // empty list: first and last node
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;   // link after the old last node
    tail = newNode; // or tail = tail->next
}

// Print every value, one per line.
void print_linked_list(Node* head){
    Node* tmp = head;               // walker; head is not moved
    while(tmp != NULL){             // stop after the last node
        cout << tmp-> val << endl;  // endl = newline + flush
        tmp = tmp->next;            // next node
    }
}

// Selection sort by swapping values. `head` by value is fine: no node moves.
// Trap: an empty list crashes (`i->next` read on NULL).
void sort_linked_list(Node* head){
    // i stops on the last node: nothing after it left to compare.
    for(Node* i=head; i->next != NULL; i=i->next){
        // j = every node after i; everything before i is already final.
        for(Node* j=i->next; j!=NULL; j=j->next){
            if(i->val > j-> val){           // a smaller value further on
                // Our own swap is declared further down, so at this point the
                // compiler only knows std::swap (from <algorithm>) - same effect.
                swap(i->val, j->val);
            }
        }
    }
}

// Swap two ints through references (not used by the sort above, see note there).
void swap(int &a, int &b){
    int temp = a;   // keep a's old value
    a = b;          // a gets b
    b = temp;       // b gets a's old value
}

// Main function: Entry point of the program.
int main(){
    Node* head = NULL;   // empty list
    Node* tail = NULL;

    int val;
    // Read values until -1 (a stop sign, not stored).
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    print_linked_list(head);   // as read

    // Left over from the delete lesson; this file has no such function, so it stays commented out.
    // delete_at_any_position(head, 2);

    sort_linked_list(head);    // ascending

    print_linked_list(head);   // sorted

    return 0;
}
