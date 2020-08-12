#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 100005;
int a[N];

struct segment_tree_of_vectors {
    vector<int> st[N * 4];
    void build(int start, int end, int node) {
        if(start == end) {
            st[node].push_back(a[start]);
            return;
        }
        int mid = (start + end) / 2;
        // Left Tree
        build(start, mid, ((2 * node) + 1));
        // Right Tree
        build((mid + 1), end, ((2 * node) + 2));
        // merge() : Begin, End Of First And Second Vector & Final Vector
        merge(st[(2 * node) + 1].begin(), st[(2 * node) + 1].end(), st[(2 * node) + 2].begin(), st[(2 * node) + 2].end(), back_inserter(st[node]));
        return;
    }
    int query(int start, int end, int l, int r, int k, int node) {
        // No Overlap
        if((start > r) || (end < l)) return 0;
        // Complete Overlap
        if((start >= l) && (end <= r)) {
            return (st[node].size() - (upper_bound(st[node].begin(), st[node].end(), k) - st[node].begin()));
        }
        // Partial Overlap
        int mid = (start + end) / 2;
        int left = query(start, mid, l, r, k, ((2 * node) + 1));
        int right = query((mid + 1), end, l, r, k, ((2 * node) + 2));
        return (left + right);
    }
} segTree;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    segTree.build(0, (n - 1), 0);
    int q;
    cin >> q;
    int ans = 0;
    int i, j;
    while(q--) {
        int l, r, k;
        cin >> i >> j >> k;
        l = (i ^ ans);
        r = (j ^ ans);
        k ^= ans;
        l--; // Make 0 Based Index
        r--; // Make 0 Based Index
        ans = segTree.query(0, (n - 1), l , r, k, 0);
        cout << ans << '\n';
    }
    return 0;
}