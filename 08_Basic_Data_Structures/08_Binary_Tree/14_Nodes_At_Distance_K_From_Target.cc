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

void printAtLevelK(node *root, int k) {
    if(root == NULL) return;
    if(k == 0) {
        cout << root->data << " ";
        return;
    }
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
    return;
}

int printAtDistanceK(node *root, node *target, int k) {
    // Base Case
    if(root == NULL) return -1;
    // Reach The Target Node
    if(root == target) {
        printAtLevelK(target, k);
        return 0;
    }
    // Next Step -> Some Ancestor Node
    int DL = printAtDistanceK(root->left, target, k);
    if(DL != -1) {
        // Again There Are Two Cases !
        // Ancestor Itself Or Go To The Right Ancestor
        if(DL + 1 == k) cout << root->data << " ";
        else printAtLevelK(root->right, k - 2 - DL);
        return (1 + DL);
    }
    int DR = printAtDistanceK(root->right, target, k);
    if(DR != -1) {
        if(DR + 1 == k) cout << root->data << " ";
        else printAtLevelK(root->left, k - 2 - DR);
        return (1 + DR);
    }
    // Node Was Not Present In Left Or Right Subtree Of Given Tree
    return -1;
}

int main(){
	node* root = NULL;
    cin >> root;
    node *target = root->left->left;
    cout << root;
    int k;
    cin >> k;
    printAtDistanceK(root, target, k);
	return 0;
}