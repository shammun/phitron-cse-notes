/*

https://leetcode.com/problems/linked-list-cycle/description/

Linked List Cycle (LeetCode 141) -- a Module 11 problem, solved again

Does the list loop back on itself (some node's next points to an earlier
node)? Example: 3 2 0 -4 with -4 pointing back to 2 -> true.

Idea (fast and slow pointers): `slow` moves one node per step, `fast` two.
Without a loop, `fast` reaches the end (NULL). With a loop, both end up
going round it, and `fast` gains one node per step, so it must land on
`slow` at some point. O(n) time, O(1) memory.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;   // becomes true if the pointers meet

        // fast needs two more nodes to jump; checking fast first protects
        // fast->next from being read on NULL.
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            // They met: only possible inside a loop.
            if(slow == fast){
                flag= true;
                break;
            }
        }
        return flag;
    }
};