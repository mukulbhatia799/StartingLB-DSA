#include<iostream>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;
public:
    Node() {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int value) {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
    Node* create() {
        int value;
        cout << "Enter value(-1 for NULL value) in preorder: ";
        cin >> value;

        if(value == -1) return NULL;

        Node* newnode = new Node(value);
        newnode->left = create();
        newnode->right = create();
        return newnode;
    }
    bool ConvertBSTinMaxHeap(Node* root) {
        
    }
};

void main(){
    

    return ;
}