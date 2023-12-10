
/*
Approach:
1. reverse LL.
2. Then, add one to first node and pass carry to next node in while loop.
3. again reverse the number in it's original order.
*/

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

    cout << "Enter each digit in each node" << endl;
    ll.insert(head);
    ll.insert(head);
    ll.insert(head);

    cout << "-------before adding one-------" << endl;
    ll.display(head);

    cout << "--------After adding one--------" << endl;
    ll.addOneInLL(head);

    return 0;
}