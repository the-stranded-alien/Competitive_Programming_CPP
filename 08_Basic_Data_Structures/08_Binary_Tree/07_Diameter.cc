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

// Top-Down / Preorder Aproach O(N^2)
int diameter(node *root) {
    if(root == NULL) return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}

// Better Alternative O(N)
// Bottom-Up / Postorder Approach
class Pair {
public:
    int height;
    int diameter;
};

Pair fast_diameter(node *root) {
    Pair p;
    if(root == NULL) {
        p.diameter = 0;
        p.height = 0;
        return p;
    }
    Pair left = fast_diameter(root->left);
    Pair right = fast_diameter(root->right);
    p.height = (max(left.height, right.height) + 1);
    p.diameter = max((left.height + right.height), max(left.diameter, right.diameter));
    return p;
}

int main() {
    node *root = buildTree();
    cout << "Diameter : " << diameter(root) << endl;
    Pair p = fast_diameter(root);
    cout << "Diameter : " << p.diameter << endl;
    cout << "Height : " << p.height << endl;
    return 0;    
}