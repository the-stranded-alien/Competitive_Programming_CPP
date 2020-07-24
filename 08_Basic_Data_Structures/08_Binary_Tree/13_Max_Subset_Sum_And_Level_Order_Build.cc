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

node* buildTree(){
	int d;
	cin>>d;
	if(d == -1) return NULL;
	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();
	return n;
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

istream& operator>>(istream&is,node*&root){
	root = buildTree();
    // root = levelOrderBuild();
	return is;
}

ostream& operator<<(ostream&os,node*root){
	level_order_bfs(root);
	return os;
}

//MaxSubsetSum - Include Either Node Or It's Child In The Sum.
class Pair{
public:
	int inc;
	int exc;
};

Pair maxSubsetSum(node*root){
	Pair p;
	if(root == NULL){
		p.inc = 0; 
        p.exc = 0;
		return p;
	}
	//Post order
	Pair L = maxSubsetSum(root->left);
	Pair R = maxSubsetSum(root->right);

	p.inc = root->data + L.exc + R.exc;
	p.exc = max(L.inc,L.exc) + max(R.inc, R.exc);
	return p;
}

int main(){
	node* root = NULL;
    cin >> root;
    cout << root;
    Pair ans = maxSubsetSum(root);
	cout << "Maxisum Subset Sum : " << max(ans.inc, ans.exc) <<endl;
    cout << "Level Order Build : \n";
    node *lvl;
    levelOrderBuild(lvl);
    cout << lvl;
	return 0;
}