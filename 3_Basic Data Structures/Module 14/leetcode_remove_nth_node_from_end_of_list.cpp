/*

https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* currentNode = head; 
        while(currentNode){
            length++;
            currentNode = currentNode->next;
        }

        if(n == length){
            ListNode* toDel = head;
            head = head->next;
            delete toDel;
            return head;
        }

        ListNode* tmp = head;
        int index = length - n;
        for(int i=1; i<index; i++){
            tmp = tmp->next;
        }
        ListNode* toDelete = tmp->next;
        tmp->next = tmp->next->next;
        delete toDelete;

        return head;
    }
};