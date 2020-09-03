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

// Would Give TLE
int countBS(int n, int last) {
    // Base Case
    if(n == 0) return 0;
    if(n == 1) {
        if (last) return 1;
        else return 2;
    }
    // Recursive Case
    if(last == 0) return (countBS((n - 1), 1) + countBS((n - 1), 0));
    else return (countBS((n - 1), 0));
}

// Optimised (Still TLE)
int countBSOptimized(int n) {
    // Base Case
    if((n == 1) || (n == 2)) return (n + 1);
    // Recursive Case
    return (countBSOptimized(n - 1) + countBSOptimized(n - 2));

}

// Using Dynamic Programming
// dp[n][0] -> Number Of Possible Strings Which End At 0.
// dp[n][1] -> Number Of Possible Strings Which End At 1.
// Bottom-Up DP
ll countBSBottomUp(int n) {
    ll dp[n + 1][2] = {0};
    // Base Cases
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i][1] += dp[i - 1][0];
        dp[i][0] += (dp[i - 1][0] + dp[i - 1][1]);
    }
    return (dp[n][0] + dp[n][1]);
}


int main() {
    FIO;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << countBSBottomUp(n) << endl;
    }
    return 0;
}