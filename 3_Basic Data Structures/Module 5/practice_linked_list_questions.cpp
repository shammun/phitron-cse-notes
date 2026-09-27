/*
 * Practice: questions about a linked list drawn in memory.
 *
 * The module's exercise sheet draws six nodes. Each box shows the node's value
 * and the address stored in its `next`, and under each box is the node's own
 * address:
 *
 *   address:   500       1000      1050      2000       ?        3000
 *            [5|1000] -> [7|1050] -> [1|2000] -> [14|1020] -> [3|3000] -> [11|NULL]
 *
 * Answers to the written questions, in my own words:
 *
 * a) Why does a linked list use more memory than an array for the same values?
 *    Every node stores the value AND a pointer to the next node. An array
 *    stores only the values, side by side, so it needs no pointers.
 *
 * b) Three array limits that a linked list removes:
 *    1. An array's size is fixed when it is created; a list grows one node at
 *       a time with `new`.
 *    2. Inserting in the middle of an array shifts every later element; in a
 *       list you only change two `next` pointers.
 *    3. Deleting from an array also shifts elements to close the gap; in a
 *       list you just link around the removed node.
 *    (An array also needs one big block of free memory in a row; list nodes
 *    can live anywhere.)
 *
 * c) Head holds the address of the first node: 500.
 *
 * d) The "?" node's address is whatever the node before it points to. The
 *    node at 2000 has next = 1020, so "?" is 1020.
 *
 * e) Head->next->next->val: 500 -> 1000 -> 1050, and the node at 1050 holds 1.
 *
 * f) The pseudocode adds values while temp->next is not 1020, then subtracts
 *    the value of the node where it stopped. The program below runs it.
 *
 * We cannot choose real addresses in C++, so the program builds the same six
 * nodes with `new` and uses the pointer `q` (the node "at 1020") wherever the
 * sheet compares with address 1020.
 *
 * Output:
 *   Head->next->next->val = 1
 *   Sum = -1
 */

#include <iostream> // cout
using namespace std; // lets us drop the std:: prefix

// The same node the module builds: a value and a pointer to the next node.
class Node {
    public: // usable from main()
        int val; // the data stored in this node
        Node* next; // address of the next node (NULL at the end)

        // Constructor: runs on every new Node(x). `this` points at the node being
        // built; this->val is the member, plain val is the parameter.
        Node(int val) {
            this->val = val; // store the value
            this->next = NULL;   // no next node until we link one
        }
};

int main() { // the program starts running here
    // Create the six nodes on the heap.
    // new Node(x) makes a node with value x and returns its address.
    Node* head = new Node(5);    // the node at "500"
    Node* a = new Node(7);       // "1000"
    Node* b = new Node(1);       // "1050"
    Node* c = new Node(14);      // "2000"
    Node* q = new Node(3);       // "?" = "1020"
    Node* d = new Node(11);      // "3000"

    // Link them in the drawn order. The last node keeps next = NULL.
    // p->next is short for (*p).next.
    head->next = a; // 5 -> 7
    a->next = b; // 7 -> 1
    b->next = c; // 1 -> 14
    c->next = q; // 14 -> 3
    q->next = d; // 3 -> 11

    // Question e: two hops from head, then read the value.
    cout << "Head->next->next->val = " << head->next->next->val << endl; // 1

    // Question f: follow the pseudocode step by step.
    int sum = 0; // running total
    Node* temp = head; // walker pointer, starts at the first node
    // Stop when the NEXT node is q; comparing pointers compares addresses.
    while(temp->next != q){      // "while temp->next != 1020"
        sum += temp->val;        // adds 5, then 7, then 1
        temp = temp->next; // step to the next node
    }
    // The loop stops at the node whose next is q: the node holding 14.
    // Its value was never added, and now it is taken away.
    sum -= temp->val;            // 13 - 14
    // sum is now -1.

    cout << "Sum = " << sum << endl; // prints Sum = -1

    // (The nodes are never deleted; the operating system frees them when the
    // program ends.)
    return 0; // program finished successfully
}
