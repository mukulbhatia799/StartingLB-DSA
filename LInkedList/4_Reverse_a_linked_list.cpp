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

    void reverseLL(Node *head) // ******* reverse a LL *******
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

    linkedlist.reverseLL(head);
    cout << "curr size of LL: " << linkedlist.findLength(head) << endl;

    return 0;
}