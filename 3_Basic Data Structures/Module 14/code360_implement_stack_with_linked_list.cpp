/*

https://www.naukri.com/code360/problems/implement-stack-with-linked-list_630475?leftPanelTabValue=PROBLEM

*/

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
    //Write your code here
    Node* head;
    int size;

    public:
        Stack()
        {
            //Write your code here
            head = NULL;
            size = 0;
        }

        int getSize()
        {
            //Write your code here
            return size;
        }

        bool isEmpty()
        {
            //Write your code here
            return head == NULL;
        }

        void push(int data)
        {
            //Write your code here
            Node* newNode = new Node(data);
            newNode->next =head;
            head = newNode;
            size++;
        }

        void pop()
        {
            //Write your code here
            if (isEmpty()) {
                return;
            }
            Node* tmp = head;
            head = head->next;
            delete tmp;
            size--;
        }

        int getTop()
        {
            //Write your code here
            if (isEmpty()) {
                return -1;
            }

            return head->data;
        }
};