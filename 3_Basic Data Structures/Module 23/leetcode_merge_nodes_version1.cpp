/*

https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
/*
 * Task in short: the list starts and ends with 0, with more 0s in between.
 * Replace every run of values between two 0s by one node holding their sum,
 * and drop all the 0s. Example: 0 3 1 0 4 5 2 0 -> 4 11.
 *
 * Idea: reuse the existing nodes instead of making new ones.
 * `nextSum` runs ahead and adds up one block; `modify` is the first node of
 * that block, which gets overwritten with the sum and is then linked
 * straight to the first node of the next block (skipping the rest).
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // head is always a 0, so the first block starts at head->next.
        ListNode* modify = head->next;
        ListNode* nextSum = modify;

        while(nextSum){
            // Add the values up to (not including) the next 0.
            int sum = 0;
            while(nextSum->val != 0){
                sum = sum + nextSum->val;
                nextSum = nextSum->next;
            }

            // nextSum now stands on that 0. Store the block's sum in its
            // first node.
            modify->val = sum;
            // Step past the 0: this is the first node of the next block,
            // or NULL if that 0 was the last node.
            nextSum = nextSum->next;
            // Link the sum node directly to it, cutting out the rest of
            // the block and the 0, then move modify there.
            modify->next = nextSum;
            modify = modify->next;
        }
        // Skip the leading 0: the answer starts at the first sum node.
        return head->next;
    }
};