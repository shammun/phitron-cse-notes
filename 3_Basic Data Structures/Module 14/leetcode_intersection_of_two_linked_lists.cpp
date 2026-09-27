/*

https://leetcode.com/problems/intersection-of-two-linked-lists/

Intersection of Two Linked Lists (LeetCode 160) -- a Module 11 problem, solved again

Two lists may join at some node and share every node after it (a Y shape).
Return the first shared node, or NULL if they never join.

Example: A = 4 1 [8 4 5], B = 5 6 1 [8 4 5] where [8 4 5] are the SAME
nodes -> answer is the node holding 8.

Idea (brute force): for every node of A, walk all of B and look for the very
same node. Compare the POINTERS (addresses), not the values: two different
nodes can hold equal values. O(n*m) time, O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Outer walk: every node of list A.
        ListNode* tempA = headA;
        while(tempA != NULL){
            // Inner walk: restart at the head of B for each node of A.
            ListNode* tempB = headB;
            while(tempB != NULL){
                // Same address = same node = the lists meet here.
                if(tempA == tempB){
                    return tempA;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }
        // No node of A appears in B: the lists never meet.
        return NULL;
    }
};