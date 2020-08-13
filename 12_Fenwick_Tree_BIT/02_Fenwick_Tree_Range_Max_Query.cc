#include<iostream>
using namespace std;

int a[10000];
int BIT[10000] = {0};

// Range Max Query

// Build And Update
void update(int i, int val, int N) {
    while(i <= N) {
        BIT[i] = max(BIT[i], val);
        i += (i & (-i));
    }
}

// Max Till The ith Index
int query(int i) {
    int ans = 0;
    while(i > 0) {
        ans = max(ans, BIT[i]);
        i -= (i & (-i));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    // Build The BIT
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i], n);
    }
    // Update
    update(3, 10, n);
    // Query
    int q;
    cin >> q;
    while(q--) {
        int idx;
        cin >> idx;
        cout << query(idx) << endl;
    }
    return 0;
}