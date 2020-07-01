#include<iostream>
using namespace std;

#define ll long long

// Prime Visits - Prime Sieve Problem
// For N (N <= 1000) Queries Print The Count Of
// Prime Numbers Between a & b (a <= 1000000 & b <= 1000000)

// Idea Is To Precompute The Array Of Primes
// Then Make A Cumulative Sum Array

// Sieve Approach - Generate A Array Containing Prime Numbers
void prime_sieve(int *p) {
    // First Mark All Odd Numbers As Primes
    for(int i = 3; i <= 100000; i += 2) {
        p[i] = 1;
    }
    // Sieve
    for(ll i = 3; i <= 100000; i += 2) {
        // If The Current Number Is Not Marked (It Is Prime)
        if(p[i] == 1) {
            // Mark All The Multiples Of 'i' As Not Prime
            for(ll j = (i * i); j <= 100000; j = (j + i)) {
                p[j] = 0;
            }
        }
    }
    // Special Cases
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main() {
    int p[1000005] = {0};
    prime_sieve(p);
    int csum[1000005] = {0};
    // Precompute The Primes Upto An Index 'i'
    for(int i = 1; i <= 1000000; i++) {
        csum[i] = csum[i - 1] + p[i];
    }
    
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << csum[b] - csum[a-1] << endl;
    }

    return 0;
}