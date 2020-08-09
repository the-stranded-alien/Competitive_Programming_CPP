#include<iostream>
#include<vector>
#include<cstring>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll dp[22][(1 << 22)];
int match(vector<vector<int> > &compat, int i, int womenSubset, int N) {
    if(i == (N + 1)) { // Base Case
        if(womenSubset == 0) return 1; // All Women Are Paired i.e. Right Config.
        else return 0; // Some Women Is Not Paired i.e. Invalid.
    }
    if(dp[i][womenSubset] != -1) return dp[i][womenSubset];
    ll ans = 0;
    for(int women = 0; women < N; women++) {
        bool available = (((1 << women) & (womenSubset)) == 0) ? 0 : 1;
        if(available && compat[i][women + 1]) {
            ans = (ans + match(compat, (i + 1), (womenSubset ^ (1 << women)), N)) % MOD;
        }
    }
    return (dp[i][womenSubset] = ans);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > compat((n + 1), vector<int> (n + 1));
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cin >> compat[i][j];
    }
    cout << match(compat, 1, ((1 << n) - 1), n) << endl;
    return 0;
}