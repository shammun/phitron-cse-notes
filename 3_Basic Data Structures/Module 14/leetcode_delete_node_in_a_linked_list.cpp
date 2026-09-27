/*

https://leetcode.com/problems/delete-node-in-a-linked-list/description/

Delete Node in a Linked List (LeetCode 237) -- a Module 11 problem, solved again

You get a pointer to a node in the middle of a list, but NOT the head, so
you cannot reach the node before it. Remove that node's value from the list.

Example: list 4 5 1 9, node = the one holding 5 -> list becomes 4 1 9.

Idea: the node itself cannot be unlinked without its previous node. So copy
the NEXT node's value into this node, then unlink the next node instead.
The list now reads as if this node had been removed. O(1).

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// (LeetCode defines ListNode itself, as shown above, and supplies the includes and main.)
class Solution {
public:     // callable by the judge
    // node = pointer to the node to delete (never the tail). Returns nothing.
    void deleteNode(ListNode* node) {
        // Become a copy of the next node (5 -> 1 in the example) ...
        // ('->' reads a member through a pointer.)  List is now 4 1 1 9.
        node->val = node->next->val;
        // ... then skip over that next node, which is now a duplicate.
        // List is now 4 1 9.
        node->next = node->next->next;
    }
};