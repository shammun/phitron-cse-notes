/*

https://leetcode.com/problems/middle-of-the-linked-list/description/

Middle of the Linked List

*/

/*
 * Task in short: return the middle node of the list; with an even number of
 * nodes, return the second of the two middle ones.
 * Example: 1 2 3 4 5 -> 3, and 1 2 3 4 5 6 -> 4.
 *
 * Idea: two simple walks. First count the nodes, then walk size/2 steps from
 * the head. size/2 is exactly the index we want for both odd sizes
 * (5/2 = 2 -> node 3) and even sizes (6/2 = 3 -> node 4).
 */
// (LeetCode defines ListNode - int val, ListNode *next - and calls
// middleNode from its own hidden main.)
class Solution {
public:   // LeetCode calls middleNode from outside the class
    // Walk the whole list once and count the nodes.
    int get_size(ListNode* head){
        int size = 0;
        ListNode* temp = head;      // start at the first node
        while(temp != NULL){        // stops after the last node
            size++;                 // count this node
            temp = temp->next;      // step to the next one
        }
        return size;
    }
    ListNode* middleNode(ListNode* head) {
        int size = get_size(head);
        // Index (0-based) of the middle node.
        int idx = size / 2;
        // idx steps from the head land on node number idx.
        ListNode* temp = head;
        for(int i=0; i<idx; i++){
            temp = temp->next;      // one step right
        }
        return temp;                // the middle node
    }
};

