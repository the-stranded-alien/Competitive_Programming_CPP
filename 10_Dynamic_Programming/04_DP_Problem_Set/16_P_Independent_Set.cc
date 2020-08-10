#include<iostream>
#include<vector>
#include<cstring>
#define ll long long int
#define MOD 1000000007
using namespace std;

vector<int> tree[100001];
ll dp[100001][2];

ll independentSets(int u, bool constraint, int pr) {
    if(dp[u][constraint] != -1) return dp[u][constraint]; // Look Up
    ll ans = 0;
    ll w1 = 1;
    for(int child : tree[u]) {
        if(child != pr) {
            w1 = ((w1 * independentSets(child, 0, u)) % MOD);
        }
    }
    ans = ((ans + w1) % MOD);
    if(!constraint) {
        ll w2 = 1;
        for(int child : tree[u]) {
            if(child != pr) {
                w2 = ((w2 * independentSets(child, 1, u)) % MOD);
            }
        }
        ans = ((ans + w2) % MOD);
    }
    return (dp[u][constraint] = ans);    
}

int main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < (n - 1); i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout << independentSets(1, 0, -1) << endl;
    return 0;
}