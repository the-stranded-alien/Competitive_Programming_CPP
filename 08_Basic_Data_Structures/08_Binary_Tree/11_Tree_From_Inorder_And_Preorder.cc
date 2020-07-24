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

node *createTreeFromInorderAndPreorder(int *inorder, int *preorder, int s, int e) {
    static int i = 0;
    // Base Case
    if(s > e) return NULL;
    // Recursive Case
    node *root = new node(preorder[i]);
    int index = -1;
    for(int j = s; j <= e; j++) {
        if(inorder[j] == preorder[i]) {
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromInorderAndPreorder(inorder, preorder, s, index - 1);
    root->right = createTreeFromInorderAndPreorder(inorder, preorder, index + 1, e);
    return root;
}

void level_order_bfs(node *root) {
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

int main() {
    int inorder[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int preorder[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(inorder) / sizeof(int);
    node *root = createTreeFromInorderAndPreorder(inorder, preorder, 0, n - 1);
    level_order_bfs(root);
    return 0;    
}