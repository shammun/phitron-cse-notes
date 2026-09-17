/*

https://leetcode.com/problems/palindrome-linked-list/description/

*/

class Solution {
public:
    void reverse(ListNode* &head, ListNode* tmp){
        if(tmp->next == NULL){
            head = tmp;
            return;
        }
        reverse(head, tmp->next);
        tmp->next->next = tmp;
        tmp->next = NULL;
    }

    void insert_at_tail(ListNode* &head, ListNode* &tail, int val){
        ListNode* newNode = new ListNode(val);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        ListNode* tmp = head;
        while(tmp != NULL){
            insert_at_tail(newHead, newTail, tmp->val);
            tmp = tmp->next;
        }
        reverse(newHead, newHead);

        tmp = head;
        ListNode* tmp2 = newHead;

        while(tmp != NULL){
            if(tmp->val != tmp2->val){
                return false;
            }
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        return true;
    }
};