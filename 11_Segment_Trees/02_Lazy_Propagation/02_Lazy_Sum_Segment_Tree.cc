#include<iostream>
using namespace std;

int lazy[10000] = {0};

void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index) {
    // Before Going Down Resolve The Lazy Value If It Exists
    if(lazy[index] != 0) {
        tree[index] += ((se - ss + 1) * lazy[index]);
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
        tree[index] += ((se - ss + 1) * inc);
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
    tree[index] = (tree[2 * index] + tree[(2 * index) + 1]);
    return;
}

int querySumLazy(int *tree, int ss, int se, int qs, int qe, int index) {
    // Before Going Down Resolve The Lazy Value If It Exists At Current Node
    if(lazy[index] != 0) {
        tree[index] += ((se - ss + 1) * lazy[index]);
        // For Non Leaf Nodes, Pass The Lazy Values To Children
        if(ss != se) {
            lazy[2 * index] += lazy[index];
            lazy[(2 * index) + 1] += lazy[index];
        }
        lazy[index] = 0; // Clear The Lazy Value At Current Node
    }
    // Query Logic
    // No Overlap
    if((ss > qe) || (se < qs)) return 0;
    // Complete Overlap
    if((ss >= qs) && (se <= qe)) return tree[index];
    // Partial Overlap
    int mid = (ss + se) / 2;
    int leftSum = querySumLazy(tree, ss, mid, qs, qe, (2 * index));
    int rightSum = querySumLazy(tree, (mid + 1), se, qs, qe, ((2 * index) + 1));
    return (leftSum + rightSum);
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
    tree[index] = (tree[2 * index] + tree[(2 * index) + 1]);
    return;
}

int main() {
    int arr[] = {4, 6, 3, 1, 2, 8};
    int n = (sizeof(arr) / sizeof(int));
    int *tree = new int[(4 * n) + 1];
    buildTree(arr, 0, (n - 1), tree, 1);
    updateRangeLazy(tree, 0, (n - 1), 2, 4, 10, 1);
    cout << "Q1 : 2-3 -> " << querySumLazy(tree, 0, (n - 1), 2, 3, 1) << endl;
    cout << "Q2 : 2-4 -> " << querySumLazy(tree, 0, (n - 1), 2, 4, 1) << endl;
    cout << "Q3 : 0-5 -> " << querySumLazy(tree, 0, (n - 1), 0, 5, 1) << endl;
    return 0;
}