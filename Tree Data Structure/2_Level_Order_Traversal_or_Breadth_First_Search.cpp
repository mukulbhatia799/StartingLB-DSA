#include<iostream>
#include<queue>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;
public:
    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node* Create(queue<int> &q) {
        if(q.empty() || q.front() == -1) {
            q.pop();
            return NULL;
        }

        Node* newnode = new Node;
        newnode->data = q.front();
        q.pop();
        newnode->left = Create(q);
        newnode->right = Create(q);
        return newnode;
    }
    void print_Level(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        cout << q.size() << endl;
        while(q.size() != 1)     // if q.size() == 1 means there is only NULL.
        {
            if(q.front() == NULL) {
                cout << endl;
                q.push(NULL);
                q.pop();
            } else {
                cout << q.front()->data << " ";
                if(q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
    }
} *root = NULL;

int main(){
    int arr[] = {10, 20, 30, -1, -1, 40, -1, -1, 50, -1, 60, -1, 70, -1, -1};
    int size = sizeof(arr) / sizeof(int);

    queue<int> q;   // store array in queue.
    for(int i = 0; i < size; i++) q.push(arr[i]);

    Node tree1;
    root = tree1.Create(q);

    cout << "---Printing tree level-wise---" << endl;
    tree1.print_Level(root);

    return 0;
}





// revision
/*

#include<iostream>
#include<queue>
using namespace std;

class TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode* Create(queue<int> &q)
    {
        if(q.empty() || q.front() == -1) return NULL;

        TreeNode* newnode = new TreeNode;
        newnode->data = q.front();
        q.pop();
        newnode->left = Create(q);
        q.pop();
        newnode->right = Create(q);
        return newnode;
    }
    void print_Level(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        cout << "-> ";
        while(q.size() > 1) {
            if(q.front() == NULL) {
                cout << "\n-> ";
                q.push(NULL);
                q.pop();
            } else {
                cout << q.front()->data << " ";
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
        }
    }
    void print(TreeNode* root) {
        cout << "root: " << root->data << endl;
        cout << "root->left->right: " << root->left->right->data << endl;
        cout << "root->right: " << root->right->data << endl;
    }
} *root = NULL;

int main() {
    TreeNode tree;
    queue<int> q;
    int arr[] = {1, 2, -1, 3, -1, -1, 4, 1, -1, -1, -1};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++) q.push(arr[i]);
    root = tree.Create(q);

    tree.print(root);

    cout << "---- print Levels---- " << endl;
    tree.print_Level(root);

    return 0;
}

*/