#include<iostream>
#define MOD 1000000007
using namespace std;

char grid[1002][1002];

int numberOfWays(int n, int m) {
    int dp[n + 1][m + 1];
    dp[n][m] = 1; // Base Case
    for(int i = n; i >= 1; i--) {
        for(int j = m; j >= 1; j--) {
            if(i == n && j == m) continue;
            if(grid[i][j] == '#') dp[i][j] = 0;
            else dp[i][j] = ((((i == n) ? 0 : dp[i + 1][j]) + ((j == m) ? 0 : dp[i][j + 1])) % MOD);
        }
    }
    return dp[1][1];
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> grid[i][j];
    }
    cout << numberOfWays(n, m) << endl;
    return 0;
}