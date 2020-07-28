#include<iostream>
#include<climits>
using namespace std;

// Top Down Approach
int minCoinsTopDown(int amt, int coins[], int T, int dp[]) {
    // Base Case
    if(amt == 0) return 0;
    // Recursive Case
    if(dp[amt] != 0) return dp[amt];
    int ans = INT_MAX;
    for(int i = 0; i < T; i++) {
        if((amt - coins[i]) >= 0) {
            int subProb = minCoinsTopDown((amt - coins[i]), coins, T, dp);
            ans = min(ans, (subProb + 1));
        }
    }
    return (dp[amt] = ans);
}

// Bottom Up Approach
int minCoinsBottomUp(int N, int coins[], int T) {
    int dp[100] = {0}; // Memory
    dp[0] = 0; // Init. Base Case
    // Iterate Over All States (1.......N)
    for(int n = 1; n <= N; n++) {
        // Init The Current Ans As INT_MAX
        dp[n] = INT_MAX;
        for(int i = 0; i < T; i++) {
            if((n - coins[i]) >= 0) {
                int subProb = dp[n - coins[i]];
                dp[n] = min(dp[n], (subProb + 1));
            }
        }
    }
    return dp[N];
}

int main() {
    int N = 15;
    int coins[] = {1, 7, 10};
    int T = sizeof(coins) / sizeof(int);
    // Top Down Approach
    int dp[100] = {0}; // Memory
    cout << minCoinsTopDown(N, coins, T, dp) << endl;
    // Bottom Up Approach
    cout << minCoinsBottomUp(N, coins, T) << endl;
    return 0;
}