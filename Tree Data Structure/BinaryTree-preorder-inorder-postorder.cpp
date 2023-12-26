#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* create()
{
    int value;
    cout << "Enter value, -1 if NULL: " << endl;
    cin >> value;

    if(value == -1) return NULL;

    Node* root = new Node(value);

    cout << "Input Left of " << value << endl;
    root->left = create();
    
    cout << "Input Right of " << value << endl;
    root->right = create();

    return root;
}

void preOrderTraversal(Node* root)
{
    if(root == NULL) {
        return ;
    }
    // N
    cout << root->data << " -> ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root)
{
    if(root == NULL) {
        return ;
    }
    // L
    inOrderTraversal(root->left);
    // N
    cout << root->data << " -> ";
    // R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root)
{
    if(root == NULL) {
        return ;
    }
    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data << " -> ";
}

int main(){
    Node* root = create();

    cout << "PreOrder Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "InOrder Traveral: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}