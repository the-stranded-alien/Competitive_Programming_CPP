#include<iostream>
#include<vector>
using namespace std;

// Prime Factorization Using Optimized Prime Sieve

vector<int> primeSieve(int *p, int n) {
    p[0] = p[1] = 0;
    p[2] = 1;

    // Mark All Odd Numbers As Prime (Initialisation)
    for(int i = 3; i <= n; i += 2) p[i] = 1;

    // Sieve Login To Mark Non Prime Numbers As 0
    // 1. Optimization : Iterate Only Over Odd Numbers
    for(int i = 3; i <= n; i += 2) {
        if(p[i]) {
            // Mark All The Multiples Of That Number As Not Prime
            // 2. Optimization : Take A Jump Of (2 * i) Starting From (i * i).
            for(int j = (i * i); j <= n; j += (2 * i)) {
                p[j] = 0;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);
    for(int i = 3; i <= n; i += 2) {
        if(p[i] == 1) primes.push_back(i);
    }
    return primes;
}

// This Function Returns A Vector Of Prime Factors
vector<int> factorize(int m, vector<int> &primes) {

    vector<int> factors;
    factors.clear();

    int i = 0;
    int p = primes[0];

    while((p * p) <= m) {
        if(m % p == 0) {
            // factors.push_back(p); // If Just The Unique Factors Are Needed
            while(m % p == 0) {
                factors.push_back(p); // If Factors Along With Their Count Is Needed
                m = (m / p);
            }
        }
        // Go To The Next Position
        i++;
        p = primes[i];
    }
    if(m != 1) factors.push_back(m);
    return factors;
}

int main() {
    int N = 100000;
    int p[N] = {0}; // for(int i = 0; i < N; i++) p[i] = 0;
    vector<int> primes = primeSieve(p, 10000);

    int t;
    cin >> t;
    while(t--) {
        int no;
        cin >> no;
        vector<int> factors = factorize(no, primes);
        for(auto f : factors) {
            cout << f << " ";
        }
        cout << endl;
    }
    return 0;
}