#include<bits/stdc++.h>
using namespace std;
 
class Node
{
public:
    int data;
    Node* next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        
    }
    void display()
    {
        Node* temp = this;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    cout << "New display: ";
    first->display();  

    Node* fifth = new Node;
    fourth->next = fifth;
    fifth->next = NULL;

    cout << "New display: ";

    first->display();

    return 0;
}