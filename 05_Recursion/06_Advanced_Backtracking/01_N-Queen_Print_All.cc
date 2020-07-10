#include<iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n) {
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

void solveNQueen(int board[][10], int i, int n) {
    // Base Case
    if(i == n) {
        // Successfully Placed Queens In 'n' Rows (0,......, n - 1)
        // Print The Board
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if(board[x][y] == 1) cout << "Q ";
                else cout << "_ ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    // Recursive Case
    // Try To Place The Queen In The Current Row And Call On The Remaining Part Which Will Be Solved By Recursion
    for(int j = 0; j < n; j++) {
        // Have To Check If (i, j)th Position Is Safe To Place The Queen Or Not.
        if(isSafe(board, i, j, n)) {
            // Place The Queen
            board[i][j] = 1;
            // Check For The Next Queen
            solveNQueen(board, i + 1, n);
            // Means (i, j) Is Not The Right Position - Assumption Is Wrong
            // Backtrack
            board[i][j] = 0;
        } 
    }
    // Have Tried For All Positions In The Current Row But Couldn't Place A Queen.
    return;
}

int main() {
    int N;
    cin >> N;
    int board[10][10] = {0};
    solveNQueen(board, 0, N);
    return 0;
}