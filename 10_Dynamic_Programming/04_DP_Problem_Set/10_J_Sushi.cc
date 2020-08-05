#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

double dp[301][301][301];

double sushi(int x, int y, int z, int &n) {
    // Base Case
    if((x < 0) || (y < 0) || (z < 0)) return 0;
    if((x == 0) && (y == 0) && (z == 0)) return 0;
    // Recursive Case
    if(dp[x][y][z] > -0.9) return dp[x][y][z]; // Look Up
    double exp = (n + (x * sushi((x - 1), y, z, n)) + (y * sushi((x + 1), (y - 1), z, n)) + (z * sushi(x, (y + 1), (z - 1), n)));
    return (dp[x][y][z] = (exp / double (x + y + z)));
}

int main() {
    int n, x;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    int one = 0, two = 0, three = 0;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x == 1) one++;
        else if(x == 2) two++;
        else three++;
    }
    cout << fixed << setprecision(8) << sushi(one, two , three, n);
    return 0;
}