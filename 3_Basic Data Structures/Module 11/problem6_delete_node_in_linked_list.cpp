/*

https://leetcode.com/problems/delete-node-in-a-linked-list/

You are given ONLY a pointer to a node in the middle of a singly linked list
(never the tail) - not the head. Delete that node's value from the list.
Example: 4 5 1 9, node = the 5  ->  4 1 9.

The idea: we cannot reach the node before it (no head, no back pointer), so we
cannot unhook this node. Instead, make this node become its neighbour: copy the
neighbour's value in, then skip the neighbour. The list looks as if the given
node was removed.

*/

#include <iostream>     // cout and endl
using namespace std;    // write cout instead of std::cout

// Definition for singly-linked list.
struct ListNode {
    int val;            // the number in this node
    ListNode *next;     // address of the next node (nullptr at the end)
    // Default constructor; ": val(0), next(nullptr)" is an initializer list.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value: new ListNode(4) -> node 4, next = nullptr.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// LeetCode's answer class.
class Solution {
public:     // callable from main
    // Deletes a node (except the tail) from the linked list.
    // This function copies the value from the next node into the current node
    // and then bypasses the next node.
    // Returns nothing (void): the list is changed in place.
    void deleteNode(ListNode* node) {
        node->val = node->next->val;        // 4 5 1 9 -> 4 1 1 9 (node now holds 1)
        node->next = node->next->next;      // skip the old 1-node -> 4 1 9
    }
};

// Helper function to print the linked list.
// head is a copy of the caller's pointer, so moving it here is safe.
void printList(ListNode* head) {
    while (head != nullptr) {           // one pass per node
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 4 -> 5 -> 1 -> 9
    // For the LeetCode problem, we're given only a pointer to the node to delete,
    // and it's guaranteed that the node is not the tail.
    // `new` builds each node on the heap and returns its address.
    ListNode* n1 = new ListNode(4);
    ListNode* n2 = new ListNode(5);
    ListNode* n3 = new ListNode(1);
    ListNode* n4 = new ListNode(9);

    // Link them in order.
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    cout << "Original list: ";
    printList(n1);                  // Original list: 4 5 1 9

    // Suppose we want to delete the node with value 5.
    // In this approach, we are given only a pointer to the node to be deleted (n2).
    Solution sol;                   // object to call deleteNode on
    sol.deleteNode(n2);

    // After deletion, the list should become: 4 -> 1 -> 9
    cout << "List after deletion: ";
    printList(n1);                  // List after deletion: 4 1 9

    // Cleanup:
    // Note: In the LeetCode problem, we do not worry about freeing memory.
    // The node that really left the list is the one n3 points to
    // (its value 1 and its link were copied into n2). It is no longer reachable
    // FROM THE LIST, but the variable n3 still holds its address, so `delete n3;`
    // would free it too. This demo simply skips it (a small leak).
    // For simplicity, we'll free the nodes that are still in the list.
    delete n1; // Node with value 4.
    delete n2; // Node now holding value 1 (copied from n3).
    delete n4; // Node with value 9.

    return 0;   // normal exit
}
