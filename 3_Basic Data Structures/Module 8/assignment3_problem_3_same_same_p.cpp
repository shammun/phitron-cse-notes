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

        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

int get_size(Node* head){
    int size = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        tmp = tmp->next;
        size++;
    }
    return size;
}

void is_similar(Node* head1, Node* head2){
    int size1 = get_size(head1);
    int size2 = get_size(head2);

    if(size1 != size2){
        cout << "NO" << endl;
        return;
    }

    Node* tmp1 = head1;
    Node* tmp2 = head2;

    while(tmp1 != NULL){
        if(tmp1->val != tmp2->val){
            cout << "NO" << endl;
            return;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    cout << "YES" << endl;
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;

    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head1, tail1, val);
    }

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
}