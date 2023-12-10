#include<iostream>
using namespace std;

class Node {
    int val;
    Node* next = NULL;
public:
    Node* mergeTwoLists(Node* , Node* );
} *head = NULL;

Node* Node::mergeTwoLists(Node* list1, Node* list2) 
{
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    Node* temp1 = list1;
    Node* temp2 = list2;

    Node* newhead = NULL;
    Node* prev = NULL;

    while(temp1 != NULL && temp2 != NULL)
    {
        if(newhead == NULL)
        {
            if(temp1->val <= temp2->val)
            {
                prev = temp1;
                newhead = temp1;
                temp1 = temp1->next;
            }
            else {
                prev = temp2;
                newhead = temp2;
                temp2 = temp2->next;
            }
        }
        else {
            if(temp1->val <= temp2->val)
            {
                prev->next = temp1;
                prev = temp1;
                temp1 = temp1->next;
            }
            else {
                prev->next = temp2;
                prev = temp2;
                temp2 = temp2->next;
            }
        }
    }
    while(temp1 != NULL)
    {
        prev->next = temp1;
        prev = temp1;
        temp1 = temp1->next;
    }
    while(temp2 != NULL)
    {
        prev->next = temp2;
        prev = temp2;
        temp2 = temp2->next;
    }
    return newhead;
}

int main()
{
    // create LL and run merge function.
}
