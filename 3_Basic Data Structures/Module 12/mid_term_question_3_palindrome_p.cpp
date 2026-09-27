/*

Problem Statement

You need to take a doubly linked list of integer value as input. You need to tell if the 
doubly linked list forms a palindrome or not.

Note: You need to solve this using Doubly Linked List, otherwise you will not get marks.

Input Format

Input will contain the values of the doubly linked list, and will terminate with -1.
Constraints

1 <= N <= 10^6; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output "YES" if it forms a palindrom otherwise output "NO".
Sample Input 0

1 2 3 2 1 -1
Sample Output 0

YES
Sample Input 1

1 2 2 1 -1
Sample Output 1

YES
Sample Input 2

1 -1
Sample Output 2

YES
Sample Input 3

1 2 3 1 -1
Sample Output 3

NO

*/

/*
 * The idea: a doubly linked list can be read from both ends at once. Put `i`
 * on the head and `j` on the tail, compare their values, then move `i`
 * forward and `j` backward. One different pair means NO.
 *
 * When to stop:
 *   odd length  (1 2 3 2 1): the two pointers land on the same middle node,
 *                            `i == j`, and a node always equals itself;
 *   even length (1 2 2 1)  : they never land on the same node - they cross,
 *                            and right after crossing `i->prev == j`.
 * Without the second test an even list would walk right off both ends.
 */

// Practice copy of mid_term_question_3_palindrome.cpp: the same code.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 

class Node {
    public:
        int val;     
        Node* next;
        Node* prev;

    Node(int val) {
        this->val = val; 
        this->next = NULL;
        this->prev = NULL;
    }
};


// Append at the end in O(1), because `tail` is remembered.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

bool is_palindrome(Node* head, Node* tail){
    bool flag = true;   // a palindrome until a mismatch is found
    for(Node *i=head, *j=tail; i!=j && i->prev != j; i=i->next, j=j->prev){
        // Compare the two mirror positions.
        if(i->val != j->val){
            flag = false;   // one mismatch is enough
            break;
        }
    }
    return flag;
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;

    int val;
    // Read values until -1.
    while(true){
        cin >> val;
        if(val==-1){
            break;
        }
        insert_at_tail(head1, tail1, val);
    }

    bool result = is_palindrome(head1, tail1);

    if(result){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
