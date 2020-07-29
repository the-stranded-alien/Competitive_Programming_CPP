#include<iostream>
using namespace std;

// You Are Given Prices Of 'N' Bottles Of Wines.
// In Each Year You Have To Sell 1 Bottle From Extreme Last Or First.
// Prices Of Wine Increase Every Year, In Yth Year Price = p[i] * y;
// Find The Max Profit Possible !

// Recursion
int winesProfitRec(int wines[], int i, int j, int y) {
    // Base Case
    if(i > j) return 0; // No Bottles Are Left.
    // Recursive Case
    int opt1 = ((wines[i] * y) + winesProfitRec(wines, (i + 1), j, (y + 1)));
    int opt2 = ((wines[j] * y) + winesProfitRec(wines, i, (j - 1), (y + 1)));
    return max(opt1, opt2);
}

// Top Down Approach
int winesProfitTopDown(int wines[], int i, int j, int y, int dp[100][100]) {
    // Base Case
    if(i > j) return 0; // No Bottles Are Left.
    // Recursive Case
    if(dp[i][j] != 0) return (dp[i][j]); // Look Up
    int opt1 = ((wines[i] * y) + winesProfitTopDown(wines, (i + 1), j, (y + 1), dp));
    int opt2 = ((wines[j] * y) + winesProfitTopDown(wines, i, (j - 1), (y + 1), dp));
    return (dp[i][j] = max(opt1, opt2));
}

// Bottom Up Approach
int winesProfitBottomUp(int wines[], int n) {
    int dp[100][100] = {}; // Memory
    for (int len = 1; len <= n; ++len) {
        int yr = n - len + 1; // Current Year
        int srt = 0;
        int end = n - len;
        int en = srt + len - 1;
        while(srt <= end){
            dp[srt][en] = max(
                ((yr * wines[srt]) + dp[srt + 1][en]),
                ((yr * wines[en]) + dp[srt][en - 1])
                );
            ++srt;
            ++en;
        }
    }
    return dp[0][n - 1];
}


int main() {
    int wines[] = {2, 3, 5, 1, 4};
    int n = sizeof(wines) / sizeof(int);
    int y = 1;
    // Recursion
    cout << winesProfitRec(wines, 0, n - 1, y) << endl;
    // Top Down DP
    int dp[100][100] = {0}; // Memory
    cout << winesProfitTopDown(wines, 0, n - 1, y, dp) << endl;
    // Bottom Up DP
    cout << winesProfitBottomUp(wines, n) << endl;
    return 0;
}