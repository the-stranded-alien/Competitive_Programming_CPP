#include<iostream>
using namespace std;

int pairFriends(int n) {
    int dp[1000] = {0};
    // Init. Base Cases
    dp[0] = 1;
    dp[1] = 1;  
    dp[2] = 2;
    // Iterate Over Other Cases
    for(int i = 3; i <= n; i++) dp[i] = dp[i - 1] + ((i - 1) * dp[i - 2]);
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << pairFriends(n) << endl;
    return 0;
}