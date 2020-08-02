#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

struct activity {
    // Stores Happiness Points
    int A, B, C;
};

// Bottom Up DP
int vacationBottomUp(vector<activity> arr, int n) {
    // 1 Based Indexing
    int dp[n + 1][3] = {0}; // Memory
    // Init. Base Cases
    dp[1][0] = arr[1].A;
    dp[1][1] = arr[1].B;
    dp[1][2] = arr[1].C;
    // Iteratively Calculating For All Other Valid Values
    for(int i = 2; i <= n; i++) {
        dp[i][0] = (arr[i].A + max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] = (arr[i].B + max(dp[i - 1][0], dp[i - 1][2]));
        dp[i][2] = (arr[i].C + max(dp[i - 1][0], dp[i - 1][1]));
    }
    return (max(dp[n][0], max(dp[n][1], dp[n][2])));
}

int main() {
    int n;
    cin >> n;
    vector<activity> arr(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].A;
        cin >> arr[i].B;
        cin >> arr[i].C;
    }
    // Bottom Up Approach
    cout << vacationBottomUp(arr, n) << endl;
    return 0;
}