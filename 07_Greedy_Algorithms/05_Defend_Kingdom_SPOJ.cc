#include<iostream>
#include<algorithm>
using namespace std;

// Defend Kingdom (DEFKIN) - SPOJ 
// Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player
// defends the Kingdom that is represented by a rectangular grid of cells. The player builds
// crossbow towers in some cells of the grid. The tower defends all the cells in the same row
// and the same column. No two towers share a row or a column.
// The penalty of the position is the number of cells in the largest undefended rectangle.

int main() {
    int t;
    int w, h, n;
    cin >> t;
    int X[40010], Y[40010];
    while(t--) {
        cin >> w >> h >> n;
        for(int i = 0; i < n; i++) cin >> X[i] >> Y[i];
        // Sorting
        sort(X, X + n);
        sort(Y, Y + n);
        // Compute Delta X & Delta Y
        int dx = X[0] - 1;
        int dy = Y[0] - 1;
        for(int i = 1; i < n; i++) {
            dx = max(dx, (X[i] - X[i - 1] - 1));
            dy = max(dy, (Y[i] - Y[i - 1] - 1));
        }
        // Corner Case (Last Tower To Grid End)
        dx = max(dx, w - X[n - 1]);
        dy = max(dy, h - Y[n - 1]);

        cout << (dx * dy) << endl;
    }
    return 0;
}