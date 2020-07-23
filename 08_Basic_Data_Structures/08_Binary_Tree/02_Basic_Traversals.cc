#include<iostream>
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

node *buildTree() {
    int d;
    cin >> d;
    if(d == -1) return NULL;
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(node *root) {
    if(root == NULL) return;
    // Root -> Left -> Right
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void inorder(node *root) {
    if(root == NULL) return;
    // Left -> Root -> Right
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}

void postorder(node *root) {
    if(root == NULL) return;
    // Left -> Right -> Root
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    return;
}

int main() {
    node *root = buildTree();
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;    
}