#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define pb push_back
#define F first
#define S second
#define P pair<int, int>
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Hänschen dreams he is in a shop with an infinite amount of marbles. He is allowed to
// select n marbles. There are marbles of k different colors. From each color, there are
// also infinitely many marbles. Hänschen wants to have at least one marble of each color,
// but still there are a lot of possibilities for his selection. In his effort to make a
// decision he wakes up. Now he asks you how many possibilities for his selection he would
// have had. Assume that marbles of equal color can't be distinguished, and the order of the
// marbles is irrelevant.

ll nCr(int x, int y) {
	if((x == y) || (y == 0)) return 1;
	if(y == 1) return (ll) x;
	ll ans = 1;
	if(y > (x - y)) y = (x - y);
	for(int i = 0; i < y; i++) {
		ans = (ans * (x - i)) / (i + 1);
	}
	return ans;
}

int main() {
    FIO;
    int t; cin >> t;
    while(t--) {
        int num; cin >> num;
        int colors; cin >> colors;
        cout << nCr((num - 1), (colors - 1)) << endl;
    }
    return 0;
}