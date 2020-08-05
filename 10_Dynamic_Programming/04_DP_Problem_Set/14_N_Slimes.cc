#include<iostream>
#include<cstring>
#include<vector>
#define INF (1LL << 60)
using namespace std;

long long int dp[3001][3001];
long long int sum[3001][3001];

long long int slimes(vector<int> &v, int i, int j) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j]; // Look-Up
    long long int minCost = INF;
    for(int k = i; k < j; k++) {
        minCost = min(minCost, (sum[i][j] + slimes(v, i, k) + slimes(v, (k + 1), j)));
    }
    return (dp[i][j] = minCost);
}

void preprocess(vector<int> &v, int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            sum[i][j] = v[j] + ((j == i) ? 0 : sum[i][j - 1]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    preprocess(v, n);
    cout << slimes(v, 1, n) << endl;
    return 0;
}