#include<iostream>
#include<cmath>
using namespace std;

int n, m;
int arr[1000000];
int seg[2000000];

void build(int nd, int l, int r) {
    if(l == r) {
        seg[nd] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build((2 * nd), l, mid);
    build(((2 * nd) + 1), (mid + 1), r);
    int times = log2(r - l + 1);
    if(times & 1) seg[nd] = (seg[2 * nd] | seg[(2 * nd) + 1]);
    else seg[nd] = (seg[2 * nd] ^ seg[(2 * nd) + 1]);
    return;
}

void update(int nd, int i, int l, int r, int val) {
    if((i < l) || (i > r)) return;
    if(l == r) seg[nd] = val;
    else {
        int mid = (l + r) / 2;
        update((2 * nd), i, l, mid, val);
        update(((2 * nd) + 1), i, (mid + 1), r, val);
        int times = log2(r - l + 1);
        if(times & 1) seg[nd] = (seg[2 * nd] | seg[(2 * nd) + 1]);
        else seg[nd] = (seg[2 * nd] ^ seg[(2 * nd) + 1]);
    }
}

int main() {
    cin >> n >> m;
    n = pow(2, n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, (n - 1));
    while(m--) {
        int id, val;
        cin >> id >> val;
        id--;
        update(1, id, 0, (n - 1), val);
        cout << seg[1] << '\n';
    }
    return 0;
}