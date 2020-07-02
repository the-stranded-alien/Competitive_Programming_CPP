#include<iostream>
using namespace std;

// The Football Season - Codeforces (1244 C)
// The football season has just ended in Berland. According to the rules of Berland football,
// each match is played between two teams. The result of each match is either a draw, or a
// victory of one of the playing teams. If a team wins the match, it gets w points, and the
// opposing team gets 0 points. If the game results in a draw, both teams get d points.
// The manager of the Berland capital team wants to summarize the results of the season, but,
// unfortunately, all information about the results of each match is lost. The manager only
// knows that the team has played n games and got p points for them.
// You have to determine three integers x, y and z — the number of wins, draws and loses of
// the team. If there are multiple answers, print any of them. If there is no suitable triple
// (x,y,z), report about it. If there is no answer, print −1. Otherwise print three non-negative
// integers x, y and z — the number of wins, draws and losses of the team. If there are multiple
// possible triples (x,y,z), print any of them. The numbers should meet the following conditions:
// (x * w) + (y * d) = p & (x + y + z) = n.

int __gcd(int a, int b) {
    return (b == 0 ? a : __gcd(b, a % b));
}

int modInverse(int a, int m) {
    if(m == 1) return 0;
    int mo = m, y = 0, x = 1;
    while(a > 1) {
        int q = a / m;
        int t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if(x < 0) x += mo;

    return x;
}

void solve() {
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    int x, y, z;
    int g = __gcd(w, d);
    if(p % g != 0) {
        cout << -1;
        return;
    }
    // Team Win All Matches Still Can't Get 'p' Points
    if(n * w < p) {
        cout << -1;
        return;
    }
    p /= g;
    w /= g;
    d /= g;
    // Draw
    y = ((p % w) * modInverse(d, w)) % w;
    // Wins
    x = (p - y * d) / w;
    if(x + y > n) {
        cout << -1;
        return;
    }
    if(x < 0) {
        cout << -1;
        return;
    }
    z = n - x + y;
    cout << x << " " << y << " " << z << endl;
}

int main() {
    solve();
}

