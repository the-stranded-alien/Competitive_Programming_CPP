#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

string stones(vector<int> &v, int k) {
    bool dp[k + 1];  // Memory
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= k; i++) {
        for(int move : v) {
            if(move > i) continue;
            if(dp[i - move] == 0) dp[i] = 1;
        }
    }
    return (dp[k] ? "First" : "Second");
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << stones(v, k) << endl;
    return 0;
}