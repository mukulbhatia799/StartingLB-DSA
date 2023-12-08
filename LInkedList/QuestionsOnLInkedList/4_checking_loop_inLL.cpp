/*
three ques comes in this ques:
1. check for loop
2. starting point of loop.
3. remove loop.
*/


#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    void insert(Node *&head)
    {
        int value;
        Node *temp = new Node;
        cout << "insert: ";
        cin >> value;

        temp->data = value;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            int pos;
            cout << "pos: ";
            cin >> pos;

            if (pos < 1 && pos > findLength(head) + 1)
            {
                cout << "pos is not valid!" << endl;
                delete temp;

                return;
            }
            else
            {
                Node *prev = NULL;
                Node *curr = head;
                while (pos != 1)
                {
                    prev = curr;
                    curr = curr->next;
                    pos--;
                }
                if (prev == NULL)
                {
                    temp->next = curr;
                    head = temp;
                }
                else
                {
                    prev->next = temp;
                    temp->next = curr;
                }
            }
        }
        cout << "inserted successfully" << endl;
        display(head);
    }
    bool checkingLoop(Node *head)
    {
        if (head == NULL)
        {
            cout << "LL is empty!" << endl;
            return false;
        }
        else
        {
            // using slow(+1) and fast(+2) pointer method.
            Node *slow = head;
            Node *fast = head;
            while (fast != NULL)
            {
                fast = fast->next;
                if (fast != NULL)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                if (fast == slow)
                {
                    cout << "Loop exits at Node " << fast->data << endl;
                    return true;
                }
            }
        }
        return false;
    }
    Node *findTail(Node *head)
    {
        if (head == NULL)
        {
            cout << "LL empty! can't find tail" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            return temp;
        }
        return NULL;
    }
    void setLooping(Node *head, Node *tail)
    {
        if (head == NULL)
        {
            cout << "can't set looping, LL is empty!" << endl;
        }
        else if (head == tail)
        {
            tail->next = head;
        }
        else
        {
            tail->next = head->next;
        }
    }
    int findLength(Node *head)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
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
            cout << "LL is empty!" << endl;
            return;
        }
        cout << "displaying LL: ";
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "LL size: " << findLength(head) << endl;
    }
} *head = NULL;

int main()
{
    Node linkedlist;
    linkedlist.insert(head);
    linkedlist.insert(head);
    linkedlist.insert(head);
    linkedlist.insert(head);
    linkedlist.insert(head);
    linkedlist.insert(head);

    // adding loop in LL.
    Node *tail = linkedlist.findTail(head);
    linkedlist.setLooping(head, tail);

    // checking loop in LL.
    if (linkedlist.checkingLoop(head))
    {
        cout << "loop exists!" << endl;
    }
    else
    {
        cout << "loop not exists." << endl;
    }

    return 0;
}