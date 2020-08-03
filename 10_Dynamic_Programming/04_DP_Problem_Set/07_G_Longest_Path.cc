#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> graph[100001];
int dp[100001]; // dp[i] : Length Of Longest Path Starting At Node 'i'.

int longestPath(int src) {
    if(dp[src] != -1) return dp[src];
    bool leaf = 1;
    int bestChild = 0;
    for(int child : graph[src]) {
        leaf = 0;
        bestChild = max(bestChild, longestPath(child));
    }
    return (dp[src] = (leaf ? 0 : (1 + bestChild)));
}

int main() {
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, longestPath(i));
    cout << ans;
    return 0; 
}