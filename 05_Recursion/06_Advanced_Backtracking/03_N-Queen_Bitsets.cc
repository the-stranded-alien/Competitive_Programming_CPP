#include<iostream>
#include<bitset>
using namespace std;

bitset<30> col, d1, d2;

// Counts All The Possible Configurations 
void solve(int r, int n, int &ans) {
    if(r == n) { ans++; return; }
    for(int c = 0; c < n; c++) {
        if(!col[c] && !d1[r - c + n - 1] && !d2[r + c]) {
            // Placing A Queen, Marking Column & Both The Diagonals.
            col[c] = d1[r - c + n - 1] = d2[r + c] = 1;
            solve(r + 1, n, ans);
            col[c] = d1[r - c + n - 1] = d2[r + c] = 0; // Backtracking (Unplace The Queen)
        }
    }
}

// Prints All The Possible Configurations
void solvePrint(int r, int n, int board[][30]) {
    if(r == n) { 
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
    for(int c = 0; c < n; c++) {
        if(!col[c] && !d1[r - c + n - 1] && !d2[r + c]) {
            // Placing A Queen, Marking Column & Both The Diagonals.
            col[c] = d1[r - c + n - 1] = d2[r + c] = board[r][c] = 1;
            solvePrint(r + 1, n, board);
            col[c] = d1[r - c + n - 1] = d2[r + c] = board[r][c] = 0; // Backtracking (Unplace The Queen)
        }
    }
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    solve(0, n, ans);
    cout << ans << endl;
    int board[30][30] = {0};
    solvePrint(0, n, board);
    return 0;
}