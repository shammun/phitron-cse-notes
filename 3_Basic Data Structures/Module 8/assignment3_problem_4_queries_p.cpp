/*

Problem Statement

You have a singly linked list which is empty initially. Then you will be given Q queries. In each 
query you will be given two values X and V.

If X is 0 that means you will insert the value V to the head of the linked list.
If X is 1 then you will insert the value V to the tail of the linked list.
If X is 2 then you will delete the value Vth index of the linked list. Assume that index starts 
from 0. If the index is invalid, then you shouldn't perform the deletion.
After each query you need to print the linked list.
Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 1000;
0 <= X <= 2;
0 <= V <= 10^9
Output Format

For each query ouput the updated linked list.

Sample Input 0
4
0 10
1 20
1 30
0 40

Sample Output 0
10 
10 20 
10 20 30 
40 10 20 30 

Sample Input 1
11
0 10
2 5
1 20
1 30
0 40
2 0
0 50
2 2
1 60
2 3
2 3

Sample Output 1
10 
10 
10 20 
10 20 30 
40 10 20 30 
10 20 30 
50 10 20 30 
50 10 30 
50 10 30 60 
50 10 30 
50 10 30 

Sample Input 2
10
1 4
2 1
0 9
0 10
2 2
1 5
2 0
2 1
2 5
2 2

Sample Output 2
4 
4 
9 4 
10 9 4 
10 9 
10 9 5 
9 5 
9 
9 
9 

*/

/*
 * A list that starts empty and changes with every query:
 *   X = 0 -> insert V at the head
 *   X = 1 -> insert V at the tail
 *   X = 2 -> delete the node at index V, but only if that index exists
 * and after every query the whole list is printed.
 *
 * The only tricky query is the delete. Valid indexes are 0..size-1, so any
 * V >= size is ignored. Index 0 is the head (move head forward). Any other
 * index: stand on the node one BEFORE it, bend its arrow past the victim,
 * then free the victim. If the victim was the last node, tail moves back.
 *
 * Part of Sample 1 traced:
 *   list 40 10 20 30, query "2 0" -> index 0 is the head -> 10 20 30
 *   list 50 10 20 30, query "2 2" -> stand on index 1 (10), skip 20 -> 50 10 30
 *   list 50 10 30 60, query "2 3" -> index 3 is the last node (60): the node
 *                     before it (30) becomes the new tail -> 50 10 30
 *   list 50 10 30,    query "2 3" -> size is 3, index 3 does not exist -> no change
 */

/* Practice copy of assignment3_problem_4_queries.cpp - same logic. */

#include <iostream>   // cin and cout
#include <vector>   // std::vector - not used here
#include <algorithm>   // sort/max/min - not used here
#include <string>   // std::string - not used here
using namespace std; 

// One node of a singly linked list: a value plus the next node's address.
class Node {
    public:   // usable from outside the class
        int val;   // the data
        Node* next;   // next node's address; NULL for the last node

    // Constructor, runs on `new Node(x)`. `this->val` is the member,
    // plain `val` the parameter with the same name.
    Node(int val) {
        this->val = val;   // store the value
        this->next = NULL;   // not linked yet
    }
};

// Count the nodes from head to NULL.
int get_size(Node* head){
    int size = 0;   // counter
    Node* tmp = head;   // walker (a copy; head itself does not move)
    while(tmp!=NULL){   // one pass per node, until we fall off the end
        tmp = tmp->next;   // step over a node...
        size++;   // count the node just stepped over
    }
    return size;   // number of nodes
}

// X = 0: the new node points at the old head and becomes the head.
// `Node* &` = reference to main's pointer, so main sees the new head/tail.
// O(1): no walk needed.
void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // `new` builds the node on the heap and returns its address
    if(head == NULL){   // empty list: the new node is first and last
        head = newNode;   // first node...
        tail = newNode;   // ...and also the last node
        return;   // done
    }
    // Non-empty list: link in front of the old head.
    newNode->next = head;   // new node points at the old first node
    head = newNode;   // and becomes the first node itself
}

// X = 1: walk to the last node and hang the new node after it.
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);   // new heap node
    if(head == NULL){   // empty list: first and last node
        head = newNode;   // first node...
        tail = newNode;   // ...and also the last node
        return;   // done
    }

    Node* tmp = head;   // start the walk at the first node
    // Walk to the last node (O(n); the `tail` pointer would make this O(1)).
    while(tmp->next != NULL){   // stops on the last node (the one whose next is NULL)
        tmp = tmp->next;   // one step forward
    }
    tmp->next = newNode;   // hang the new node after the old last node
    tail = newNode;   // remember it as the last node
}

// X = 2: remove the node at index `idx` if it exists.
void delete_at_any_position(Node* &head, Node* &tail, int idx){
    // Empty list, or an index past the last node: nothing to delete.
    // `||` means OR. Valid indexes are 0..size-1.
    if(head == NULL || idx >= get_size(head)){
        return;   // nothing to do
    }

    // Deleting the head: the second node becomes the head.
    if(idx == 0){   // the head has no node before it, so it is handled separately
        Node* deleteNode = head;   // save the old head
        head = head->next;   // second node becomes the head

        if(head == NULL){
            // The list is now empty, so there is no last node either.
            tail = NULL;   // no nodes left, so no last node
        }
        delete deleteNode;   // free the old head (`delete` gives back memory made by `new`)
        return;   // done
    }

    // Stop on the node just BEFORE the victim: idx-1 steps.
    Node* tmp = head;   // walker, starts on index 0
    for(int i=1; i<idx; i++){   // idx-1 steps: ends on index idx-1
        tmp = tmp->next;   // one step forward
    }

    // Hold the victim, bend the arrow past it, then free it.
    Node* deleteNode = tmp->next;   // the victim (index idx)
    tmp->next = tmp->next->next;   // bend the arrow past the victim

    // We removed the last node: the node before it is the new tail.
    if(tmp->next == NULL){   // nothing after the gap: the victim was the last node
        tail = tmp;   // move tail back one node
    }

    delete deleteNode;   // free the victim
}

// Print all values on one line, each followed by a space, then a newline.
void print_linked_list(Node* head){
    Node* tmp = head;   // walker
    while(tmp != NULL){   // until past the last node
        cout << tmp->val << " ";   // print one value and a space
        tmp = tmp->next;   // next node
    }
    cout << endl;   // endl = newline + flush
}

int main(){
    int Q;   // how many queries follow
    cin >> Q;   // number of queries

    // The list starts empty and is shared by all queries.
    Node* head = NULL;   // first node (none yet)
    Node* tail = NULL;   // last node (none yet)

    // One query per round; print the list after each one.
    // `while(Q--)` tests Q, then lowers it by 1: the body runs exactly Q times.
    while(Q--){
        int X, V;   // X = kind of query, V = value (or index for X = 2)
        cin >> X >> V;   // read both numbers of this query

        if(X == 0){   // insert at head
            insert_at_head(head, tail, V);   // X = 0
        } else if(X == 1){   // insert at tail
            insert_at_tail(head, tail, V);   // X = 1
        } else if(X == 2){   // delete index V (if it exists)
            delete_at_any_position(head, tail, V);   // X = 2; V is an index here
        }
        print_linked_list(head);   // print after every query, even when nothing changed
    }

    return 0;   // normal exit
}
