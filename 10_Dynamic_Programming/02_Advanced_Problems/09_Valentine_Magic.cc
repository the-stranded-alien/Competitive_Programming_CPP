#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 10000000000099ll
#define mod 1000000007
#define ll long long int

ll n, m;
ll boys[5005], girls[5005];
ll dp[5005][5005];

// Top Down DP
ll valentine(ll i, ll j) {
    // 'i' Is The Index For Boy, And 'j' Is The Index For Girl.
    // Base Cases
    if(i == n) return 0; // We Have Paired All The Boys.
    if(j == m) return INF; // We Have Rejected Lot Of Girls, And No Girl Is Available For The Boys.
    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j]; // Look Up
    ll op1 = (abs(boys[i] - girls[j]) + valentine((i + 1),(j + 1))); // By Accepting The Jth Girl
    ll op2 = valentine(i, (j + 1)); // By Rejecting Jth Girl
    return (dp[i][j] = min(op1, op2));
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> boys[i];
    for(int j = 0; j < m; j++) cin >> girls[j];
    sort(boys, boys + n);
    sort(girls, girls + m);
    ll ans = valentine(0, 0);
    cout << ans << endl;
    return 0;
}