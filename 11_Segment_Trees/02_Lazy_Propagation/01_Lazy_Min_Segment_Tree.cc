#include<iostream>
#include<climits>
using namespace std;

int lazy[10000] = {0};

void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index) {
    // Before Going Down Resolve The Lazy Value If It Exists
    if(lazy[index] != 0) {
        tree[index] += lazy[index];
        // For Non Leaf Nodes, Pass The Lazy Values To Children
        if(ss != se) {
            lazy[2 * index] += lazy[index];
            lazy[(2 * index) + 1] += lazy[index];
        }
        lazy[index] = 0; // Clear The Lazy Value At Current Node
    }
    // Base Case / No Overlap
    if((ss > r) || (l > se)) return;
    // Another Case / Complete Overlap
    if((ss >= l) && (se <= r)) {
        tree[index] += inc;
        // Create A New Lazy Value Of Children Nodes
        if(ss != se) {
            lazy[2 * index] += inc;
            lazy[(2 * index) + 1] += inc;
        } 
        return;
    }
    // Recursive Case / Partial Overlap
    int mid = (ss + se) / 2;
    updateRangeLazy(tree, ss, mid, l, r, inc, (2 * index));
    updateRangeLazy(tree, (mid + 1), se, l , r, inc, ((2 * index) + 1));
    // Update The Current Node : tree[index]
    tree[index] = min(tree[2 * index], tree[(2 * index) + 1]);
    return;
}

int queryLazy(int *tree, int ss, int se, int qs, int qe, int index) {
    // Before Going Down Resolve The Lazy Value If It Exists At Current Node
    if(lazy[index] != 0) {
        tree[index] += lazy[index];
        // For Non Leaf Nodes, Pass The Lazy Values To Children
        if(ss != se) {
            lazy[2 * index] += lazy[index];
            lazy[(2 * index) + 1] += lazy[index];
        }
        lazy[index] = 0; // Clear The Lazy Value At Current Node
    }
    // Query Logic
    // No Overlap
    if((ss > qe) || (se < qs)) return INT_MAX;
    // Complete Overlap
    if((ss >= qs) && (se <= qe)) return tree[index];
    // Partial Overlap
    int mid = (ss + se) / 2;
    int left = queryLazy(tree, ss, mid, qs, qe, (2 * index));
    int right = queryLazy(tree, (mid + 1), se, qs, qe, ((2 * index) + 1));
    return min(left, right);
}

void buildTree(int *arr, int s, int e, int *tree, int index) {
    // Base Case
    if(s == e) {
        tree[index] = arr[s];
        return;
    }
    // Recursive Case
    int mid = (s + e) / 2;
    buildTree(arr, s, mid, tree, (2 * index));
    buildTree(arr, (mid + 1), e, tree, ((2 * index) + 1));
    tree[index] = min(tree[2 * index], tree[(2 * index) + 1]);
    return;
}

int main() {
    int arr[] = {1, 3, 2, -5, 6, 4};
    int n = (sizeof(arr) / sizeof(int));
    int *tree = new int[(4 * n) + 1];
    buildTree(arr, 0, (n - 1), tree, 1);
    updateRangeLazy(tree, 0, (n - 1), 0, 2, 10, 1);
    updateRangeLazy(tree, 0, (n - 1), 0, 4, 10, 1);
    cout << "Q1 : 1-1 -> " << queryLazy(tree, 0, (n - 1), 1, 1, 1) << endl;
    updateRangeLazy(tree, 0, (n - 1), 3, 4, 10, 1);
    cout << "Q2 : 3-5 -> " << queryLazy(tree, 0, (n - 1), 3 , 5, 1) << endl;
    return 0;
}