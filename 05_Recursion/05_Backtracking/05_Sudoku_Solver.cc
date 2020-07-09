#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int number) {
    // Checking For Row And Column
    for(int x = 0; x < n; x++) {
        if(mat[x][j] == number || mat[i][x] == number) return false;
    }
    // Checking For Sub-Grid
    int rn = sqrt(n);
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;
    for(int x = sx; x < (sx + rn); x++) {
        for(int y = sy; y < (sy + rn); y++) {
            if(mat[x][y] == number) return false;
        }
    }
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n) {
    // Base Case
    if(i == n) {
        // Completely Filled All 'n' Rows
        // Print The Sudoku Matrix
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                cout << mat[x][y] << " ";
            }
            cout << endl;
        }
        return true;
    }
    // Case For Row End
    if(j == n) return solveSudoku(mat, i + 1, 0, n);
    // Skip The Prefilled Cells
    if(mat[i][j] != 0) return solveSudoku(mat, i, j + 1, n);
    // Recursive Case
    // Fill The Current Cell With Possible Options
    for(int number = 1; number <= n; number++) {
        if(canPlace(mat, i, j, n, number)) {
            // Assume This Number Is Correct
            mat[i][j] = number;
            bool couldWeSolve = solveSudoku(mat, i, j + 1, n);
            if(couldWeSolve == true) return true;
        }
    }
    // Backtrack Here (After Trying All Numbers From 1 to (n - 1))
    mat[i][j] = 0;
    return false;
}

int main() {
    int mat[9][9] =
        {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        };
    solveSudoku(mat, 0, 0, 9);
    
    return 0;
}