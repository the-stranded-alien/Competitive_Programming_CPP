#include<iostream>
using namespace std;

int main() {
    int a[5][3] = {0};
    // Iterate Over The Array
    int val = 1;
    for(int row = 0; row <= 4; row++) {
        for(int col = 0; col <= 2; col++) {
            a[row][col] = val;
            val = val + 1;
            cout << a[row][col] << " ";
        }
        cout << endl;
    }
    int b[100][100];
    int m, n;
    cin >> m >> n;
    for(int row = 0; row <= (m - 1); row++) {
        for(int col = 0; col <= (n - 1); col++) {
            cin >> b[row][col];
        }
    }
    for(int row = 0; row <= (m - 1); row++) {
        for(int col = 0; col <= (n - 1); col++) {
            cout << b[row][col] << " ";
        }
        cout << endl;
    }
    return 0;
}