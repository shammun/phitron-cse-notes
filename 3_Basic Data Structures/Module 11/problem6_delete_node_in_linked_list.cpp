/*

https://leetcode.com/problems/delete-node-in-a-linked-list/

*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    // Default constructor.
    ListNode() : val(0), next(nullptr) {}
    // Constructor with a value.
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with a value and a pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Deletes a node (except the tail) from the linked list.
    // This function copies the value from the next node into the current node
    // and then bypasses the next node.
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// Helper function to print the linked list.
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 4 -> 5 -> 1 -> 9
    // For the LeetCode problem, we're given only a pointer to the node to delete,
    // and it's guaranteed that the node is not the tail.
    ListNode* n1 = new ListNode(4);
    ListNode* n2 = new ListNode(5);
    ListNode* n3 = new ListNode(1);
    ListNode* n4 = new ListNode(9);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    
    cout << "Original list: ";
    printList(n1);
    
    // Suppose we want to delete the node with value 5.
    // In this approach, we are given only a pointer to the node to be deleted (n2).
    Solution sol;
    sol.deleteNode(n2);
    
    // After deletion, the list should become: 4 -> 1 -> 9
    cout << "List after deletion: ";
    printList(n1);
    
    // Cleanup:
    // Note: In the LeetCode problem, we do not worry about freeing memory.
    // However, in this demonstration, we have an orphaned node (originally n3)
    // whose memory is not directly accessible after deletion because its value
    // and pointer have been copied into n2.
    // For simplicity, we'll free the nodes that are still accessible.
    delete n1; // Node with value 4.
    delete n2; // Node now holding value 1 (copied from n3).
    delete n4; // Node with value 9.
    
    return 0;
}
