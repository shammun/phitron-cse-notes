
/*

Take two doubly linked lists as input and check if they are the same or not.

Input:
10 20 30 40 50 -1
10 20 30 40 50 -1

Output:
YES

Input:
10 20 30 40 50 -1
10 20 30 40 -1

Output:
NO

*/

/*
 * What this file does: it builds two doubly linked lists from the input and
 * answers YES when they have the same number of nodes.
 *
 * Two things stand between it and the real task:
 *
 *   * it never runs to the end. The first loop leaves `main` with `return;`
 *     the moment it reads -1, so nothing is printed. `break;` was meant.
 *     The second loop is `while(tail2)`, and `tail2` is NULL at that point,
 *     so it would never read anything even after the first fix; it should
 *     be `while(true)` as well.
 *   * the task asks whether the lists are the *same*, and equal size is only
 *     the first half of that. `10 20 30` and `30 20 10` have the same size
 *     but are different lists. practice_problem_1_same_doubly_lists.cpp
 *     finishes the job: size first, then a value-by-value walk.
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


// Append at the end. `tail` is kept so this is O(1) instead of a walk.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){          // empty list: the new node is head and tail
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;    // old tail -> new node
    newNode->prev = tail;    // new node -> old tail (the arrow back)
    tail = newNode;          // the new node is the tail now
}

// Count the nodes by walking from head until we fall off the end.
int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;

    // First list: read values until -1.
    int val;
    while(true){
        cin >> val;
        if(val==-1){
            // Bug: `return;` ends the whole program here, before the second
            // list is read or anything is printed. Use `break;`.
            return;
        }
        insert_at_tail(head1, tail1, val);
    }

    Node* head2 = NULL;
    Node* tail2 = NULL;
    int val2;
    // Bug: `tail2` is NULL, so this loop never starts. Use `while(true)`.
    while(tail2){
        cin >> val2;
        if(val2==-1){
            return;
        }
        insert_at_tail(head2, tail2, val2);
    }

    // Compare only the sizes. For "same list" you would also have to walk
    // both lists together and compare each pair of values.
    int size1 = get_size(head1);
    int size2 = get_size(head2);
    if(size1 == size2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}