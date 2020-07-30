#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Bottom Up Approach
int matricChainMultiplication(vector<int> &A) {
    int dp[200][200] = {0}; // Memory
    int n = A.size() - 1;
    for(int i = 1; i < n; i++) {
        int row = 0;
        int col = i;
        while(col < n) {
            // Traversing Diagonal After Diagonal !!
            // cout << "(" << (row + 1) << ", " << (col + 1) << ")" << endl;
            int val = INT_MAX;
            for(int pivot = row; pivot < col; pivot++) {
                val = min(val, (dp[row][pivot] + dp[pivot + 1][col] + (A[row] * A[pivot + 1] * A[col + 1])));
            }
            dp[row][col] = val;
            row++;
            col++;
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> matrices{4, 2, 3, 1, 3};
    cout << matricChainMultiplication(matrices) << endl;
    return 0;
}