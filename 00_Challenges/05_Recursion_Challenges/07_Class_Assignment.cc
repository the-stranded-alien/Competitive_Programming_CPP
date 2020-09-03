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

int countInt(int n) {
    if((n == 1) || (n == 2)) return (n + 1);
    return (countInt(n - 1) + countInt(n - 2));
}

int main() {
    FIO;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << "#" << n << " : " << countInt(n) << endl;
    }   
    return 0;
}