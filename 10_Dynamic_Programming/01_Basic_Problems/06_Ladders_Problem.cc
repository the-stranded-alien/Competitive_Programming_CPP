#include<iostream>
using namespace std;

// Top Down Approach
int laddersProblemTopDown(int n, int k, int dp[]) {
    // Base Case
    if(n == 0) return 1;
    // Recursive Case
    if(dp[n] != 0) return dp[n]; // Look Up
    int ways = 0;
    for(int i = 1; i <= k; i++) {
        if(n - i >= 0) ways += laddersProblemTopDown(n - i, k, dp);
    }
    return (dp[n] = ways);
}

// Bottom Up Approach
int laddersProblemBottomUp(int n, int k) {
    int dp[100] = {0};
    dp[0] = 1; // Base Case
    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

// Optimised Implementation Of Bottom Up DP
int laddersProblemBottomUpOptimised(int n, int k) {
    int dp[100] = {0};
    dp[0] = dp[1] = 1; // Base Case
    for(int i = 2; i <= k; i++) dp[i] = (2 * dp[i - 1]);
    for(int j = (k + 1); j <= n; j++) dp[j] = (2 * dp[j - 1]) - dp[j - k - 1];
    return dp[n];
}

int main() {
    int n, k;
    cin >> n >> k;
    // Top Down DP
    int dp[100] = {0};
    cout << laddersProblemTopDown(n, k, dp) << endl;
    // Bottom Up DP
    cout << laddersProblemBottomUp(n, k) << endl;
    // Bottom Up DP Optimised 
    cout << laddersProblemBottomUpOptimised(n, k) << endl;
    return 0;
}