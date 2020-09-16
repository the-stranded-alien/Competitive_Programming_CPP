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



int main() {
    FIO;
    int x, n; cin >> x >> n;
    int pow = x;
    int res = 1;
    while(n > 0) {
        if(n & 1) res = res * pow;
        pow = pow * pow;
        n = n >> 1;
    }    
    cout << res << endl;
    return 0;
}