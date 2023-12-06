// Doubly Linked List

#include<iostream>
using namespace std;

class Node {
    int data;
    Node* next;
    Node* prev;
public:
    void insertAtHead(Node* head, Node* tail)
    {

    }
    void insertAtTail(Node* head, Node* tail)
    {

    }
    void insertAtMid(Node* head, Node* tail)
    {

    }
    void deleteHead(Node* head, Node* tail)
    {

    }
    void deleteTail(Node* head, Node* tail)
    {

    }
    void deleteMid(Node* head, Node* tail)
    {

    }
    int findLength(Node* head, Node* tail)
    {
        int count = 0;
        Node* temp = head;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        delete temp;
        return count;
    }
    void display(Node* head)
    {
        cout << "displaying list: ";
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
        delete temp;
    }
} *head = NULL, *tail = NULL;

int main(){
    Node linkedlist;

        

    return 0;
}