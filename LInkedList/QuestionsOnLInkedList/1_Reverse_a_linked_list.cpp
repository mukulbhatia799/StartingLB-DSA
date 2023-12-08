#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }

    void insertNode(Node *&head)
    {
        int value;
        cout << "value to insert: ";
        cin >> value;

        int pos;
        cout << "Position to insert: ";
        cin >> pos;

        if (pos < 1 || pos > findLength(head) + 1)
        {
            cout << "pos is not valid!" << endl;
        }
        else if (head == NULL)
        {
            Node *temp = new Node;
            temp->data = value;
            head = temp;
        }
        else
        {
            Node *newNode = new Node;
            newNode->data = value;
            Node *curr = head;
            Node *prev = NULL;
            while (pos != 1)
            {
                prev = curr;
                curr = curr->next;
                pos--;
            }
            if (prev == NULL)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                prev->next = newNode;
                newNode->next = curr;
            }
        }
        display(head);
    }

    void reverseLL(Node *head) // ******* reverse a LL *******      // using iteration.
    {
        if (head == NULL)
        {
            cout << "LL is empty! can't reverse." << endl;
        }
        else if (findLength(head) == 1)
        {
            return;
        }
        else
        {
            Node *prev = NULL;
            Node *curr = head;
            while (curr != NULL)
            {
                Node *temp = curr->next; // save the addr of one ahead node so that the LL is not lost.
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            head = prev; // at last place head at last node.
        }
        display(head);
    }
    void reverseLLusingRE(Node *head) // using recursion.
    {
        if (head == NULL)
        {
            cout << "LL is empty! can't reverse." << endl;
        }
        else
        {
            Node *prev = NULL;
            Node *curr = head;
            cout << "reverse of LL......" << endl;
            reverseUsingREHelper(prev, curr, head);
        }
    }
    void reverseUsingREHelper(Node *prev, Node *curr, Node *&head)
    {
        if (curr == NULL)
        {
            head = prev;
            display(head);
            return;
        }
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        reverseUsingREHelper(prev, curr, head); // recursive function.
    }

    int findLength(Node *head)
    {
        Node *temp = head;
        int count = 0;
        while (temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    void display(Node *head)
    {
        cout << "Displaying LL: ";
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
        delete temp;
    }
} *head;

int main()
{
    Node linkedlist;
    linkedlist.insertNode(head);
    cout << "curr size of LL: " << linkedlist.findLength(head) << endl;
    linkedlist.insertNode(head);
    cout << "curr size of LL: " << linkedlist.findLength(head) << endl;
    linkedlist.insertNode(head);
    cout << "curr size of LL: " << linkedlist.findLength(head) << endl;

    linkedlist.reverseLLusingRE(head);
    cout << "curr size of LL: " << linkedlist.findLength(head) << endl;

    return 0;
}