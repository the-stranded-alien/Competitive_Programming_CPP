#include<iostream>
using namespace std;

// Recursion
int fibonacciRec(int n) {
    // Base Case
    if(n == 0 || n == 1) return n;
    // Recursive Case
    int ans = fibonacciRec(n - 1) + fibonacciRec(n - 2);
    return ans;
}

// Top Down DP Approach (Recursion + Memoization)
int fibonacciTopDownDP(int n, int dp[]) {
    // Base Case
    if(n == 0 || n == 1) return n;
    // Recursive Case
    if(dp[n] != 0) return dp[n]; // Look Up
    int ans = fibonacciTopDownDP(n - 1, dp) + fibonacciTopDownDP(n - 2, dp);
    return dp[n] = ans;
}

// Bottom Up DP Approach (Iteration + Memoization)
int fibonacciBottomUpDP(int n) {
    int dp[100] = {0}; // Memory
    dp[1] = 1; // Initialising Base Cases
    for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// Bottom Up DP With Space Optimisation
int fibonacciBUSpaceOptimised(int n) {
    if(n == 0 || n == 1) return n;
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    // Recursive
    cout << fibonacciRec(n) << endl;
    // Top Down DP !
    int dp[100] = {0}; // Memory
    cout << fibonacciTopDownDP(n, dp) << endl;
    // Bottom Up DP
    cout << fibonacciBottomUpDP(n) << endl;
    // Bottom Up DP With Space Optimisation
    cout << fibonacciBUSpaceOptimised(n) << endl;
    return 0;
}