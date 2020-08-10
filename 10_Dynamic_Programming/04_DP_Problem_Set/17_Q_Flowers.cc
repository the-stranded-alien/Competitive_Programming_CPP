#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#define ll long long int
using namespace std;

struct flower {
    ll height;
    ll beauty;
};

ll flowers(vector<flower> &v, int n) {
    vector<ll> dp(n + 1);
    map<ll, ll> meaningful;
    // Base Case
    dp[1] = v[1].beauty;
    meaningful[v[1].height] = dp[1];
    // Bottom Up Approach
    ll ans = dp[1];
    for(int i = 2; i <= n; i++) {
        dp[i] = v[i].beauty;
        auto it = meaningful.lower_bound(v[i].height + 1);
        if(it != meaningful.begin()) {
            it--;
            dp[i] += it->second;
        }
        meaningful[v[i].height] = dp[i];
        it = meaningful.upper_bound(v[i].height);
        while((it != meaningful.end()) && (it->second <= dp[i])) {
            auto temp = it;
            temp++;
            meaningful.erase(it);
            it = temp;
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<flower> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i].height;
    for(int i = 1; i <= n; i++) cin >> v[i].beauty;
    cout << flowers(v, n) << endl;
    return 0;
}