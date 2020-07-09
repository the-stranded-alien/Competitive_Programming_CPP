#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n) {
    // Base Case
    if(i == m && j == n) {
        soln[m][n] = 1;
        // Print The Path
        for(int x = 0; x <= m; x++) {
            for(int y = 0; y <= n; y++) {
                cout << soln[x][y] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    // Recursive Case
    // Rat Should Be Inside The Grid
    if(i > m || j > n) return false;
    // Cell Should Not Be Blocked
    if(maze[i][j] == 'X') return false;
    // Assume Solution Exists Through Current Cell
    soln[i][j] = 1;
    // Right Hand Side
    bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);
    // Down Side
    bool downSuccess = ratInMaze(maze, soln, i + 1, j, m, n);
    // Backtracking
    // After Hitting Base Case, On The Way Back, Make Everything 0. 
    // Make It 0, Even If It Was Right Or Wrong !!
    soln[i][j] = 0; 
    // Success From Any Direction
    if(rightSuccess || downSuccess) return true;
    return false;
}

int main() {
    char maze[10][10] = {"0000", "00X0", "000X", "0X00"};
    int soln[10][10] = {0};
    int m = 4;
    int n = 4;
    bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);
    if(ans == false) cout << "Path Doesn't Exist !!" << endl;
    return 0;
}