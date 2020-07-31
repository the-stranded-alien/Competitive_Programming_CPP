#include<iostream>
using namespace std;

// Top Down Approach
int optimalGame(int arr[], int s, int e, int dp[50][50]) {
    // Base Case
    if(s > e) return 0;
    // Recursive Case
    if(dp[s][e] != 0) return dp[s][e];
    int op1 = arr[s] + min(optimalGame(arr, (s + 2), e, dp), optimalGame(arr, (s + 1), (e - 1), dp));
    int op2 = arr[e] + min(optimalGame(arr, s, (e - 2), dp), optimalGame(arr, (s + 1), (e - 1), dp));
    return (dp[s][e] = max(op1, op2));
}

int main() {
    int n;
    cin >> n;
    int arr[50];
    int dp[50][50] = {0};
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << optimalGame(arr, 0, (n - 1), dp) << endl;
    return 0;
}