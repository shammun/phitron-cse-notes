#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node class represents a single element in a linked list.
class Node {
    public:
        int val;     // Value stored in the node (data).
        Node* next;  // Pointer to the next node in the linked list.

        // Constructor for the Node class to initialize 'val' and set 'next' to NULL.
        Node(int val) {
            this->val = val;  // Assign the provided value to the 'val' member.
            this->next = NULL; // Initialize 'next' to NULL, meaning no next node by default.
        }
};

// Main function: Entry point of the program.
int main() {
    // Step 1: Create three nodes using the constructor.
    // Here, the constructor is called with the values 10, 20, and 30 respectively.
    Node a(10), b(20), c(30);

    // Step 2: Link the nodes to form a chain (linked list).
    a.next = &b;  // The 'next' pointer of the first node points to the address of the second node.
    b.next = &c;  // The 'next' pointer of the second node points to the address of the third node.

    // Step 3: Output the values of the nodes to verify the linked list structure.
    cout << "The value of a is: " << a.val << endl; // Output the value of the first node.
    // Access the value of the second node using the 'next' pointer of the first node.
    cout << "The value of b is: " << a.next->val << endl; 
    // Explanation: 'a.next' is a pointer to the second node, and 'a.next->val' accesses its value.

    // Step 4: Demonstrate alternative syntax for accessing the value of the third node.
    // 'a.next->next' points to the third node, and 'a.next->next->val' accesses its value.
    cout << "The value of c is: " << a.next->next->val << endl; 
    // Equivalent expression using dereferencing: (*(*a.next).next).val
    // Explanation: 'a.next' gives the address of the second node, 
    // '*a.next' dereferences it to access the second node itself,
    // and '.next' accesses the pointer to the third node. Finally, '*(*a.next).next' dereferences it.

    // Why this formatting is used:
    // - Constructor usage (`Node(int val)`): Simplifies initialization by combining declaration and assignment.
    //   This is more efficient and cleaner than separately setting `val` and `next`.
    // - Linking nodes (`a.next = &b;`): This explicit assignment makes it clear how nodes are connected.
    // - Pointer traversal: Step-by-step traversal (`a.next->val`, `a.next->next->val`) demonstrates
    //   how linked list elements are accessed using pointers.
    // - Alternative syntax: Showing `(*(*a.next).next).val` helps beginners understand the equivalence
    //   between arrow operator (`->`) and dereferencing with dot operator (`.`).

    return 0; // End of the program.
}
