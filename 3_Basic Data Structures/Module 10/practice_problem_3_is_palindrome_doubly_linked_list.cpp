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
    bool flag = true;
    for(Node *i=head, *j=tail; i!=j && i->prev != j; i=i->next, j=j->prev){
        if(i->val != j->val){
            flag = false;
            break;
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
            return;
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