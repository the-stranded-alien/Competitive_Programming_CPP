#include<iostream>
using namespace std;

#define ll long long

// Naive Approach - 1 ( O(N) For 1 Number)
bool isPrime1(int n) {
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i < n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

// Naive Approach - 2 ( O(sqrt(N)) For 1 Number)
bool isPrime2(int n) {
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; (i * i) < n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

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
    // cout << "Enter Number Upto Which You Want To Print Primes : ";
    int n;
    cin >> n;
    int p[100005] = {0};
    prime_sieve(p);

    // Lets Print Primes Upto Range 'n'
    for(int i = 0; i <= n; i++) {
        if(p[i] == 1) cout << i << " ";
    }
    return 0;
}