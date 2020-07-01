#include<iostream>
#include<vector>
using namespace std;

// Sample Problem -> PRIME1 - Prime Generator (SPOJ)
// Generate All Prime Numbers Between Two Numbers (m & n).
// (1 <= m <= n <= (10^9), (n - m) <= (10^5))

const int N = 100005; // RANGE = (n - m)
vector<int> primes;
int p[N] = {0};

void sieve() {
    for(int i = 2; i <= N; i++) {
        if(p[i] == 0) {
            // Store 'i' To The Primes Vector
            primes.push_back(i);
            // Mark All Multiples Of 'i' As Not Prime
            for(int j = i; j <= N; j += i) {
                p[j] = 1; // Not Prime
            }
        }
    }
}

int main() {
    sieve(); // Build The Sieve Once For All
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> m >> n;
        bool segment[n - m + 1];
        for(int i = 0; i < (n - m + 1); i++) {
            segment[i] = 0; // Mark All As Primes
        }
        // Segmented Sieve Logic
        for(auto x : primes) {
            if((x * x) > n) break; // Stop The Loop If Remaining Prime Numbers Are Not Needed
            int start = ((m / x) * x);
            // Prime Number Lies In The Segment Sieve Range
            if(x >= m and x <= n) {
                start = x * 2;
            }
            // Mark All Multiples Of 'x', In The Range Start To 'n' As Not Primes.
            for(int i = start; i <= n; i += x) {
                segment[i - m] = 1; // Mark As Not Prime
                // if((i - m) >= 0) segment[i - m] = 1;
            } 
        }
        // Loop Over The Range (m.....n) And Print The Primes
        for(int i = m; i <= n; i++) {
            if(segment[i - m] == 0 and i != 1) {
                cout << i << endl;
            }
        }
        cout << endl;
    } 
    return 0;
}