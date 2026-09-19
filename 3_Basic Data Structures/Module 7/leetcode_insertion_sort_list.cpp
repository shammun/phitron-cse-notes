/*

Insertion Sort List   (LeetCode 147)
https://leetcode.com/problems/insertion-sort-list/

You are given the head of a singly linked list. Sort it in ascending order the
way insertion sort works: keep a second list that is always sorted, take the
nodes of the given list one by one, and drop each node into the place where it
belongs inside the sorted list. Return the head of the sorted list.

The nodes themselves are moved (their `next` links are rewritten); no new node
is created for the answer, and the values are not copied around.

Input (for this program, so it can be run here)
A number n, then n values on the next line. The program keeps reading pairs
like that until the input ends, so several lists can be given in one run.

Output
One line per list: the values in ascending order, separated by spaces.

Constraints
The list may be empty. Values can be negative. The list is short enough that
a sort doing two nested walks is fast enough (this is the whole point of the
problem: the simple O(n^2) method is accepted).

Example

input
4
4 2 1 3
5
-1 5 3 4 0

output
1 2 3 4
-1 0 3 4 5

*/

#include <iostream>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// This is the node LeetCode gives you at the top of the editor.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        /* A fake node in front of the sorted list. It means every insertion
           looks the same, even the one that lands before the smallest value:
           there is always a node to hang the new node from. */
        ListNode* dummy = new ListNode(0);

        ListNode* cur = head;
        while(cur != NULL){
            /* Save the rest of the unsorted list first. The very next line
               changes `cur->next`, and then the rest would be unreachable. */
            ListNode* nextNode = cur->next;

            /* Walk the sorted list while the value there is still <= cur->val.
               We stop at the node *before* the spot, because in a singly list
               only that node can be made to point at `cur`. */
            ListNode* p = dummy;
            while(p->next != NULL && p->next->val <= cur->val){
                p = p->next;
            }

            // Hook `cur` between `p` and whatever `p` was pointing at.
            cur->next = p->next;
            p->next = cur;

            cur = nextNode;
        }

        return dummy->next; // the real head, one step past the fake node
    }
};

// Main function: Entry point of the program.
int main(){
    int n;
    while(cin >> n){
        ListNode* head = NULL;
        ListNode* tail = NULL;

        for(int i = 0; i < n; i++){
            int val;
            cin >> val;
            ListNode* newNode = new ListNode(val);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        ListNode* sorted = Solution().insertionSortList(head);

        for(ListNode* tmp = sorted; tmp != NULL; tmp = tmp->next){
            cout << tmp->val;
            if(tmp->next != NULL){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
