#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Print The BST Level By Level
void levelOrderPrint(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node *f = q.front();
        if(f == NULL) {
            cout << endl;
            q.pop();
            if(!q.empty()) q.push(NULL);
        } 
        else {
            cout << f->data << " ";
            q.pop();
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
    }
    return;
}

// Left -> Root -> Right
void inOrderPrint(node *root) {
    if(root == NULL) return;
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
    return;
}

// Accepts The Old Root Node & Data And Returns The New Root Node
node *insertInBST(node *root, int data) {
    // Base Case
    if(root == NULL) return new node(data);
    // Recursive Case -> Insert In The Subtree And Update The Pointers
    if(data <= root->data) root->left = insertInBST(root->left, data);
    else root->right = insertInBST(root->right, data);
    return root;
}

node *build() {
    // Read A List Of Numbers Till -1 And Also These Numbers Will Be Inserted Into BST
    int d;
    cin >> d;
    node *root = NULL;
    while(d != -1) {
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}

int main() {
    node *root = build();
    cout << "\nIn-Order Print : ";
    inOrderPrint(root);
    cout << "\nLevel Order Print : \n";
    levelOrderPrint(root);
    return 0;
}