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

int main(){
	node* root = NULL;
    cin >> root;
    cout << root;
    cout << "LCA OF 4 & 7 Is : " << lca(root, 4, 7)->data << endl;
    cout << "LCA OF 6 & 9 Is : " << lca(root, 6, 9)->data << endl;
    cout << "LCA OF 4 & 11 Is : " << lca(root, 4, 11)->data << endl;
	return 0;
}