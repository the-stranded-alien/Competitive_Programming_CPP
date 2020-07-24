#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

void levelOrderBuild(node*&root){
	cout << "Enter Root Data : " << endl;
	int d;
	cin >> d;
	root = new node(d);
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		node* n = q.front();
		q.pop();
		int c1,c2;
		cout << "Enter children of : " << n->data << endl;
		cin >> c1 >> c2;
		if(c1 != -1){
			n->left = new node(c1);
			q.push(n->left);
		}
		if(c2 != -1){
			n->right = new node(c2);
			q.push(n->right);
		}
	}
    return;
}

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

istream& operator>>(istream &is, node *&root){
	levelOrderBuild(root);
	return is;
}

ostream& operator<<(ostream &os, node *root){
	levelOrderPrint(root);
	return os;
}

// Assumption -> Both 'a' & 'b' Are Present In The Tree And All Keys Are Unique.
node *lca(node *root, int a, int b) {
    if(root == NULL) return NULL;
    if(root->data == a or root->data == b) return root;
    // Search In Left & Right Subtrees
    node *leftAns = lca(root->left, a, b);
    node *rightAns = lca(root->right, a, b);
    if(leftAns != NULL && rightAns != NULL) return root;
    if(leftAns != NULL) return leftAns;
    else return rightAns;
}

// Finding The Level Of A Given Node From The Root Node / Any Given Node
int search(node *root, int key, int level) {
    if(root == NULL) return -1;
    if(root->data == key) return level;
    int left = search(root->left, key, level + 1);
    if(left != -1) return left;
    return search(root->right, key, level + 1);
}

// Find The Shortest Distance Between Two Nodes
int findDistance(node *root, int a, int b) {
    node *lca_node = lca(root, a, b);
    int l1 = search(lca_node, a, 0);
    int l2 = search(lca_node, b, 0);
    return (l1 + l2);
}

int main(){
	node* root = NULL;
    cin >> root;
    cout << root;
    cout << "Distance Between 7 & 9 Is : " << findDistance(root, 7, 9) << endl;
	return 0;
}