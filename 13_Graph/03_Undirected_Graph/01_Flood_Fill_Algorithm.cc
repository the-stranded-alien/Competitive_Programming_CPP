#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int R, C;

// West, North, East, South
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void printMat(char input[][15]) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) cout << input[i][j] << " ";
        cout << endl;
    }
}

// 'ch' Is The Character To Be Replaced
// 'color' Is The Character To Be Added
void floodFill(char mat[][15], int i, int j, char ch, char color) {
    // Base Case - Matrix Bounds
    if((i < 0) || (j < 0) || (i >= R) || (j >= C)) return;
    // Figure Boundary Condition
    if(mat[i][j] != ch) return;
    // Color Current Cell
    mat[i][j] = color;
    // Recursive Case
    for(int k = 0; k < 4; k++) floodFill(mat, (i + dx[k]), (j + dy[k]), ch, color);
    return;
}

int main() {
    FIO;
    cin >> R >> C;
    char input[15][15];
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) cin >> input[i][j];
    }
    printMat(input);
    floodFill(input, 5, 5, '.', 'r');
    printMat(input);
    return 0;
}
