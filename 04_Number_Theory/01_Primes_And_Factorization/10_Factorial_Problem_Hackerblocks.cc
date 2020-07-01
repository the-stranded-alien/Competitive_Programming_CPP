#include<iostream>
using namespace std;

// Find The Maximum Value Of 'x' Such That ((n!) % (k ^ x)) = 0

#define INT_MAX 100000000

int main() {

    int t;
    cin >> t;
    int n, k;
    while(t--) {
        cin >> n >> k;
        int ans = INT_MAX;
        // Factorization Of K.
        // p1, p2, p3, ......, pl.
        int occur;
        for(int i = 2; (i * i) <= k; i++) {
            if((k % i) == 0) {
                occur = 0;
                while(k % i == 0) {
                    occur++;
                    k = (k / i);
                }
                // Find Out The Powers Of 'i' In (n!) Side By Side
                int cnt = 0;
                long long int p = i;
                while(p <= n) {
                    cnt += (n / p);
                    p = p * i;
                }
                ans = min(ans, (cnt/occur));     
            }
        }
        // One Prime Factor Can Be Greater Than Sqrt(N).
        // All Other Prime Factors Will Be Smaller Than Sqrt(N).
        // We May Have A Case When Still A Prime Factor Is Left.
        if(k > 1) {
            long long int p = k;
            int cnt = 0;
            while(p <= n) {
                cnt += (n / p);
                p *= k;
            }
            ans = min(ans, cnt);
        }
        if(ans == INT_MAX) ans = 0;
        cout << ans << endl;
    }
    return 0;
}