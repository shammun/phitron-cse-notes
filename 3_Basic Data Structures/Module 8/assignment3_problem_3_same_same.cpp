/*

Problem Statement

You will be given two singly linked list of integer values as input. You need to check if all the 
elements of both list are same which means both list are same. If they are same print "YES" 
otherwise print "NO".

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain the values of the first singly linked list, and will terminate with -1.
Second line will contain the values of the second singly linked list, and will terminate with -1.

Constraints
- 1 <= N1, N2 <= 1000; Here N1 and N2 is the maximum number of nodes of the first and second linked 
list.
- 0 <= V <= 1000; Here V is the value of each node.

Output Format
Output "YES" or "NO".

Sample Input 0
10 20 30 40 -1
10 20 30 40 -1

Sample Output 0
YES

Sample Input 1
10 20 30 40 -1
10 20 30 -1

Sample Output 1
NO

Sample Input 2
10 20 30 40 -1
40 30 20 10 -1

Sample Output 2
NO

*/

/*
 * Two lists are "the same" when they have the same length AND the same value
 * at every position. So first compare the sizes: different sizes can never be
 * the same list, and it also guarantees the next step is safe. Then walk both
 * lists side by side with two pointers, one step each per round, and compare
 * the values under them. The first mismatch means NO; no mismatch means YES.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <climits>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.


class Node {
    public:
        int val;
        Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL; 
    }
};

// O(1) append: `tail` remembers the last node, so there is no walk.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    
    // Link the new node after the old last node, then move `tail` onto it.
    tail->next = newNode;
    tail = newNode; // or tail = tail->next
}

// Count the nodes from head to NULL.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

// Prints YES when both lists hold the same values in the same order.
void is_similar(Node* head1, Node* head2){
    int size1 = get_size(head1);
    int size2 = get_size(head2);

    // Different lengths: they cannot be equal.
    if(size1 != size2){
        cout << "NO" << endl;
        return;
    }

    // Equal lengths, so both pointers reach NULL together: walk them in step.
    Node* temp1 = head1;
    Node* temp2 = head2;

    for(int i=0; i<size1; i++){
        int val1 = temp1->val;
        int val2 = temp2->val;
        if(val1 != val2){
            cout << "NO" << endl;
            return;
        }
        // Both pointers move one node forward.
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    // Every position matched.
    cout << "YES" << endl;
}


int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;
    
    int val;
    // First list: values until -1.
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head1, tail1, val);
    }

    // Second list, read the same way into its own head/tail.
    Node* head2 = NULL;
    Node* tail2 = NULL;

    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head2, tail2, val);
    }

    is_similar(head1, head2);

    return 0;
}
