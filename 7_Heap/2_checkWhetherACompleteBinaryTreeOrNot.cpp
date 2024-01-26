// C.B.T is a tree where each level/row is full and last row have all of the nodes at leftmost side.

#include<iostream>
#include<queue>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;
public:
    Node() {
        this->data = 0;
        this->left = 0;
        this->right = 0;
    }
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node* create() {
        int value;
        cout << "Enter value(-1 or NULL.)" << endl;
        cin >> value;

        if(value == -1) {
            return NULL;
        }
        Node* newnode = new Node(value);
        newnode->left = create();
        newnode->right = create();
        return newnode;
    }
    bool checkCBTorNot(Node* root) {
        queue<Node*> q;
        q.push(root);

        bool checkptr = false;
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            if(front == NULL) {
                checkptr = true;
            }
            else {
                if(checkptr) return false;
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};

int main() {
    Node cbt;
    Node* root = cbt.create();      // [10 -1 30 -1 -1] is not a CBT and [10, 20, -1, -1, 30, -1, -1] is a CBT.

    bool check = cbt.checkCBTorNot(root);
    if(check) cout << "yes, CBT" << endl;
    else cout << "not a CBT" << endl;

    return 0;
}