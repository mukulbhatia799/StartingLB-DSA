/*
two ways to find height.
1. find left height and right height count. and return the maximum.
2. second method of level order traversal and count each level which is equal to height of a tree.
*/

#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    int countDepth(TreeNode *, int);
    int maxDepth(TreeNode *);
    TreeNode *Create(queue<int> q);
} *root = NULL;

TreeNode *TreeNode::Create(queue<int> q)
{
    if (q.empty() || q.front() == -1)
    {
        q.pop();
        return NULL;
    }

    TreeNode *newnode = new TreeNode;
    newnode->data = q.front();
    q.pop();
    newnode->left = Create(q);
    newnode->right = Create(q);
    return newnode;
}

int TreeNode::countDepth(TreeNode *root, int count)
{
    if (root == NULL)
        return count;
    count++;
    return max(countDepth(root->left, count), countDepth(root->right, count));
}

int TreeNode::maxDepth(TreeNode *root)
{
    return countDepth(root, 0);
}

int main()
{
    int arr[] = {10, 20, 30, -1, -1, 40, -1, -1, 50, -1, 60, -1, 70, -1, -1};
    int size = sizeof(arr) / sizeof(int);

    queue<int> q; // store array in queue.
    for (int i = 0; i < size; i++)
        q.push(arr[i]);

    TreeNode tree1;
    cout << "MaxDepth of a tree: " << tree1.maxDepth(root) << endl;

    return 0;
}