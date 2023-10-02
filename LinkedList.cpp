#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* next;
    Node* head;
public:
    Node(){
        this->data = 0;
        this->next = NULL;
        this->head = NULL;
    }
    void insertNode()
    {
        Node* newNode = new Node;
        cout << "\tInsert value: ";
        cin >> newNode->data;

        if(head == NULL)
        {
            newNode->next = NULL;
            head = newNode;
        }
        else 
        {
            newNode->next = head;
            head = newNode;
        }
        cout << "\t****Inserted :)****" << endl;
    }

    void deleteNode()
    {
        if(head == NULL) 
        {
            cout << "\t****No node to delete!!!****" << endl;
            return ;
        }
        Node* ptr = head;
        int delNode;
        cout << "\tEnter deleting node: ";
        cin >> delNode;
        if(delNode == 1) head = head->next;
        else 
        {
            while(delNode > 2)
            {
                ptr = ptr->next;
                delNode--;
            }
            ptr->next = ptr->next->next;
        }
        cout << "\t****Deleted :)****" << endl;
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "\t****Linked List is empty!!!****" << endl;
            return ;
        }
        cout << "Displaying Linked List: ";
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    
};

int main(){
    Node obj;

    char ch;
    do {
        cout << "\t==============================" << endl;
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> ch;
        switch(ch) {
            case '1':
                obj.insertNode();
                break;
            case '2':
                obj.deleteNode();
                break;
            case '3':
                obj.display();
                break;
            case '4':
                cout << "Bye :)" << endl;
                break;
            default:
                cout << "Enter valid input!!!" << endl;
                break;
        }
    }while(ch != '4');

    return 0;
}