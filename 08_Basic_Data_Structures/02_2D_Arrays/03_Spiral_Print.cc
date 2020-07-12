#include<iostream>
using namespace std;

// Spiral Print
void spiral_print(int a[][100], int m, int n) {
    int startRow = 0;
    int startCol = 0;
    int endRow = m - 1;
    int endCol = n - 1;
    while(startRow <= endRow && startCol <= endCol) {
        // First Row
        for(int i = startCol; i <= endCol; i++) cout << a[startRow][i] << " ";
        startRow++;
        // Last Column
        for(int i = startRow; i <= endRow; i++) cout << a[i][endCol] << " ";
        endCol--;
        // Bottom Row
        if(endRow > startRow) {
            for(int i = endCol; i >= startCol; i--) cout << a[endRow][i] << " ";
            endRow--;
        }
        // First Column
        if(endCol > startCol) {
            for(int i = endRow; i >= startRow; i--) cout << a[i][startCol] << " ";
            startCol++;
        }
    }
    return;
}

int main() {
    int b[100][100];
    int m, n;
    cin >> m >> n;
    for(int row = 0; row <= (m - 1); row++) {
        for(int col = 0; col <= (n - 1); col++) cin >> b[row][col];
    }
    spiral_print(b, m, n);
    return 0;
}