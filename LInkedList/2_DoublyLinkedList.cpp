// Doubly Linked List

// #include <iostream>
// using namespace std;

// class Node
// {
//     int data;
//     Node *next;
//     Node *prev;

// public:
//     Node()
//     {
//         data = 0;
//         next = NULL;
//         prev = NULL;
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
//             head->prev = temp;
//             head = temp;
//         }
//         display(head);
//     }
//     void insertAtTail(Node *&head, Node *&tail)
//     {
//         int value;
//         cout << "value to insert at tail: ";
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
//             tail->next = temp;
//             temp->prev = tail;
//         }
//         display(head);
//     }
//     void insertAtMid(Node *&head, Node *&tail) // ******** issue to insert. ********
//     {
//         int value;
//         cout << "value to insert at mid: ";
//         cin >> value;

//         int pos;
//         cout << "position to insert at mid: ";
//         cin >> pos;
//         if (pos < 1 && pos > findLength(head) + 1)
//         {
//             cout << "position is not valid to insert at mid!" << endl;
//         }
//         if (head == NULL)
//         {
//             if (pos == 1)
//             {
//                 Node *temp = new Node;
//                 temp->data = value;
//                 head = temp;
//                 tail = temp;
//             }
//             else
//             {
//                 cout << "position is not valid!" << endl;
//             }
//         }
//         else
//         {
//             Node *temp = new Node;
//             temp->data = value;
//             Node *curr = head;
//             while (pos != 1)
//             {
//                 curr = curr->next;
//                 pos--;
//             }
//             temp->next = curr;
//             temp->prev = curr->prev;
//             curr->prev = temp;
//             (curr->prev)->next = temp;
//         }
//         display(head);
//     }
//     void deleteHead(Node *&head, Node *&tail)
//     {
//         if (head == NULL)
//         {
//             cout << "LL empty! can't delete from head." << endl;
//         }
//         else if (head == tail)
//         {
//             Node *temp = head;
//             delete temp;
//             head = NULL;
//             tail = NULL;
//         }
//         else
//         {
//             Node *temp = head;
//             head = head->next;
//             temp->next = NULL;
//             delete temp;
//         }
//         display(head);
//     }
//     void deleteTail(Node *&head, Node *&tail)
//     {
//         if (tail == NULL)
//         {
//             cout << "LL empty! can't delete from tail." << endl;
//         }
//         else if (head == tail)
//         {
//             Node *temp = tail;
//             delete temp;
//             head = NULL;
//             tail = NULL;
//         }
//         else
//         {
//             Node *temp = tail;
//             tail = tail->prev;
//             tail->next = NULL;
//             delete temp;
//         }
//         display(head);
//     }
//     void deleteMid(Node *&head, Node *&tail)
//     {
//         int pos;
//         cout << "Enter position to delete: ";
//         cin >> pos;

//         int len = findLength(head);
//         if (pos < 1 || pos > len)
//         {
//             cout << "LL size is " << len << ". Enter valid position." << endl;
//         }
//         else if (head == NULL)
//         {
//             cout << "LL is empty! can't delete from mid." << endl;
//             return;
//         }
//         else if (head == tail)
//         {
//             if (pos == 1)
//             {
//             }
//         }
//         display(head);
//     }
//     int findLength(Node *head)
//     {
//         int count = 0;
//         Node *temp = head;
//         while (temp)
//         {
//             count++;
//             temp = temp->next;
//         }
//         delete temp;
//         return count;
//     }
//     void display(Node *head)
//     {
//         cout << "displaying list: ";
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

//     linkedlist.insertAtHead(head, tail);
//     cout << "curr LL length: " << linkedlist.findLength(head) << endl;
//     linkedlist.insertAtTail(head, tail);
//     cout << "curr LL length: " << linkedlist.findLength(head) << endl;
//     linkedlist.insertAtMid(head, tail);
//     cout << "curr LL length: " << linkedlist.findLength(head) << endl;
//     linkedlist.insertAtHead(head, tail);
//     cout << "curr LL length: " << linkedlist.findLength(head) << endl;

//     linkedlist.deleteHead(head, tail);
//     cout << "curr LL length: " << linkedlist.findLength(head) << endl;
//     linkedlist.deleteTail(head, tail);

//     return 0;
// }

// bugs in code. ******************





// doubly linked list
#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    void insert(Node *&head)
    {
        cout << "====================" << endl;
        int val, pos;
        cout << "insert: ";
        cin >> val;
        cout << "pos(1 to n): ";
        cin >> pos;

        Node *temp = new Node;
        temp->data = val;
        int len = findLength(head);
        cout << "len: " << len << endl;
        if(pos < 1 || pos > len+1) {
            cout << "pos not valid!" << endl;
        }
        else if (head == NULL)
        {
            head = temp;
        }
        else if (pos == 1)
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else if (pos == len + 1)
        {
            pos = pos - 1;
            Node *curr = head;
            while (pos != 1)
            {
                curr = curr->next;
                pos--;
            }
            curr->next = temp;
            temp->prev = curr;
        }
        else
        {
            Node *curr = head;
            Node *back = NULL;
            while (pos != 1)
            {
                back = curr;
                curr = curr->next;
                pos--;
            }
            back->next = temp;
            temp->prev = back;
            temp->next = curr;
            curr->prev = temp;
        }
        display(head);
    }
    int findLength(Node *head)
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    void display(Node *head)
    {
        if(head == NULL)
        {
            cout << "can't display! empty LL" << endl;
        }
        cout << "Displaying LL: ";
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node* lastNode(Node* head)
    {
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp;
    }
    void displayFromLast(Node* tail)
    {
        if(tail == NULL)
        {
            cout << "empty LL, can't display from last" << endl;

            return ;
        }
        cout << "Displaying from last: ";
        Node* temp = tail;
        while(temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << " " << endl;
    }
} *head = NULL;

int main()
{
    Node ll;
    ll.insert(head);
    ll.insert(head);
    ll.insert(head);

    Node* tail = ll.lastNode(head);

    ll.displayFromLast(tail);

    return 0;
}