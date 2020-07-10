#include<iostream>
using namespace std;

bool isSafe(int board[][20], int i, int j, int n) {
    // Check For The Column
    for(int row = 0; row < i; row++) {
        if(board[row][j] == 1) return false;
    }
    // Check The Left Diagonal
    int x = i;
    int y = j;
    while(x >= 0 && y >= 0) {
        if(board[x][y] == 1) return false;
        x--;
        y--;
    }
    // Check The Right Diagonal
    x = i;
    y = j;
    while(x >= 0 && y < n) {
        if(board[x][y] == 1) return false;
        x--;
        y++;
    }
    // The Position Is Now Safe, Checked For Both Column & Diagonal
    return true;
}

int solveNQueen(int board[][20], int i, int n) {
    // Base Case
    if(i == n) return 1;
    // Recursive Case
    int cnt = 0;
    for(int j = 0; j < n; j++) {
        if(isSafe(board, i, j, n)) {
            board[i][j] = 1;
            cnt += solveNQueen(board, i + 1, n);
            board[i][j] = 0;
        } 
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    int board[20][20] = {0};
    cout << solveNQueen(board, 0, N) << endl;
    return 0;
}