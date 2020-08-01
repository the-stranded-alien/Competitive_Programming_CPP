#include<iostream>
#include<cstring>
using namespace std;

#define MOD 1000000007

// Robot And Paths (CodeChef)
// A robot is designed to move on a rectangular grid of M rows and N columns.
// The robot is initially positioned at (1, 1), i.e., the top-left cell. The
// robot has to reach the (M, N) grid cell. In a single step, robot can move
// only to the cells to its immediate east and south directions. That means if
// the robot is currently at (i, j), it can move to either (i + 1, j) or (i, j + 1)
// cell, provided the robot does not leave the grid. Now somebody has placed several
// obstacles in random positions on the grid, through which the robot cannot pass.
// Given the positions of the blocked cells, your task is to count the number of
// paths that the robot can take to move from (1, 1) to (M, N). Since the answer
// can get very large, output the answer modulo 1000000007.

int dp[1001][1001];

int numWays(int Row, int Col) {
    // Base Case
    if(dp[0][0] == -1) return 0;
    // Compute The Number Of Ways For The First Row
    for(int j = 0; j < Col; j++) {
        if(dp[0][j] == -1) break;
        dp[0][j] = 1;
    }
    // Compute The Number Of Ways For The First Column
    for(int j = 0; j < Row; j++) {
        if(dp[j][0] == -1) break;
        dp[j][0] = 1;
    }
    // Bottom Up Approach For Rest Of The Matrix
    for(int i = 1; i < Row; i++) {
        for(int j = 1; j < Col; j++) {
            // If Cell Is Blocked Leave It
            if(dp[i][j] == -1) continue;
            dp[i][j] = 0;
            if(dp[i][j - 1] != -1) dp[i][j] = (dp[i][j - 1] % MOD);
            if(dp[i - 1][j] != -1) dp[i][j] = ((dp[i][j] + dp[i - 1][j]) % MOD);
        }
    }
    // Check For The Final Cell
    if(dp[Row - 1][Col - 1] == -1) return 0;
    return (dp[Row - 1][Col - 1]);
}

int main() {
    memset(dp, 0, sizeof(dp));
    int M, N, P; // M : Number Of Rows & N : Number Of Columns
    cin >> M >> N >> P;
    for(int i = 0; i < P; i++) {
        int X, Y;
        cin >> X >> Y;
        // Mark All The Blocked Cells As -1.
        dp[X - 1][Y - 1] = -1;
    }
    cout << numWays(M, N) << endl;
    return 0;
}