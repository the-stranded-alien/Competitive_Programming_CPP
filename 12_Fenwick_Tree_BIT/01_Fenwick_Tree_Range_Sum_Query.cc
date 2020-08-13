#include<iostream>
using namespace std;

int a[10000];
int BIT[10000] = {0};

// Range Sum Query

// Build And Update
void update(int i, int inc, int N) {
    while(i <= N) {
        BIT[i] += inc;
        i += (i & (-i));
    }
}

// Sum Till The ith Index
int query(int i) {
    int ans = 0;
    while(i > 0) {
        ans += BIT[i];
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
    // Query
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << (query(r) - query(l - 1)) << endl;
    }
    return 0;
}