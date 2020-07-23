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

int height(node *root) {
    if(root == NULL) return 0;
    int ls = height(root->left);
    int rs = height(root->right);
    return (max(ls, rs) + 1);
}

void printKthLevel(node *root, int k) {
    if(root == NULL) return;
    if(k == 1) {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}

void levelorder(node *root) {
    int H = height(root);
    for(int i = 1; i <= H; i++) {
        printKthLevel(root, i);
        cout << endl;
    }
    return;
}

int main() {
    node *root = buildTree();
    cout << "Height : " << height(root) << endl;
    cout << "Level Order : \n";
    levelorder(root);
    return 0;    
}