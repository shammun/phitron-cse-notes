/*

Take a doubly linked list as input and check if it forms any palindrome or not.

Input:
10 20 30 20 10 -1

Output:
YES

Input:
10 20 30 30 20 10 -1

Output:
YES

Input:
10 20 30 40 20 10 -1

Output:
NO

*/


/*
 * The idea: a palindrome reads the same from both ends, and a doubly linked
 * list can be walked from both ends at once. Put `i` on the head and `j` on
 * the tail, compare the two values, then step `i` forward and `j` backward.
 * One mismatch is enough to say NO. If they reach the middle with no
 * mismatch, the answer is YES.
 *
 * The stopping test is the same one reverse_doubly_linked_list.cpp uses:
 * `i != j` stops an odd-length list when both land on the middle node, and
 * `i->prev != j` stops an even-length list the moment the two pointers cross.
 *
 * In `main` the input loop ends with `break;` when -1 arrives. It first said
 * `return;`, which left the program before the check and printed nothing;
 * the `_p.cpp` copy still has that mistake.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 

// A doubly linked node: the value, an arrow forward and an arrow back.
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
    bool flag = true;   // innocent until a mismatch is found
    for(Node *i=head, *j=tail; i!=j && i->prev != j; i=i->next, j=j->prev){
        // Compare the pair that mirrors each other.
        if(i->val != j->val){
            flag = false;   // one different pair is enough
            break;          // no need to look further
        }
    }
    return flag;
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;

    int val;
    while(true){
        cin >> val;
        if(val==-1){
            break;    // leave the loop only; `return;` would skip the check
        }
        insert_at_tail(head1, tail1, val);
    }

    // Check the list and print the verdict.
    bool result = is_palindrome(head1, tail1);

    if(result){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}