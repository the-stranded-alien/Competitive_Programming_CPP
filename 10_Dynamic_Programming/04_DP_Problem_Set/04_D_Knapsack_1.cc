#include<iostream>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;

struct item {
    int wt;
    int val;
};

// Bottom Up Approach
long long int knapsackBottomUp(vector<item> arr, int n, int W) {
    long long int dp[n + 1][W + 1]; // Memory
    // Base Case
    for(int w = 0; w <= W; w++) dp[1][w] = 0;
    dp[1][arr[1].wt] = arr[1].val;
    // Iteratively Calculating Other Cases In Bottom Up Fashion
    for(int i = 2; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if(arr[i].wt > w) continue;
            dp[i][w] = max(dp[i][w], (arr[i].val + dp[i - 1][w - arr[i].wt]));
        }
    }  
    return *max_element(dp[n], (dp[n] + W + 1));
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<item> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i].wt >> arr[i].val;
    cout << knapsackBottomUp(arr, n, w) << endl;
    return 0;
}