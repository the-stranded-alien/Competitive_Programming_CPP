#include<iostream>
#include<map>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

map<int, int> pre_cnt;
map<int, int> suf_cnt;
int bit[1000005];
int arr[1000005];
int lft[1000005];
int rgt[1000005];

int query(int x) {
    int val = 0;
    while(x > 0) {
        val += bit[x];
        x -= (x & (-x));
    }
    return val;
}

void update(int x, int n) {
    while(x <= n) {
        bit[x] += 1;
        x += (x & (-x));
    }
    return;
}

int main() {
    // FIO;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        pre_cnt[arr[i]]++;
        lft[i] = pre_cnt[arr[i]];
    }
    for(int i = (n - 1); i >= 0; i--) {
        suf_cnt[arr[i]]++;
        rgt[i] = suf_cnt[arr[i]];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (i) - query(rgt[i]);
        update(lft[i], n);
    }
    cout << ans << endl;
    return 0;
}