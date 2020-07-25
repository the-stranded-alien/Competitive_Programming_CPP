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

bool search(node *root, int key) {
    if(root == NULL) return false;
    if(root->data == key) return true;
    // Recursively Search In Left & Right Subtree
    if(key <= root->data) return search(root->left, key);
    else return search(root->right, key);
}

node *deleteInBST(node *root, int data) {
    if(root == NULL) return NULL;
    else if(data < root->data) {
        root->left = deleteInBST(root->left, data); 
        return root;
    }
    else if(data == root->data) {
        // Found The Node To Delete. There Would Be 3 Cases.
        // Case 1 -> Node With 0 Children (Leaf Node)
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2 -> Only 1 Child
        else if(root->left != NULL && root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL && root->right != NULL) {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // Case 3 -> Node With 2 Children
        else {
            node *replace = root->right;
            // Find The Inorder Successor From The Right Subtree.
            while(replace->left != NULL) replace = replace->left;
            root->data = replace->data;
            root->right = deleteInBST(root->right, replace->data);
            return root;
        }
    } 
    else {
        root->right = deleteInBST(root->right, data);
        return root;
    }
}

int main() {
    node *root = build();
    cout << "\nIn-Order Print : ";
    inOrderPrint(root);
    cout << endl;
    int s;
    cin >> s;
    cout << "Deleting : " << s << endl;
    root = deleteInBST(root, s);
    cout << "\nIn-Order Print After Deletion : ";
    inOrderPrint(root);
    cout << "\nLevel Order Print After Deletion : \n";
    levelOrderPrint(root);
    return 0;
}