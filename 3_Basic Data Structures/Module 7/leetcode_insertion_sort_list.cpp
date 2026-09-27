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

#include <iostream>   // cin and cout
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// This is the node LeetCode gives you at the top of the editor.
// A `struct` is the same as a `class` except its members are public by default.
struct ListNode {
    int val;          // the value in this node
    ListNode *next;   // address of the next node, NULL at the end
    // Three constructors. The part after `:` is a "member initializer list":
    // `val(0), next(NULL)` sets the members before the (empty) body `{}` runs.
    ListNode() : val(0), next(NULL) {}                            // ListNode()      -> val 0, no next
    ListNode(int x) : val(x), next(NULL) {}                       // ListNode(5)     -> val 5, no next
    ListNode(int x, ListNode *next) : val(x), next(next) {}       // ListNode(5, p)  -> val 5, next p
};

// LeetCode wraps the answer in a class called Solution with one public method.
class Solution {
public:
    // Takes the head of an unsorted list, returns the head of the same nodes
    // re-linked in ascending order.
    ListNode* insertionSortList(ListNode* head) {
        /* A fake node in front of the sorted list. It means every insertion
           looks the same, even the one that lands before the smallest value:
           there is always a node to hang the new node from. */
        ListNode* dummy = new ListNode(0);   // dummy->next is the sorted list; starts empty (NULL)

        ListNode* cur = head;   // the node of the unsorted list we are placing now
        // One pass = take `cur` out of the unsorted list and insert it into
        // the sorted list. Stops when every node has been placed.
        // Trace with 4 2 1 3:
        //   place 4 -> sorted: 4
        //   place 2 -> sorted: 2 4
        //   place 1 -> sorted: 1 2 4
        //   place 3 -> sorted: 1 2 3 4
        while(cur != NULL){
            /* Save the rest of the unsorted list first. The very next line
               changes `cur->next`, and then the rest would be unreachable. */
            ListNode* nextNode = cur->next;

            /* Walk the sorted list while the value there is still <= cur->val.
               We stop at the node *before* the spot, because in a singly list
               only that node can be made to point at `cur`. */
            ListNode* p = dummy;
            // `&&` stops early: if p->next is NULL, the second test (which
            // would read NULL->val) is never evaluated. Using `<=` puts equal
            // values after the ones already there, so the sort is stable.
            while(p->next != NULL && p->next->val <= cur->val){
                p = p->next;
            }

            // Hook `cur` between `p` and whatever `p` was pointing at.
            cur->next = p->next;   // cur points at the node after the spot
            p->next = cur;         // the node before the spot points at cur

            cur = nextNode;        // move on to the next unsorted node (saved earlier)
        }

        return dummy->next; // the real head, one step past the fake node
        // (the dummy node itself is never deleted - a tiny leak, harmless here)
    }
};

// Main function: Entry point of the program.
int main(){
    int n;   // how many values the next list has
    // `cin >> n` is true while a number could be read and false at the end
    // of input, so this loop handles any number of test lists.
    while(cin >> n){
        ListNode* head = NULL;   // new, empty list for this test
        ListNode* tail = NULL;

        // Read n values and append each at the tail, keeping input order.
        for(int i = 0; i < n; i++){
            int val;
            cin >> val;
            ListNode* newNode = new ListNode(val);   // new node on the heap
            if(head == NULL){          // first node: it is head and tail
                head = newNode;
                tail = newNode;
            } else {                   // otherwise link after the last node
                tail->next = newNode;
                tail = newNode;
            }
        }

        // `Solution()` makes a temporary Solution object; we call its method
        // on our list and keep the returned sorted head.
        ListNode* sorted = Solution().insertionSortList(head);

        // Print the sorted list with a space BETWEEN values (none after the last).
        // This `for` walks: start at sorted, stop at NULL, step with ->next.
        for(ListNode* tmp = sorted; tmp != NULL; tmp = tmp->next){
            cout << tmp->val;
            if(tmp->next != NULL){     // there is another value after this one
                cout << " ";
            }
        }
        cout << endl;   // end this test's line (endl = newline + flush)
    }

    return 0;   // normal exit
}
