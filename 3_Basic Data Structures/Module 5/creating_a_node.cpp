// A linked list is a chain of "nodes". Each node holds a value and the
// ADDRESS of the next node, so the nodes can sit anywhere in memory and are
// found by following the addresses: a -> b -> c -> NULL.
// This first version builds three nodes as ordinary (static) variables.
// Output:
//   The value of a is: 10
//   The value of b is: 20
//   The value of c is: 30

#include <iostream>  // cout
#include <vector>    // not needed here, kept from the template
#include <algorithm> // not needed here
#include <string>    // not needed here
using namespace std; // lets us drop the std:: prefix

// Node class represents a single element in a linked list.
// A class is a user-made type that groups data together.
class Node {
    public: // members below can be used from outside the class (e.g. from main)
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.
        // Node* means "address of a Node". A class may hold a pointer to its own
        // type (but not a whole Node inside a Node, which would never end).
}; // a class definition ends with a semicolon

int main() { // the program starts running here
    // Step 1: Declare three instances of the Node class to create the linked list.
    // Static nodes
    // (They live on the stack inside main and disappear when main ends.
    // Their val and next start as garbage until we set them.)
    Node a, b, c;

    // Step 2: Assign values to each node.
    // The dot . reaches a member of an object: a.val is the val inside a.
    a.val = 10; // Assign 10 as the value of the first node.
    b.val = 20; // Assign 20 as the value of the second node.
    c.val = 30; // Assign 30 as the value of the third node.

    // Step 3: Link the nodes to form the linked list.
    // &b means "the address of b".
    a.next = &b;  // The 'next' pointer of the first node points to the address of the second node.
    b.next = &c;  // The 'next' pointer of the second node points to the address of the third node.
    c.next = NULL; // The 'next' pointer of the third node is NULL, indicating the end of the list.
    // (NULL is the "points to nothing" address, 0.)


    cout << "The value of a is: " << a.val << endl; // 10, read directly from a
    // a.next is a POINTER, so we use -> (arrow) to reach the member of the node
    // it points to: a.next->val is the val of b.
    cout <<  "The value of b is: " << a.next->val << endl; // 20
    // (*a.next).val is the same as a.next->val
    // (*p means "the object p points at"; the brackets are needed because . binds
    // tighter than *.)
    cout << "The value of c is: " << a.next->next->val << endl; // 30: a -> b -> c
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

    return 0; // program finished successfully
}
