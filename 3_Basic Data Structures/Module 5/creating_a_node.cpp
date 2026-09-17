#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Node class represents a single element in a linked list.
class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.
};

int main() {
    // Step 1: Declare three instances of the Node class to create the linked list.
    // Static nodes
    Node a, b, c;

    // Step 2: Assign values to each node.
    a.val = 10; // Assign 10 as the value of the first node.
    b.val = 20; // Assign 20 as the value of the second node.
    c.val = 30; // Assign 30 as the value of the third node.

    // Step 3: Link the nodes to form the linked list.
    a.next = &b;  // The 'next' pointer of the first node points to the address of the second node.
    b.next = &c;  // The 'next' pointer of the second node points to the address of the third node.
    c.next = NULL; // The 'next' pointer of the third node is NULL, indicating the end of the list.


    cout << "The value of a is: " << a.val << endl; 
    cout <<  "The value of b is: " << a.next->val << endl; 
    // (*a.next).val is the same as a.next->val
    cout << "The value of c is: " << a.next->next->val << endl;
    // (*(*a.next).next).val is the same as a.next->next->val

    // Why is this formatting used?
    // - `Node a, b, c;`: Nodes are declared together because they are part of the same linked list.
    //   This format shows that the nodes are related and belong to the same sequence.
    // - Separate assignments (`a.val = 10;`, etc.) improve clarity by explicitly showing
    //   which value is assigned to which node.
    // - Linking nodes (`a.next = &b;`, etc.) is done on separate lines to make it clear
    //   how the chain (linked list) is formed.
    // - `cout` statements are separated and include explanatory text. This helps beginners
    //   understand not only the value being accessed but also how to traverse the list.

    // Explanation of pointer traversal:
    // - `a.next->val`: Access the 'next' pointer of node `a` to reach node `b`, and then get its value.
    // - `a.next->next->val`: Chain two 'next' pointers starting from `a` to reach node `c` and get its value.
    // - This chaining illustrates how linked list traversal works in C++.

    return 0;
}