#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

// Space Optimized Sieve Using Bitset

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

void sieve() {
    // Set All Bits
    b.set();
    b[0] = b[1] = 0;
    for(long long int i = 2; i <= n; i++) {
        if(b[i]) {
            primes.push_back(i);
            for(long long int j = (i * i); j <= n; j = (j + i)) {
                b[j] = 0;
            }
        }
    }
}

int main() {
    sieve();
    for(int i = 0; i <= 100; i++) {
        cout << primes[i] << " ";
    }
}