#include<iostream>
#include<climits>
using namespace std;

// Top Down DP
int frog1TopDown(int cur, int heights[], int N, int dp[]) {
    // Base Case
    if(cur >= N) return 0;
    // Recursive Case
    if(dp[cur] != 0) return dp[cur];
    int op1 = abs(heights[cur] - heights[cur + 1]) + frog1TopDown(cur + 1, heights, N, dp);
    int op2 = abs(heights[cur] - heights[cur + 2]) + frog1TopDown(cur + 2, heights, N, dp);
    int ans = min(op1, op2);
    return (dp[cur] = ans);
}

// Bottom Up DP
int frog1BottomUp(int heights[], int N) {
    int dp[100005] = {0};
    dp[0] = 0; // Init Base Case
    for(int i = 1; i <= N; i++) {
        int opt1 = (abs(heights[i] - heights[i - 1]) + dp[i - 1]);
        int opt2 = (i == 1) ? INT_MAX : (abs(heights[i] - heights[i - 2]) + dp[i - 2]);
        dp[i] = min(opt1, opt2);
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    int heights[100005];
    for(int i = 0; i < N; i++) cin >> heights[i];
    // Top Down Approach
    int dp[100005] = {0};
    cout << frog1TopDown(0, heights, N - 1, dp) << endl;
    // Bottom Up Approach
    cout << frog1BottomUp(heights, N - 1) << endl;
    return 0;
}