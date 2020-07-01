#include<iostream>
#include<vector>
using namespace std;

// Almost Prime : A number is called almost prime if it has exactly two distinct prime
// divisors. For example, 6, 18, 24 are almost prime, while, 4, 8, 9, 42 are not.
// Find The Amount Of Almost Prime Numbers which are between 1 and 'n', inclusive.

// Sieve - To Store The Number Of Distinct Prime Factors For Every Number

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

const int N = 3005;

int sieve(int n) {
    int pr[n + 1] = {};
    vector<int> primes;
    int i, j;
    for(i = 2; i <= n; i++) {
        if(!pr[i]) {
            primes.pb(i);
            for(j = i; j <= n; j += i) {
                pr[j]++;
            }
        }
    }
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(pr[i] == 2) ans++;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    cout << sieve(n);
    return;
}

// int32_t main() {
//     ios_base:: sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     solve();
//     return 0;
// }

int32_t main() {
    solve();
    return 0;
}