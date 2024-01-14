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
    TreeNode* Create()
    {
        // input -1 means NULL.
        int value;
        cout << "Enter value: ";
        cin >> value;

        if(value == -1) return NULL;
        TreeNode* newnode = new TreeNode;
        newnode->data = value;
        cout << "Enter left value of " << newnode->data << endl;
        newnode->left = Create();
        cout << "Enter right value of " << newnode->data << endl;
        newnode->right = Create();
        return newnode;
    }
    void printLevelsOfTree(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        cout << " -> ";
        while(q.size() > 1) {
            if(!q.empty() && q.front() == NULL) {
                cout << "\n -> ";
                q.push(NULL);
                q.pop();
            } else {
                cout << q.front()->data << " ";
                if(!q.empty()) q.push(q.front()->left);
                if(!q.empty()) q.push(q.front()->right);
                q.pop();
            }
        }
        cout << endl;
    }
    int HeightOfATree(TreeNode* root)
    {
        if(root == NULL) return 0;
        int lefttree = 1;
        lefttree += HeightOfATree(root->left);
        int righttree = 1;
        righttree += HeightOfATree(root->right);

        return max(lefttree, righttree);
    }
    int DiameterOfATree(TreeNode* root)
    {
        
    }
    
} *root = NULL;

int main(){
    TreeNode tree;
    root = tree.Create();

    cout << "---- printing levels of tree ----" << endl;
    tree.printLevelsOfTree(root);

    // cout << "Height of a tree: " << tree.HeightOfATree(root) << endl;

    return 0;
}