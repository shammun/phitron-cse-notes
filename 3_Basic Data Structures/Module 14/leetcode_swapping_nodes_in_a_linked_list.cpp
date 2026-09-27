/*

https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

Swapping Nodes in a Linked List (LeetCode 1721) -- a Module 11 problem, solved again

Swap the values of the k-th node from the front and the k-th node from the
end (k counts from 1). Example: 1 2 3 4 5, k = 2 -> 1 4 3 2 5.

Idea: count the length. The k-th node from the front is k-1 steps from the
head; the k-th from the end is length-k steps from the head. Walk to both
and swap their VALUES (no relinking needed). O(n) time, O(1) memory.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Count the nodes.
        int length = 0;
        ListNode* currentNode = head;
        while(currentNode){
            length++;
            currentNode = currentNode->next;
        }

        // set the front node: k-1 steps from the head
        ListNode* frontNode = head;
        for(int i=1; i< k; i++){
            frontNode = frontNode->next;
        }

        // set the end node: length-k steps from the head
        ListNode* endNode = head;
        for(int i=1; i<= length-k; i++){
            endNode = endNode->next;
        }

        // Swap only the values; the links stay as they are.
        swap(frontNode->val, endNode->val);
        return head;
    }
};