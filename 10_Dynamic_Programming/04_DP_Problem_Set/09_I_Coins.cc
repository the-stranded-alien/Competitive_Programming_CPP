#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

double dp[3001][3001];

double coins(vector<double> &arr, int i, int x) {
    // Base Cases
    if(x == 0) return 1;
    if(i == 0) return 0;
    // Recursive Case
    if(dp[i][x] > -0.9) return dp[i][x]; // Look Up
    return (dp[i][x] = ((arr[i] * coins(arr, i - 1, x - 1)) + ((1 - arr[i]) * coins(arr, i - 1, x))));    
}

int main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    vector<double> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    cout << fixed << setprecision(10) << coins(arr, n, ((n + 1) / 2)) << endl;
    return 0;
}