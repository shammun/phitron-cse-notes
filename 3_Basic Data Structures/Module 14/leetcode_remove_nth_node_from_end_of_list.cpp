/*

https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Remove Nth Node From End of List (LeetCode 19) -- a Module 11 practice-day problem

Delete the n-th node counted from the END of the list and return the head.
Example: 1 2 3 4 5, n = 2 -> the 4 goes -> 1 2 3 5.

Idea: count the length first. The n-th node from the end is the node at
position (length - n) from the front, counting from 0. To unlink it, stop at
the node just before it. Removing the first node is a special case, because
there is no node before it: the head itself moves. O(n) time, O(1) memory.

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
// (LeetCode defines ListNode as above and supplies includes and main.)
class Solution {
public:     // callable by the judge
    // Deletes the n-th node from the end; returns the (maybe new) head.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Pass 1: count the nodes.
        int length = 0;
        ListNode* currentNode = head;
        // `while(currentNode)` = "while currentNode is not NULL".
        while(currentNode){
            length++;
            currentNode = currentNode->next;    // '->' = member through a pointer
        }

        // n-th from the end is the first node: move the head forward.
        if(n == length){
            ListNode* toDel = head;     // remember the old head
            head = head->next;          // second node (or NULL) is the new head
            delete toDel;               // free the old head's memory
            return head;
        }

        // Pass 2: the node to delete sits at 0-based position length-n.
        // Stop on the node before it (position length-n-1): the loop starts
        // at position 0 and moves index-1 times.
        ListNode* tmp = head;
        int index = length - n;         // 5 - 2 = 3 in the example (the 4)
        for(int i=1; i<index; i++){     // i = 1 .. index-1
            tmp = tmp->next;
        }
        // tmp is now on position 2 (the 3) in the example.
        // Unlink the node after tmp and free it.
        ListNode* toDelete = tmp->next;
        tmp->next = tmp->next->next;    // 3 now points to 5
        delete toDelete;

        return head;
    }
};