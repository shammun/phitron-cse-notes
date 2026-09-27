/*

Practice copy of selection_sort_linked_list.cpp, re-typed from memory - same code.

Selection sort on a singly linked list: `i` is the node being settled, `j`
walks every node after it, and whenever `j` holds a smaller value the two
VALUES swap. The nodes and arrows never move. O(n^2) time, O(1) extra space.

Input : values ended by -1.
Output: the list as read (one per line), then sorted ascending (one per line).
Example: 30 10 20 -1  ->  30 10 20, then 10 20 30.

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
        // `this->val` is the member, `val` the parameter.
    Node(int val) {
        this->val = val;  // Assign the provided value to the 'val' member.
        this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
    }
};

// Append in O(1) using the remembered tail; references update main's pointers.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // heap node
    if(head == NULL){                // empty list
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;   // link after the last node
    tail = newNode; // or tail = tail->next
}

// Print every value, one per line.
void print_linked_list(Node* head){
    Node* tmp = head;               // walker
    while(tmp != NULL){
        cout << tmp-> val << endl;  // endl = newline + flush
        tmp = tmp->next;
    }
}

// Selection sort by swapping values. Crashes on an empty list (`i->next` on NULL).
void sort_linked_list(Node* head){
    // i stops on the last node.
    for(Node* i=head; i->next != NULL; i=i->next){
        // j = every node after i.
        for(Node* j=i->next; j != NULL; j=j->next){
            if(i->val > j->val){
                // Our own swap is declared below, so this calls std::swap - same effect.
                swap(i->val, j->val);
            }
        }
    }
}



// Swap two ints through references (the sort above uses std::swap instead).
void swap(int &a, int &b){
    int temp = a;   // keep a
    a = b;          // a gets b
    b = temp;       // b gets old a
}

// Main function: Entry point of the program.
int main(){
    Node* head = NULL;   // empty list
    Node* tail = NULL;

    int val;
    // Read until -1 (not stored).
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }

    print_linked_list(head);   // as read

    // Left over from the delete lesson; no such function here, so it stays off.
    // delete_at_any_position(head, 2);

    sort_linked_list(head);    // ascending

    print_linked_list(head);   // sorted

    return 0;
}
