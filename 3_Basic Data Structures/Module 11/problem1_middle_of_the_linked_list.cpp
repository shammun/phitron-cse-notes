/*

https://leetcode.com/problems/middle-of-the-linked-list/description/

Return the middle node of a singly linked list. When there are two middle
nodes (even length), return the second one.
Example: 1 2 3 4 5 -> 3,   1 2 3 4 5 6 -> 4.

The idea: a linked list cannot jump to an index, so find the middle in two
walks. Walk 1 counts the nodes. The middle is then at index size/2 (counting
from 0): for 5 nodes that is index 2 (value 3), for 6 nodes index 3 (value
4) - integer division picks the *second* middle by itself. Walk 2 takes
exactly size/2 steps from the head.

*/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    // Default constructor
    ListNode(): val(0), next(nullptr){}
    // Constructor with a value
    ListNode(int x): val(x), next(nullptr){}
    // Constructor with a value and a pointer to the next node
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
    public:
        // Walk 1: count every node until we fall off the end.
        int get_size(ListNode* head){
            int size = 0;
            ListNode* temp = head;
            while(temp != NULL){
                size++;
                temp = temp->next;
            }
            return size;
        }

        ListNode* middleNode(ListNode* head){
            int size = get_size(head);
            int idx = size / 2;          // 0-based index of the (second) middle
            ListNode* temp = head;
            // Walk 2: idx steps from the head land on the middle node.
            for(int i=0; i<idx; i++){
                temp = temp->next;
            }
            return temp;
        }

};

int main(){
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    // Link the nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Instantiate the solution and get the middle node
    Solution sol;
    ListNode* middle = sol.middleNode(n1);

    // Print the value of the middle node
    cout << middle->val << endl;

    // Clean up the memory
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}