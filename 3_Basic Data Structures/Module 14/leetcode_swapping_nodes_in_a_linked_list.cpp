/*

https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

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
        int length = 0;
        ListNode* currentNode = head;
        while(currentNode){
            length++;
            currentNode = currentNode->next;
        }

        // set the front node
        ListNode* frontNode = head;
        for(int i=1; i< k; i++){
            frontNode = frontNode->next;
        }

        // set the end node
        ListNode* endNode = head;
        for(int i=1; i<= length-k; i++){
            endNode = endNode->next;
        }

        swap(frontNode->val, endNode->val);
        return head;
    }
};