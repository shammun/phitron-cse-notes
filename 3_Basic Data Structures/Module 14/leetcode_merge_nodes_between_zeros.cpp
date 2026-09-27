/*

https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

Merge Nodes in Between Zeros (LeetCode 2181) -- a Module 11 practice-day problem

The list starts and ends with 0, and zeros split it into groups. Replace
each group by one node holding the group's sum, and drop all the zeros.

Example: 0 3 1 0 4 5 2 0 -> 4 11.

Idea: reuse the existing nodes. `modify` is the node that will hold the
current group's sum (the first node of the group). `nextSum` walks through
the group adding values until it reaches the next 0. Then `modify` gets the
sum and is linked straight to the node after that 0 (the next group's first
node), which cuts out the rest of the group and the zero. O(n), O(1) memory.

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
    ListNode* mergeNodes(ListNode* head) {
        // Skip the leading 0: the first group starts at head->next.
        ListNode* modify = head->next;   // node that will store this group's sum
        ListNode* nextSum = modify;      // walker that adds up the group

        while(nextSum){
            // Add values until the zero that closes this group.
            int sum = 0;
            while(nextSum->val != 0){
                sum = sum + nextSum->val;
                nextSum = nextSum->next;
            }

            // Store the sum in the group's first node.
            modify->val = sum;
            // Step past the zero: nextSum is the next group's first node,
            // or NULL after the final zero (which ends the outer loop).
            nextSum = nextSum->next;
            // Link the sum node straight to it, cutting out the group's
            // other nodes and the zero.
            modify->next = nextSum;
            // The next group's first node will hold the next sum.
            modify = modify->next;
        }
        // The leading 0 is not part of the answer.
        return head->next;
    }
};