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

#include <iostream>     // cout and endl
using namespace std;    // write cout instead of std::cout

// One node of a singly linked list: a value plus the address of the next node.
struct ListNode{
    int val;            // the number stored here
    ListNode* next;     // address of the next node, nullptr for the last node
    // Default constructor. ": val(0), next(nullptr)" is an initializer list.
    ListNode(): val(0), next(nullptr){}
    // Constructor with a value: new ListNode(3) -> node 3 with no next.
    ListNode(int x): val(x), next(nullptr){}
    // Constructor with a value and a pointer to the next node
    ListNode(int x, ListNode* next): val(x), next(next){}
};

// LeetCode's answer class, with one helper and the required function.
class Solution {
    public:     // both functions can be called from outside
        // Walk 1: count every node until we fall off the end.
        // Returns the number of nodes in the list.
        int get_size(ListNode* head){
            int size = 0;               // counter
            ListNode* temp = head;      // walker pointer
            while(temp != NULL){        // one pass per node
                size++;                 // count it
                temp = temp->next;      // '->' = member through a pointer: go to next node
            }
            return size;
        }

        // Returns the address of the middle node (second middle for even length).
        ListNode* middleNode(ListNode* head){
            int size = get_size(head);  // e.g. 5
            int idx = size / 2;          // 0-based index of the (second) middle; 5/2 = 2 (int division drops .5)
            ListNode* temp = head;
            // Walk 2: idx steps from the head land on the middle node.
            // i = 0 .. idx-1 -> exactly idx steps. For idx 2: node1 -> node2 -> node3.
            for(int i=0; i<idx; i++){
                temp = temp->next;
            }
            return temp;                // the middle node itself (not just its value)
        }

};

int main(){
    // Build five separate nodes on the heap; `new` returns each node's address.
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    // Link the nodes: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Instantiate the solution and get the middle node
    Solution sol;                           // object needed to call the member function
    ListNode* middle = sol.middleNode(n1);  // pass the head; get back node 3's address

    // Print the value of the middle node
    cout << middle->val << endl;            // prints 3

    // Clean up the memory: one delete for every new.
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;   // normal exit
}