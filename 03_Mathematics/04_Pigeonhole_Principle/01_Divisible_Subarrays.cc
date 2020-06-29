#include<iostream>
#include<cstring>
using namespace std;

// You Are Given 'N' Elements, [a(i), a(i+1), a(i+2), ......, a(j)],
// Find The Number Of Good Sub-Arrays. A Good Sub-Array Is A 
// Sub-Array [a(i), a(i+1), a(i+2), ......, a(j)] Such That
// [a(i) + a(i+1) + a(i+2) + ...... + a(j)] Is Divisible By 'N'.

#define ll long long
ll a[1000005];
ll pre[1000005];

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        memset(pre, 0, sizeof(pre));
        pre[0] = 1;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            sum = (sum + n) % n;
            pre[sum]++;
        }

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ll m = pre[i];
            ans += ((m) * (m - 1) / 2);
        }
        cout << ans << endl;
    }
    return 0;
}