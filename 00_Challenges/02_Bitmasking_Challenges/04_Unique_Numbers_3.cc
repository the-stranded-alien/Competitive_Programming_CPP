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
    int countArray[64] = {0};
    int n; cin >> n;
    int no;
    while(n--) {
        cin >> no;
        int j = 0;
        while(no > 0) {
            int last_bit = (no & 1);
            countArray[j++] += last_bit;
            no = (no >> 1);
        }
    }
    int p = 1;
    int ans = 0;
    for(int i = 0; i < 64; i++) {
        countArray[i] %= 3;
        ans += (countArray[i] * p);
        p = (p << 1);
    }
    cout << ans << endl;
    return 0;
}