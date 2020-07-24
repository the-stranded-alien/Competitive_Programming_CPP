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

class Pair {
public:
    int branchSum;
    int maxSum;
    Pair() {
        branchSum = 0;
        maxSum = 0;
    }
};

Pair maxSumPath(node *root) {
    Pair p;
    if(root == NULL) return p;
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    int op1 = root->data;
    int op2 = left.branchSum + root->data;
    int op3 = right.branchSum + root->data;
    int op4 = left.branchSum + right.branchSum + root->data;
    int current_ans_through_root = max(op1, max(op2, max(op3, op4)));

    // Branch Sum Of Current Root
    p.branchSum = (max(left.branchSum, max(right.branchSum, 0)) + root->data);
    // Max Sum Of Current Root
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));

    return p;
}

int main(){
	node* root = NULL;
    cin >> root;
    cout << root;
    cout << "Max Sum Path : " << maxSumPath(root).maxSum << endl;
	return 0;
}