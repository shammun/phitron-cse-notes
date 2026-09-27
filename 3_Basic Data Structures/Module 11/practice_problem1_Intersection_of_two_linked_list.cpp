/*

https://leetcode.com/problems/intersection-of-two-linked-lists/

Two singly lists may merge into one shared tail (from some node on, they use
the very same nodes). Return the first shared node, or NULL if they never
meet. Example: A = 4 1 [8 4 5], B = 5 6 1 [8 4 5] -> the node holding 8.

The idea (brute force, fine for the sizes in this course): for every node of
A, walk the whole of B and ask "is this the same node?". We compare the
*addresses* (tempA == tempB), not the values - two different nodes can hold
the same number, like the two 1s above. Time O(n*m), no extra memory.

Picture of the example (the bracketed part is shared, it exists only once in memory):

    A:  4 -> 1 \
                [8 -> 4 -> 5] -> NULL
    B:  5 -> 6 -> 1 /

*/

#include <iostream>     // gives cout (print to the screen) and endl
using namespace std;    // lets us write cout instead of std::cout

// Definition for singly-linked list (this is exactly the struct LeetCode gives you).
// One node = one number plus the address of the node after it.
struct ListNode {
    int val;            // the number stored in this node
    ListNode *next;     // address of the next node; nullptr (NULL) means "this is the last node"
    // Default constructor: ListNode() makes a node with val 0 and no next node.
    // The part after ':' is an initializer list - it sets the members before the body {} runs.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value: new ListNode(8) makes a node holding 8 whose next is nullptr.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node: new ListNode(8, p) links it to p at once.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode puts the answer function inside a class called Solution.
class Solution {
public:     // public: code outside the class (main) is allowed to call this function
    // Receives the head (first node address) of each list; returns the address of the
    // first node the two lists share, or NULL if they share none.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // tempA walks list A one node at a time; we do not move headA itself.
        ListNode* tempA = headA;
        // Outer loop: one pass = one node of A is tested. Stops when tempA falls off the end (NULL).
        while(tempA != NULL){
            // For this node of A, start again at the head of B.
            ListNode* tempB = headB;
            // Inner loop: compare the current A node with every node of B.
            while(tempB != NULL){
                // Same address = the same node = the lists meet here. The
                // outer loop goes through A in order, so this is the first one.
                // Trace on the example: tempA = 4 and 1 never match any B node;
                // tempA = the 8-node matches B's 4th node (the very same 8-node) -> return it.
                if(tempA == tempB){
                    return tempA;   // hand back the shared node's address
                }
                tempB = tempB->next;    // '->' reads a member through a pointer: move to B's next node
            }
            tempA = tempA->next;        // this A node is not shared; try the next one
        }
        return NULL;   // no node of A appears in B, so the lists never meet
    }
};

// Helper function to print a linked list as "4 -> 1 -> 8 -> NULL".
// `head` is a copy of the caller's pointer, so moving it here does not change the caller's list.
void printList(ListNode* head) {
    // Each pass prints one node and moves to the next; stops after the last node.
    while (head != nullptr) {
        cout << head->val << " -> ";    // print this node's number and an arrow
        head = head->next;              // step forward
    }
    cout << "NULL" << endl;     // endl = newline + flush the output
}

int main() {
    // Create common nodes that will serve as the intersection part:
    // Intersection list: 8 -> 4 -> 5
    // `new ListNode(8)` builds a node on the heap (memory that lives until we `delete` it)
    // and gives back its address, which we store in a pointer.
    ListNode* common1 = new ListNode(8);
    ListNode* common2 = new ListNode(4);
    ListNode* common3 = new ListNode(5);
    common1->next = common2;    // 8 -> 4
    common2->next = common3;    // 4 -> 5 (common3->next is already nullptr from the constructor)

    // Create list A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* A1 = new ListNode(4);
    ListNode* A2 = new ListNode(1);
    A1->next = A2;          // 4 -> 1
    A2->next = common1;  // Link to intersection: A's own part ends and joins the shared 8-node

    // Create list B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* B1 = new ListNode(5);
    ListNode* B2 = new ListNode(6);
    ListNode* B3 = new ListNode(1);
    B1->next = B2;          // 5 -> 6
    B2->next = B3;          // 6 -> 1
    B3->next = common1;  // Link to intersection: the SAME 8-node that A points to

    // Print both lists.
    cout << "List A: ";
    printList(A1);      // List A: 4 -> 1 -> 8 -> 4 -> 5 -> NULL
    cout << "List B: ";
    printList(B1);      // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5 -> NULL

    // Find the intersection.
    Solution sol;       // an object of the class, needed to call its member function
    ListNode* intersection = sol.getIntersectionNode(A1, B1);   // expected: the 8-node

    // nullptr means "no node found"; otherwise print the value inside the shared node.
    if(intersection != nullptr) {
        cout << "Intersection at node with value: " << intersection->val << endl;  // prints 8
    } else {
        cout << "No intersection found." << endl;
    }

    // Clean up allocated memory: every `new` should get exactly one `delete`.
    // Note: Since the intersection nodes are shared, they must be deleted only once.
    delete A1;
    delete A2;
    delete B1;
    delete B2;
    delete B3;
    // `delete common1` frees ONLY the 8-node. ListNode has no destructor
    // that follows `next`, so common2 and common3 are NOT freed here (a small memory leak).
    // To free them too you would add: delete common2; delete common3;
    delete common1;
    // (Deleting a shared node twice - once "via A" and once "via B" - would be a crash-prone
    // double delete, which is why the shared nodes are handled separately.)

    return 0;   // 0 tells the operating system the program finished normally
}
