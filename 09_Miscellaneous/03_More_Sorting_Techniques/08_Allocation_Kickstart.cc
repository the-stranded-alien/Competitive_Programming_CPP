#include<iostream>
#include<algorithm>
using namespace std;

// There are N houses for sale. The i-th house costs Ai dollars to buy.
// You have a budget of B dollars to spend. What is the maximum number of houses you can buy?

int main() {
    int t;
    cin >> t;
    int tc = 0;
    int n, b;
    int a[10000];
    while(t--) {
        tc++;
        cin >> n >> b;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n); // O(N.log(N))
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(b >= a[i]) {
                ans++;
                b -= a[i];
            }
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}