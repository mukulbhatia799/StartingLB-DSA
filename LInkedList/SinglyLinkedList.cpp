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
//         else if (pos < 1 || pos > findLength(head))
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