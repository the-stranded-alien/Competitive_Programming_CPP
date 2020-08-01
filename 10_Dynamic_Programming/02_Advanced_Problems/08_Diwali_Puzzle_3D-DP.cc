#include<iostream>
#include<cstring>
using namespace std;

#define ll long long int
#define mod 1000003

ll n, k;
ll dp[105][3][105];

// Top Down DP
ll puzzle(ll cur_idx, ll prev, ll cnt) {
    // Base Case
    if(cur_idx == n) {
        if(cnt == k) return 1;
        else return 0;
    }
    // Recursive Case
    if(dp[cur_idx][prev][cnt] != -1) return dp[cur_idx][prev][cnt]; // Look Up
    ll ans = 0;
    // When The Current Element We Put Is One
    if(prev == 1) ans = ans + puzzle((cur_idx + 1), 1, (cnt + 1));
    else ans = ans + puzzle((cur_idx + 1), 1, cnt);
    ans %= mod;
    // When The Current Element We Put Is Zero
    ans = ans + puzzle((cur_idx + 1), 0, cnt);
    ans %= mod;
    
    return (dp[cur_idx][prev][cnt] = ans);
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        // Start By Both Choice With First Value Either 0 Or 1 !!
        cout << (puzzle(1, 0, 0) + puzzle(1, 1, 0)) % mod << endl;
    }
    return 0;
}