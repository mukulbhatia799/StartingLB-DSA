#include<bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node* next;
    Node* head;
public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->head = NULL;
    }
    void sizeOfList()
    {
        Node* temp = head;
        int count = 0;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        cout << "Current size of List is " << count << endl;
    }
    void insertAtHead()
    {
        Node* temp = new Node;
        cout << "Enter value to insert at head: ";
        cin >> temp->data;
        temp->next = head;
        head = temp;
    }
    void insertAtEnd()
    {
        Node* temp = new Node;
        Node* temp2 = head;
        cout << "Enter value to insert at end: ";
        cin >> temp->data;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    void display()
    {
        Node* temp = head;
        cout << "Displaying linked list: ";
        while(temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Node obj;
    obj.insertAtEnd();
    obj.insertAtEnd();
    obj.insertAtEnd();
    obj.display();
    obj.sizeOfList();
    obj.insertAtEnd();
    obj.insertAtHead();
    obj.display();
    obj.sizeOfList();
    

    return 0;
}