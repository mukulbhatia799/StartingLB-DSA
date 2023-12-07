/*
    Linked list can be linear as well as nonlinear,
    linear because each node is connected to it's previous node
    and non linear becuase non contiguous memory location happens
    in linked list.

    When we try to access the NULL pointer address. Then the
    NullPointerException error will occur.
*/

// singly LL

// #include <iostream>
// using namespace std;

// class Node
// {
//     int data;
//     Node *next;

// public:
//     Node()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }
//     ~Node()
//     {
//         cout << "deleted " << this->data << " node successfully:)" << endl;
//     }
//     void insertAtHead(Node *&head, Node *&tail)
//     {
//         int value;
//         cout << "value to insert at head: ";
//         cin >> value;

//         Node *temp = new Node;
//         temp->data = value;
//         if (head == NULL)
//         {
//             head = temp;
//             tail = temp;
//         }
//         else
//         {
//             temp->next = head;
//             head = temp;
//         }
//         cout << "insertion done at head successfully." << endl;
//     }
//     void insertAtTail(Node *&head, Node *&tail)
//     {
//         int value;
//         cout << "value to insert at tail: ";
//         cin >> value;

//         Node *temp = new Node;
//         temp->data = value;
//         if (tail == NULL)
//         {
//             tail = temp;
//             head = temp;
//         }
//         else
//         {
//             tail->next = temp;
//             tail = temp;
//         }
//     }
//     void insertAtMid(Node *&head, Node *&tail)
//     {
//         int value;
//         cout << "Value to insert at mid: ";
//         cin >> value;

//         int pos;
//         cout << "Enter position to insert: ";
//         cin >> pos;

//         if (head == NULL)
//         {
//             if (pos == 1)
//             {
//                 Node *temp = new Node;
//                 temp->data = value;
//                 head = temp;
//                 tail = temp;
//                 cout << "inserted at mid successfully." << endl;
//             }
//             else
//             {
//                 cout << "LL is empty, enter valid position" << endl;
//             }
//         }
//         else if (pos < 1 || pos > findLength(head)+1)
//         {
//             cout << "input position is not valid!" << endl;
//             return;
//         }
//         else
//         {
//             Node *temp = new Node;
//             temp->data = value;
//             Node *prev = NULL;
//             Node *curr = head;
//             while (pos != 1)
//             {
//                 prev = curr;
//                 curr = curr->next;
//                 pos--;
//             }
//             prev->next = temp;
//             temp->next = curr;
//             cout << "inserted at mid successfully:)" << endl;
//         }
//     }
//     void deleteAtHead(Node *&head, Node *&tail)
//     {
//         if(head == tail)
//         {
//             Node* temp = head;
//             delete temp;
//             head = NULL;
//             temp = NULL;
//             return ;
//         }
//         else if (head == NULL)
//         {
//             cout << "LL is empty! can't delete head node" << endl;
//         }
//         else
//         {
//             Node *temp = head;
//             head = head->next;
//             temp->next = NULL;
//             delete temp;            // destructor is called when delete is there;
//         }
//     }
//     void deleteAtTail(Node *&head, Node *&tail)
//     {
//         if(head == tail)
//         {
//             Node* temp = head;
//             delete temp;

//             head = NULL;
//             tail = NULL;
//             return ;
//         }
//         else if (head == NULL)
//         {
//             cout << "LL is empty! can't delete tail node." << endl;
//             return;
//         }
//         Node *prev = head;
//         while (prev->next != tail)
//         {
//             prev = prev->next;
//         }
//         delete tail;
//         prev->next = NULL;
//         tail = prev;
//     }
//     void deleteAtMid(Node *&head, Node *&tail)
//     {
//         int pos;
//         cout << "Enter position to delete at mid: ";
//         cin >> pos;

//         if(head == tail)
//         {
//             Node* temp = head;
//             delete temp;
//             head = NULL;
//             tail = NULL;
//         }
//         else if (head == NULL)
//         {
//             cout << "Can't delete from mid! LL is empty";
//             return;
//         }
//         else if (pos < 1 || pos > findLength(head))
//         {
//             cout << "pos is not valid!" << endl;
//             return;
//         }
//         else
//         {
//             Node *temp = head;
//             Node *prev = NULL;
//             while (pos != 1)
//             {
//                 prev = temp;
//                 temp = temp->next;
//                 pos--;
//             }
//             if (prev == NULL)
//             {
//                 head = head->next;
//                 temp->next = NULL;
//                 delete temp;
//             }
//             else
//             {
//                 prev->next = temp->next;
//                 temp->next = NULL;
//                 delete temp;
//             }
//         }
//     }
//     int findLength(Node *head)
//     {
//         Node *temp = head;
//         int count = 0;
//         while (temp)
//         {
//             count++;
//             temp = temp->next;
//         }
//         return count;
//     }
//     void display(Node *head)
//     {
//         cout << "Displaying LL: ";
//         if (head == NULL)
//         {
//             cout << "LL is empty! can't display()" << endl;
//             return;
//         }
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         cout << endl;
//         delete temp;
//     }
// } *head = NULL, *tail = NULL;

// int main()
// {
//     Node linkedlist;

//     // linkedlist.insertAtMid(head, tail);
//     // linkedlist.display(head);

//     // linkedlist.insertAtHead(head, tail);
//     // linkedlist.display(head);

//     // linkedlist.insertAtTail(head, tail);
//     // linkedlist.display(head);

//     // linkedlist.deleteAtHead(head, tail);
//     // linkedlist.display(head);

//     // linkedlist.deleteAtMid(head, tail);
//     // linkedlist.display(head);

//     // linkedlist.insertAtHead(head, tail);
//     // linkedlist.display(head);

//     return 0;
// }

// Revision

#include <iostream>
#include <climits>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iomanip>

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
    void deleteNode(Node *head)
    {
        cout << "pos to delete: ";
        int pos;
        cin >> pos;

        if (head == NULL)
        {
            cout << "LL is empty! can't delete" << endl;
        }
        else if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        else
        { // 20 10        pos = 2;
            Node *curr = head;
            Node *prev = NULL;
            while (pos != 1)
            {
                prev = curr;
                curr = curr->next;
                pos--;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        display(head);
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

    linkedlist.deleteNode(head);
    linkedlist.deleteNode(head);
    linkedlist.deleteNode(head);

    return 0;
}