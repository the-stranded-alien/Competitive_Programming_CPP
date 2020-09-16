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
    int n; cin >> n;
    ll catalan[n];
    catalan[0] = catalan[1] = 1;
    for(int i = 2; i <= n; i++){
        catalan[i] = 0;
        for(int j = 0; j < i; j++) catalan[i] += catalan[j] * catalan[i-j-1];
    }
    cout << catalan[n] << endl;
    return 0;
}