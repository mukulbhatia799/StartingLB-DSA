#include <iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;       // we can make data attributres private but then we have to send the min and max value rather than there pointers.
    Node *left;
    Node *right;
    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    void createBST(Node*&);
    Node* insertBST(Node*, int);
    void levelOrderTraversal(Node*);
    Node* deleteNodeInBST(Node*&, int);
    Node* maxNodeInBST(Node*);
    Node* minValueInBST(Node*);
    Node* findValueInBST(Node*, int);
    Node* BSTfromInorder(int[],int, int);
};

Node* Node::insertBST(Node *root, int data)
{
    if(root == NULL) {  // if BST is empty then create root node.
        root = new Node(data);
        return root;
    } else {
        if(data > root->data) { // if data is less than root->data then go right
            root->right = insertBST(root->right, data);
        } else { // else go left.
            root->left = insertBST(root->left, data);
        }
    }
}

void Node::createBST(Node* &root)
{
    int value;
    cout << "Enter value(-1 to exit): ";
    cin >> value;

    while(value != -1)
    {
        root = insertBST(root, value);      // insert value in BST.
        cout << "Enter value(-1 to exit): ";
        cin >> value;
    }
}

void Node::levelOrderTraversal(Node* root)
{
    if(root == NULL) {
        cout << "emtpy BST" << endl;
        return ;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();
        if(front == NULL) {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        } else {
            cout << front->data << " ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}

Node* Node::deleteNodeInBST(Node* &root, int target)
{
    if(root == NULL) return NULL;
    if(target == root->data) {
        // There can be four cases to delete a node from BST.

        // 1st case: Both root->left and root->right child is NULL.
        if(root->left == NULL && root->right == NULL) {
            Node* deletenode = root;
            delete deletenode;
            return NULL;
        }

        // 2nd case: root->left is not NULL but root->right is NULL.
        else if(root->left != NULL && root->right == NULL) {
            Node* deletenode = root;
            delete deletenode;
            return root->right;
        }
        // 3rd case: root->left is NULL but root->right is not NULL.
        else if(root->left == NULL && root->right != NULL) {
            Node* deletenode = root;
            delete deletenode;
            return root->right;
        }
        // 4th case: Both root->left and root->right child is not NULL.
        // Here either find the maximum element in left subtree and place in root->data or minimum element in right subtree and place in root->data.
        else {
            Node* maxEleInLeftSubTree = maxNodeInBST(root->left);
            root->data = maxEleInLeftSubTree->data;
            root->left = deleteNodeInBST(root->left, maxEleInLeftSubTree->data);
            return root;
        }
    } 
    else if(target < root->data) {
        root->left = deleteNodeInBST(root->left, target);
    } 
    else {
        root->right = deleteNodeInBST(root->right, target);
    }
    return root;
}

Node* Node::maxNodeInBST(Node* root)
{
    if(root == NULL) return NULL;

    if(root->right == NULL) return root;    // if last root->right found then return 

    return maxNodeInBST(root->right);   // as the values greater than root->data is on right so always go right.
}

Node* Node::minValueInBST(Node* root)
{
    if(root == NULL) return NULL;
    if(root->left == NULL) return root;

    return minValueInBST(root->left);   // as the values lesser than root->data is on left so always go on left.
}

Node* Node::findValueInBST(Node* root, int target)
{
    if(root == NULL) return NULL;
    if(root->data == target) return root;

    Node* left = findValueInBST(root->left, target);
    Node* right = findValueInBST(root->right, target);
    return left?left:right;
}

Node* Node::BSTfromInorder(int inorder[], int l, int r)
{
    if(l > r) return NULL;

    int mid = l + (r-l)/2;
    int element = inorder[mid];
    Node* newnode = new Node(element);

    newnode->left = BSTfromInorder(inorder, l, mid-1);
    newnode->right = BSTfromInorder(inorder, mid+1, r);
    return newnode;
}

int main()
{
    /*
    Node bst;
    Node* root = NULL;
    bst.createBST(root);
    bst.levelOrderTraversal(root);

    Node* maxNode = bst.maxNodeInBST(root);
    if(maxNode) cout << "Max value: " << maxNode->data << endl;
    else cout << "max not found!!" << endl;
    
    Node* minvalue = bst.minValueInBST(root);
    if(minvalue) cout << "Min value: " << minvalue->data << endl;
    else cout << "min not found!!" << endl;

    int target;
    cout << "Enter target to find in BST: ";
    cin >> target;
    Node* findTarget = bst.findValueInBST(root, target);
    if(findTarget) cout << "Target found!!" << endl;
    else cout << "Target not found!!" << endl;

    cout << "Enter target to delete from BST(-1 to exit): ";
    cin >> target;
    while(target != -1)
    {
        bst.deleteNodeInBST(root, target);
        cout << "Enter target to delete from BST(-1 to exit): ";
        cin >> target;
    }
    bst.levelOrderTraversal(root);

    */

   /*
    
    cout << "BST from inorder" << endl;
    Node* bst2;
    int inorder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(inorder)/sizeof(int);
    int left = 0, right = size-1;
    Node* root2 = bst2->BSTfromInorder(inorder, left, right);
    bst2->levelOrderTraversal(root2);
    
    */

    return 0;
}