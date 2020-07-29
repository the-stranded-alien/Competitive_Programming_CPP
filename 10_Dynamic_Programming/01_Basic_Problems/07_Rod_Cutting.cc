#include<iostream>
using namespace std;

// Recursion
int maxProfitRec(int arr[], int totalLen) {
    // Base Case
    if(totalLen == 0) return 0;
    // Recursive Case
    int best = 0;
    for(int len = 1; len <= totalLen; ++len) {
        int netProfit = arr[len] + maxProfitRec(arr, totalLen - len);
        best = max(best, netProfit);
    }
    return best;
}

// Top Down Approach
int maxProfitTopDown(int arr[], int totalLen, int memo[]) {
    if(totalLen == 0) return 0; // Base Case 
    if(memo[totalLen] != 0) return memo[totalLen]; // Look Up
    int best = 0;
    for(int len = 1; len <= totalLen; ++len) {
        int netProfit = arr[len] + maxProfitRec(arr, totalLen - len);
        best = max(best, netProfit);
    }
    return (memo[totalLen] = best);    
}

// Bottom Up Approach
int maxProfitBottomUp(int arr[], int totalLen) {
    int dp[100] = {0};
    for(int len = 1; len <= totalLen; ++len) {
        int best = 0;
        for(int cut = 1; cut <= len; ++cut) best = max(best, (arr[cut] + dp[len - cut]));
        dp[len] = best;
    }
    return dp[totalLen];
}

int main() {
    int priceOfEachLen[100];
    int totalLen;
    cin >> totalLen;
    for(int eachPiece = 1; eachPiece <= totalLen; ++eachPiece) cin >> priceOfEachLen[eachPiece];
    // Recursion
    int ans = maxProfitRec(priceOfEachLen, totalLen);
    cout << ans << endl;
    // Top Down DP
    int memo[100] = {0};
    cout << maxProfitTopDown(priceOfEachLen, totalLen, memo) << endl;
    // Bottom Up DP
    cout << maxProfitBottomUp(priceOfEachLen, totalLen) << endl;
    return 0;
}