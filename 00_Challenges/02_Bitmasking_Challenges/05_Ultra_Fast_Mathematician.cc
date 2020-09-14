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
    int t; cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int len = s1.length();
        for(int i = 0; i < len; i++) {
            if(s1[i] == s2[i]) cout << "0";
            else cout << "1";
        }
        cout << endl;
    }    
    return 0;
}