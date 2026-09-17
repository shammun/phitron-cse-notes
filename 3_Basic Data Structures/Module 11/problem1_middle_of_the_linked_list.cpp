/*

https://leetcode.com/problems/middle-of-the-linked-list/description/

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
            int idx = size / 2;
            ListNode* temp = head;
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