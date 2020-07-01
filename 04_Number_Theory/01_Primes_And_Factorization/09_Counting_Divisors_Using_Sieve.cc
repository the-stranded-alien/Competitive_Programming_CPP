#include<iostream>
#include<vector>
using namespace std;

// Counting Number Of Divisors Using Sieve

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
int num_of_divisors(int m, vector<int> &primes) {

    int i = 0;
    int p = primes[0];
    int ans = 1;
    while((p * p) <= m) {
        if(m % p == 0) {
            int count = 0;
            while(m % p == 0) {
                count++;
                m = (m / p);
            }
            ans *= (count + 1);
        }
        // Go To The Next Position
        i++;
        p = primes[i];
    }
    if(m != 1) ans = ans * 2; // 1 Extra Prime Divisor. Multiply Answer With (1 + 1) = 2.
    return ans;
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
        int divisors = num_of_divisors(no, primes);
        cout << divisors << endl;
    }
    return 0;
}