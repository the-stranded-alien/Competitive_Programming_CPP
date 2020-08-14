#include<iostream>
#include<cstring>
using namespace std;

int BIT[200000] = {0};

void update(int i, int inc, int N) {
    while(i <= N) {
        BIT[i] += inc;
        i += (i & (-i));
    }
}

int query(int i) {
    int ans = 0;
    while(i > 0) {
        ans += BIT[i];
        i -= (i & (-i));
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(BIT, 0, sizeof(BIT));
        int n, u;
        cin >> n >> u;
        int l, r, val;
        for(int updates = 0; updates < u; updates++) {
            cin >> l >> r >> val;
            update((l + 1), val, (n + 1));
            update((r + 2), (-val), (n + 1));
        }
        int q;
        cin >> q;
        for(int queries = 0; queries < q; queries++) {
            int idx;
            cin >> idx;
            cout << query(idx + 1) << endl;
        }
    }
    return 0;
}