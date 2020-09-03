#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define pb push_back
#define F first
#define S second
#define P pair<int, int>
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Using DP to avoid TLE.

int Tiles(int n, int m, int dp[]) {
    // Base Case
    if(n == m) return 2;
    if((m > n) && (n >= 1)) return 1;
    if(n <= 0) return 0;
    // Recursive Case
    if(dp[n] != -1) return dp[n];
    return (dp[n] = (((Tiles((n - 1), m, dp) % MOD) + (Tiles((n - m), m, dp) % MOD)) % MOD));
}

int main() {
    FIO;
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        int dp[100005];
        memset(dp, -1, sizeof(dp));
        cin >> n >> m;
        cout << (Tiles(n, m, dp) % MOD) << endl;
    }
    return 0;
}