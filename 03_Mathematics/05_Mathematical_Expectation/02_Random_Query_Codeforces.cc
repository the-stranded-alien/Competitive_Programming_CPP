#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

// F. Random Query (Codeforces 846F)
// You are given an array a consisting of n positive integers.
// You pick two integer numbers l and r from 1 to n, inclusive
// (numbers are picked randomly, equiprobably and independently).
// If l > r, then you swap values of l and r. You have to calculate
// the expected value of the number of unique elements in segment
// of the array from index l to index r, inclusive (1-indexed).

#define ll long long

ll a[1000006] = {0};
ll lastocc[1000006] = {0};
ll ans[1000006] = {0};

int main() {
    int n;
    cin >> n;
    // Input Array
    for(ll i = 1; i <= n; i++) cin >> a[i];
    memset(lastocc, 0, sizeof(lastocc));
    memset(ans, 0, sizeof(ans));
    ans[0] = 0;
    double sum = 0.0;
    for(ll i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + (i - lastocc[a[i]]);
        lastocc[a[i]] = i;
        // Sum
        sum = sum + ans[i];
    }
    double finalAns = 0.0;
    finalAns = (((2 * (sum - n)) + n) / (n * n * 1.0));
    cout << fixed << setprecision(6) << finalAns << endl;
    return 0;
}