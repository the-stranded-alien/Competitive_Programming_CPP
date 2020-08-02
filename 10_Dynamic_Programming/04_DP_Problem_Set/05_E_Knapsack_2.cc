#include<iostream>
#include<algorithm>
#include<vector>
#define INF 1e9 + 1
using namespace std;

struct item {
    int wt;
    int val;
};

// Bottom Up Approach
int knapsackBottomUp(vector<item> arr, int n, int W) {
    int maxVal = (n * 1000);
    long long int dp[n + 1][maxVal + 1];
    // Base Cases
    for(int val = 0; val <= maxVal; val++) dp[1][val] = INF;
    dp[1][0] = 0;
    dp[1][arr[1].val] = arr[1].wt;
    // Iteratively Calculating Other Cases In Bottom Up Fashion
    for(int i = 2; i <= n; i++) {
        for(int v = 0; v <= maxVal; v++) {
            dp[i][v] = dp[i - 1][v];
            if(arr[i].val > v) continue;
            dp[i][v] = min(dp[i][v], (arr[i].wt + dp[i - 1][v - arr[i].val]));
        }
    }
    int ans = 0;
    for(int x = 0; x <= maxVal; x++) {
        if(dp[n][x] <= W) ans = x;
    }
    return ans;
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<item> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i].wt >> arr[i].val;
    cout << knapsackBottomUp(arr, n, w) << endl;
    return 0;
}