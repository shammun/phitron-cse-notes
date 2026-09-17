/*

https://leetcode.com/problems/middle-of-the-linked-list/description/

Middle of the Linked List

*/

class Solution {
public:
    int get_size(ListNode* head){
        int size = 0;  
        ListNode* temp = head;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        return size;      
    }
    ListNode* middleNode(ListNode* head) {
        int size = get_size(head);
        int idx = size / 2;
        ListNode* temp = head;
        for(int i=0; i<idx; i++){
            temp = temp->next;
        }
        return temp;
    }
};

