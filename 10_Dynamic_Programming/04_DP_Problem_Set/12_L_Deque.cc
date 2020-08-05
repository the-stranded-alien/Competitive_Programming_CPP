#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

long long int dp[3001][3001][2];

long long int deque(vector<int> &v, int i, int j, bool turn) {
    if(i > j) return 0;
    if(dp[i][j][turn] != -1) return dp[i][j][turn]; // Look Up
    if(turn == 1) return (dp[i][j][turn] =  max((v[i] + deque(v, (i + 1), j, 0)), (v[j] + deque(v, i, (j - 1), 0))));
    else return (dp[i][j][turn] = min((deque(v, (i + 1), j, 1)), (deque(v, i, (j - 1), 1))));
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    memset(dp, -1, sizeof(dp));
    long long int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    long long int scoreX = deque(v, 1, n , 1);
    long long int scoreY = (sum - scoreX);
    cout << (scoreX - scoreY) << endl;
    return 0;
}