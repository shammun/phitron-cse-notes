/*

Same or not 2

Problem Statement

There is a list of  values that were inserted into a stack and a list of  values that were inserted into a queue. You need to determine whether the stack and queue are the same or not based on the order in which the elements are removed.

Note: You cannot use any  here. You need to implement the stack and queue by yourself. You can use linked list or array as you want.

Input Format

First line will contain  and .
Second line will contain stack  with  values.
Third line will contain queue  with  values.
Constraints

Output Format

Output YES if they were same, otherwise NO.
Sample Input 0

5 5
10 20 30 40 50
50 40 30 20 10
Sample Output 0

YES
Sample Input 1

4 4
10 20 30 40
10 20 30 40
Sample Output 1

NO
Sample Input 2

5 4
1 2 3 4 5
5 4 3 2
Sample Output 2

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

class myStack{
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int size1 = 0;

        void push(int val){ // O(1)
            size1++;
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void pop(){ // O(1)
            size1--;
            Node* deleteNode = tail;
            tail = tail->prev;
            delete deleteNode; 
            if(tail==NULL){
                head=NULL;
                return;
            }
            tail->next = NULL;
        }

        int top(){
            return tail->val; // O(1)
        }

        int size(){
            return size1; // O(1)
        }

        bool empty(){
            return size1==0; // O(1)
            // return head==NULL; // O(1)
        }
};

class myQueue{
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int size2 = 0;

        void push(int val){ // O(1)
            size2++;
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }

        void pop(){ // O(1)
            size2--;
            Node* deleteNode = head;
            head = head->next;
            delete deleteNode;
            if(head==NULL){
                tail = NULL;
            }
        }

        int front(){ // O(1)
            return head->val;
        }

        int back(){ // O(1)
            return tail->val;
        }

        int size(){ // O(1)
            return size2;
        }

        bool empty(){ // O(1)
            return head == NULL;
            // return size == 0;
        }
};

int main(){
    int n, m;
    cin >> n >> m;

    myStack st;
    myQueue q;

    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        st.push(val);
    }

    for(int i=0; i<m; i++){
        int val;
        cin >> val;
        q.push(val);
    }

    if(n != m){
        cout << "NO" << endl;
        return 0;
    }

    while(!st.empty()){
        if(st.top() != q.front()){
            cout << "NO" << endl;
            return 0;
        } 
        st.pop();
        q.pop();
    }

    cout << "YES" << endl;

    return 0;
}

