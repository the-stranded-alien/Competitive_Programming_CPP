#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// Top Down DP
int frog2TopDown(int cur, int heights[], int N, int K, int dp[]) {
    // Base Case
    if(cur >= N) return 0;
    // Recursive Case
    if(dp[cur] != 0) return dp[cur]; // Look Up
    int ans = INT_MAX;
    for(int steps = 1; steps <= K; steps++) {
        if((cur + steps) <= N) {
            ans = min(ans, (abs(heights[cur] - heights[cur + steps]) + frog2TopDown((cur + steps), heights, N, K, dp)));
        } else break;
    }
    return (dp[cur] = ans);
}

// Bottom Up DP
int frog2BottomUp(int heights[], int N, int K) {
    int dp[100005] = {0};
    dp[0] = 0; // Base Case
    for(int i = 1; i <= N; i++) {
        dp[i] = INT_MAX;
        for(int steps = 1; steps <= K; steps++) {
            int cur_ans = (i < steps) ? INT_MAX : (abs(heights[i] - heights[i - steps]) + dp[i - steps]);
            dp[i] = min(dp[i], cur_ans);
        }
    }
    return dp[N];
}

// Bottom Up DP (With 1 Based Indexing)
int frog2BottomUp_1(vector<int> arr, int N, int K) {
    vector<int> dp(N + 1);
    dp[1] = 0;
    for(int i = 2; i <= N; i++) {
        dp[i] = INT_MAX;
        for(int j = (i - 1); (j >= 1 && (i - j) <= K); j--) {
            dp[i] = min(dp[i], (abs(arr[i] - arr[j]) + dp[j]));
        }
    }
    return dp[N];
}

int main() {
    int N, K;
    cin >> N >> K;
    int heights[100005];
    for(int i = 0; i < N; i++) cin >> heights[i];
    // Top Down Approach
    int dp[100005] = {0};
    cout << frog2TopDown(0, heights, N - 1, K, dp) << endl;
    // Bottom Up Approach
    cout << frog2BottomUp(heights, N - 1, K) << endl;
    // Bottom Up Approach With 1 Based Indexing
    vector<int> stones(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> stones[i];
    }
    cout << frog2BottomUp_1(stones, N, K) << endl;
    return 0;
}