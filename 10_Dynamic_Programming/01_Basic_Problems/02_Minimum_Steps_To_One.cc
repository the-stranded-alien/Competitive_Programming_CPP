#include<iostream>
#include<climits>
using namespace std;

// Minimum Steps To One
// n => (n / 3) iff (n % 3) == 0
// n => (n / 2) iff (n % 2) == 0
// n => (n - 1)

// Recursion
int minStepsRec(int n) {
    // Base Case
    if(n == 1) return 0;
    // Recursive Case
    int opt1, opt2, opt3;
    opt1 = opt2 = opt3 = INT_MAX;
    if(n % 3 == 0) opt1 = minStepsRec(n / 3) + 1;
    if(n % 2 == 0) opt2 = minStepsRec(n / 2) + 1;
    opt3 = minStepsRec(n - 1) + 1;
    int ans = min(min(opt1, opt2), opt3);
    return ans;
}

// Top Down Approach
int minStepsTopDown(int n, int dp[]) {
    // Base Case
    if(n == 1) return 0;
    // Recursive Case
    // Look Up (If 'n' Is Already Computed)
    if(dp[n] != 0) return dp[n];
    // Compute If dp[n] Is Not Known (For First Time)
    int opt1, opt2, opt3;
    opt1 = opt2 = opt3 = INT_MAX;
    if(n % 3 == 0) opt1 = minStepsTopDown(n / 3, dp) + 1;
    if(n % 2 == 0) opt2 = minStepsTopDown(n / 2, dp) + 1;
    opt3 = minStepsTopDown(n - 1, dp) + 1;
    int ans = min(min(opt1, opt2), opt3);
    return (dp[n] = ans);
}

// Bottom Up Approach
int minStepsBottomUp(int n) {
    int dp[100] = {0}; // Memory
    dp[1] = 0; // Init. Base Case
    for(int i = 2; i <= n; i++) {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if(i % 3 == 0) op1 = dp[i / 3] + 1;
        if(i % 2 == 0) op2 = dp[i / 2] + 1;
        op3 = dp[i - 1] + 1;
        dp[i] = min(min(op1, op2), op3);
    }
    return dp[n];
}

int main () {
    int n;
    cin >> n;
    // Recursion
    cout << minStepsRec(n) << endl;
    // Top Down
    int dp[100] = {0}; // Memory
    cout << minStepsTopDown(n, dp) << endl;
    // Bottom Up
    cout << minStepsBottomUp(n) << endl;
    return 0;
}