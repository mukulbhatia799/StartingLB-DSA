// circular doubly linkedlist
#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *prev;
    Node *next;

public:
    Node()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }
    void insert(Node *&head, Node *&tail)
    {
        int val, pos;
        cout << "insert: ";
        cin >> val;
        cout << "position: ";
        cin >> pos;
        int len = findLength(head);
        if (pos < 1 && pos > len + 1)
        {
            cout << "pos is not valid!" << endl;
            return;
        }
        Node *temp = new Node;
        temp->data = val;
        if (head == NULL)
        {
            temp->next = temp;
            temp->prev = temp;
            head = temp;
            tail = temp;

            // cout << "inserted in empty LL" << endl;
        }
        else if (pos == 1)
        {
            head->prev = temp;
            temp->next = head;
            head = temp;
            tail->next = temp;
            temp->prev = tail;
            // cout << "inserted on head" << endl;
        }
        else if (pos == len + 1) // if pos is next to the last node.
        {
            temp->prev = tail;
            tail->next = temp;
            temp->next = head;
            head->prev = temp;
            tail = temp;

            // cout << "inserted next to the tail" << endl;
        }
        else
        {
            Node *back = head;
            pos = pos - 1; // to stay on prev node.
            while (pos != 1)
            {
                back = back->next;
            }
            temp->next = back->next;
            back->next->prev = temp;
            back->next = temp;
            temp->prev = back;

            // cout << "inserted!" << endl;
        }
        display(head);
    }
    void deleteNode(Node *&head, Node *&tail)
    {
        if (head == NULL)
        {
            cout << "empty LL! can't delete" << endl;

            return;
        }

        int pos;
        cout << "pos to delete: ";
        cin >> pos;

        if (pos == 1) // delete head node.
        {
            if (findLength(head) == 1)
            {
                Node *temp = head;
                temp->next = NULL;
                temp->prev = NULL;
                head = NULL;
                tail = NULL;
                delete temp;
            }
            else
            {
                Node *delnode = head;
                head = head->next;
                head->prev = tail;
                tail->next = head;
                delnode->next = NULL;
                delnode->prev = NULL;
                delete delnode;
            }
        }
        else if (pos == findLength(head)) // delete last node.
        {
            Node *delnode = tail;
            if (tail->prev == NULL)
            {
                delete delnode;
                return;
            }
            else
            {
                tail->prev->next = head;
                head->prev = tail->prev;
                delete delnode;
            }
        }
        else // delete mid node.
        {
            Node *back = NULL;
            Node *curr = head;
            while (pos != 1)
            {
                back = curr;
                curr = curr->next;
                pos--;
            }
            back->next = curr->next;
            curr->next->prev = back;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
        display(head);
    }

    // we can't reverse circular LL because it will be same as before.

    int findLength(Node *head)
    {
        if (head == NULL)
            return 0;
        Node *temp = head->next;
        int count = 1;
        while (temp != head)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
    void display(Node *head)
    {
        if (head == NULL)
        {
            cout << "empty LL! can't display" << endl;
            return;
        }
        cout << "Displaying LL: ";
        Node *temp = head;
        cout << temp->data << " -> ";
        temp = temp->next;

        while (temp != head)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
} *head = NULL, *tail = NULL;

int main()
{
    Node ll;

    ll.insert(head, tail);
    ll.insert(head, tail);
    ll.insert(head, tail);

    ll.deleteNode(head, tail);
    ll.deleteNode(head, tail);

    return 0;
}