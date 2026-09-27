/*

https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

Remove Duplicates from Sorted List (LeetCode 83) -- a Module 11 problem, solved again

The list is sorted, so equal values sit next to each other. Keep one copy of
each value. Example: 1 1 2 3 3 -> 1 2 3.

Idea: compare each node with the node after it. If they are equal, unlink
the next node (and compare again, since there may be a third copy). If not,
move on. O(n) time, O(1) memory.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while(temp!= NULL && temp->next!=NULL){
            if(temp->val == temp->next->val){
                // Duplicate: skip the next node. Stay on temp, because the
                // new next may be yet another copy.
                temp->next = temp->next->next;
            } else{
                // Different value: temp is done, move forward.
                temp = temp->next;
            }
        }
        return head;
    }
};