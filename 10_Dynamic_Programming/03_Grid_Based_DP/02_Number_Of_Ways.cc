#include<iostream>
#include<cstring>
using namespace std;

void printGrid(int x, int y, int grid[105][105]) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            cout << grid[i][j] << "  ";
        }
        cout << endl;
    }
}

// Bottom Up DP
int ratPaths(int R, int C, int dp[105][105]) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(i == 0 || j == 0) dp[i][j] = 1; // Base Case
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
        }
    }
    return dp[R - 1][C - 1];
}

// Bottom Up DP
int elephantPaths(int R, int C, int dp[105][105]) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(i == 0 && j == 0) dp[i][j] = 1; // Base Case
            else {
                for(int k = 0; k < i; k++) dp[i][j] += dp[k][j];
                for(int k = 0; k < j; k++) dp[i][j] += dp[i][k];                
            }  
        }
    }
    return dp[R - 1][C - 1];
}

int main() {
    int R, C;
    cin >> R >> C;
    int rat_dp[105][105] = {0};
    int elephant_dp[105][105] = {0};
    cout << "Rat Version Ways : " << ratPaths(R, C, rat_dp) << endl;
    cout << "Grid : " << endl;
    printGrid(R, C, rat_dp);
    cout << "Elephant Version Ways : " << elephantPaths(R, C, elephant_dp) << endl;
    cout << "Grid : " << endl;
    printGrid(R, C, elephant_dp);
    return 0;
}