#include<iostream>
#include<cstring>
using namespace std;

int dp[1005][1005];
int cost[1005][1005];

// Bottom Up DP
int minCostPath(int R, int C) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(i == 0 && j == 0) dp[i][j] = cost[0][0]; // Base Case
            else if(i == 0) dp[i][j] = (dp[0][j - 1] + cost[0][j]);
            else if(j == 0) dp[i][j] = (dp[i - 1][0] + cost[i][0]);
            else dp[i][j] = (min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j]); 
        }
    }
    return dp[R - 1][C - 1];
}

int main() {
    int R, C;
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) cin >> cost[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << minCostPath(R, C) << endl;
    return 0;
}