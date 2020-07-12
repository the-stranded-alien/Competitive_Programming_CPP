#include<iostream>
using namespace std;

int main() {
    int b[100][100];
    int m, n;
    cin >> m >> n;
    for(int row = 0; row <= (m - 1); row++) {
        for(int col = 0; col <= (n - 1); col++) cin >> b[row][col];
    }
    // Wave Print
    for(int col = 0; col < n; col++) {
        if(col % 2 == 0) {
            // Even Column -> Top Down
            for(int row = 0; row <= (m - 1); row++) cout << b[row][col] << " ";
        }
        else {
            // Odd Column -> Bottom Up
            for(int row = (m - 1); row >= 0; row--) cout << b[row][col] << " ";
        }
    }
    return 0;
}