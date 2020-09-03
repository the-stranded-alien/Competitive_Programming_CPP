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

ll friendsPairing(int n) {
    // Base Case
    if(n == 0) return 1;
    if((n == 1) || (n == 2)) return n;
    // Recursive Case
    return (friendsPairing(n - 1) + ((n - 1) * friendsPairing(n - 2)));
}

int main() {
    FIO;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << friendsPairing(n) << endl;
    }
    return 0;
}