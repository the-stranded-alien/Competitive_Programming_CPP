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

void inOrderPrint(node *root) {
    if(root == NULL) return;
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
    return;
}

node *insertInBST(node *root, int data) {
    if(root == NULL) return new node(data);
    if(data <= root->data) root->left = insertInBST(root->left, data);
    else root->right = insertInBST(root->right, data);
    return root;
}

node *build() {
    int d;
    cin >> d;
    node *root = NULL;
    while(d != -1) {
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}

bool search(node *root, int key) {
    if(root == NULL) return false;
    if(root->data == key) return true;
    // Recursively Search In Left & Right Subtree
    if(key <= root->data) return search(root->left, key);
    else return search(root->right, key);
}

int main() {
    node *root = build();
    cout << "\nIn-Order Print : ";
    inOrderPrint(root);
    cout << endl;
    int key;
    cin >> key;
    if(search(root, key)) cout << "Present\n";
    else cout << "Not Present\n";
    return 0;
}