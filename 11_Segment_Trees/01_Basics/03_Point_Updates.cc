#include<iostream>
#include<climits>
using namespace std;

void buildTree(int *a, int s, int e, int *tree, int index) {
    // Base Case
    if(s == e) {
        tree[index] = a[s];
        return;
    }
    // Recursive Case
    int mid = (s + e) / 2;
    buildTree(a, s, mid, tree, (2 * index));
    buildTree(a, (mid + 1), e, tree, ((2 * index) + 1));
    tree[index] = min(tree[2 * index], tree[(2 * index) + 1]);
    return; 
}

int query(int *tree, int ss, int se, int qs, int qe, int index) {
    // Complete Overlap
    if((ss >= qs) && (se <= qe)) return tree[index];
    // No Overlap
    if((qe < ss) || (qs > se)) return INT_MAX;
    // Partial Overlap
    int mid = (ss + se) / 2;
    int left = query(tree, ss, mid, qs, qe, (2 * index));
    int right = query(tree, (mid + 1), se, qs, qe, (2 * index + 1));
    return min(left, right);
}

void pointUpdate(int *tree, int ss, int se, int i, int increment, int index) {
    // Case Where The 'i' Is Out Of Bounds
    if((i > se) || (i < ss)) return;
    // Leaf Node
    if(ss == se) {
        tree[index] += increment;
        return;
    }
    // Otherwise
    int mid = (ss + se) / 2;
    pointUpdate(tree, ss, mid, i, increment, (2 * index));
    pointUpdate(tree, (mid + 1), se, i, increment, ((2 * index) + 1));
    tree[index] = min(tree[2 * index], tree[(2 * index) + 1]);
    return;
}

int main() {
    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a) / sizeof(int);
    int *tree = new int[4 * n + 1];
    buildTree(a, 0, (n - 1), tree, 1);
    pointUpdate(tree, 0, (n - 1), 3, 10, 1);
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << query(tree, 0, (n - 1), l, r, 1) << endl;
    }
    return 0;
}