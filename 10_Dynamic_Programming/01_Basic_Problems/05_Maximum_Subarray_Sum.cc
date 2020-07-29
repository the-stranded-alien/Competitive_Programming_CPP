#include<iostream>
using namespace std;

// DP - Bottom Up Approach
int maxSubArraySumBottomUp(int arr[], int n) {
    int dp[100] = {0};
    dp[0] = (arr[0] > 0) ? arr[0] : 0; // Base Case
    int max_so_far = dp[0];
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + arr[i];
        if(dp[i] < 0) dp[i] = 0;
        max_so_far = max(dp[i], max_so_far);
    }
    return max_so_far;
}

// Space Optimized Code (Kadane's Algorithm)
int maxSubArraySpaceOpt(int arr[], int n) {
    int current_sum = 0;
    int max_so_far = 0;
    for(int i = 0; i < n; i++) {
        current_sum += arr[i];
        if(current_sum < 0) current_sum = 0;
        max_so_far = max(current_sum, max_so_far);
    }
    return max_so_far;
}

int main() {
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr) / sizeof(int);
    cout << maxSubArraySumBottomUp(arr, n) << endl;
    cout << maxSubArraySpaceOpt(arr, n) << endl;
    return 0;
}