
// gfg ques - Delete N nodes after M nodes of a linked list;

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next = NULL;

public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    void insert(Node *&head)
    {
        Node *temp = new Node;
        int val;
        cout << "insert: ";
        cin >> val;
        temp->data = val;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
    void linkdelete(Node* head, int M, int N)
    {
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL)
        {
            int m = M;
            int n = N;
            while(m != 0 && curr != NULL)
            {
                prev = curr;
                curr = curr->next;
                m--;
            }
            while(n != 0 && curr != NULL)
            {
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                curr = prev->next;
                n--;
            }
        }
    }
    void reverse(Node *&head)
    {
        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }
        head = prev;
        cout << "LL reversed!" << endl;
        display(head);
    }
    void addOneInLL(Node *&head)
    {
        reverse(head);
        int carry = 1;
        Node *temp = head;
        Node *prev = NULL;
        while (temp)
        {
            int sum = temp->data + carry;
            int newval = sum % 10;
            carry = sum / 10;
            prev = temp;
            temp->data = newval;
            temp = temp->next;
        }
        if (carry != 0)
        {
            Node *newnode = new Node;
            newnode->data = carry;
            prev->next = newnode;
        }
        reverse(head);
    }
    void display(Node *head)
    {
        Node *temp = head;
        cout << "displaying LL: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
} *head = NULL;

int main()
{
    Node ll;
    // input: 9 1 3 5 9 4 10 1
   // output: 9 1 5 9 10 1
    ll.insert(head);
    ll.insert(head);
    ll.insert(head);
    ll.insert(head);
    ll.insert(head);
    ll.insert(head);
    ll.insert(head);
    ll.insert(head);

    ll.display(head);
    ll.linkdelete(head, 2, 1);
    ll.display(head);

    return 0;
}