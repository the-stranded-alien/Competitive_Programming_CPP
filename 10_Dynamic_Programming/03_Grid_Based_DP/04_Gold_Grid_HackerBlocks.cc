#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

// Gold Grid (HackerBlocks)
// Sayan's friend has left a gamefield organized as an N∗N grid. Each square in the grid
// either has or does not have a gold coin. He has to divide the gamefield with his three
// other friends as follows: he will draw one horizontal line and one vertical line to
// divide the field into four rectangles. His friends will choose three of the four smaller
// fields and he gets the last one. He wants to divide the field so that he gets the maximum
// number of goldcoins, assuming that his friends will pick the best three rectangles.
// (1 <= N <= 1000)

int grid[1005][1005];
int preSum[1005][1005];

// Pre-Computing Prefix Sum DP 2D-Array In Bottom Up Way. 
void prefixGrid(int N) {
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < N; y++) {
            if(x == 0 && y == 0) preSum[x][y] = grid[x][y];
            else if(x == 0) preSum[x][y] = (preSum[x][y - 1] + grid[x][y]);
            else if(y == 0) preSum[x][y] = (preSum[x - 1][y] + grid[x][y]);
            else preSum[x][y] = (preSum[x][y - 1] + preSum[x - 1][y] - preSum[x - 1][y - 1] + grid[x][y]);
        }
    }
    return;
}

int goldGrid(int N) {
    int ans = INT_MIN;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int firstSqr = preSum[i][j];
            int secondSqr = (preSum[i][N - 1] - preSum[i][j]);
            int thirdSqr = (preSum[N - 1][j] - preSum[i][j]);
            int fourthSqr = (preSum[N - 1][N - 1] - firstSqr - secondSqr - thirdSqr);
            ans = max(ans, min(firstSqr, min(secondSqr, min(thirdSqr, fourthSqr))));
        }
    }
    return ans;
}

int main() {
    memset(grid, 0, sizeof(grid));
    memset(preSum, 0, sizeof(preSum));
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        grid[X - 1][Y - 1] = 1;
    }
    prefixGrid(N);
    cout << goldGrid(N) << endl;
    return 0;
}
