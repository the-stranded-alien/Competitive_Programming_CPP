#include<iostream>
#include<map>
using namespace std;

// Codeforces Hack
// f(n) Be The (n + 1) th Fibonacci Number, We Have Two Case: n Is Even And n Is Odd.
// f(2 * k) = f(k) * f(k) + f(k - 1) * f(k - 1)  (for Even)
// f(2 * k + 1) = f(k) * f(k + 1) + f(k - 1) * f(k) (for Odd)
// Only O(4 * log n) States, So We Use Hashmap Instead Of DP Table
// It's A Bottom-Up DP Approach Using Divide & Conquer

#define ll long long
const ll M = 1000000007; // Modulo
map<ll, ll> F;

ll f(ll n) {
    if(F.count(n)) return F[n];
    ll k = (n / 2);
    if(n % 2 == 0) {
        // (n = 2 * k)
        return F[n] = ((f(k) * f(k)) + (f(k-1) * f(k-1))) % M;
    } else {
        // (n = (2 * k) + 1)
        return F[n] = ((f(k) * f(k + 1)) + (f(k - 1) * f(k))) % M;
    }
}

int main() {
    ll n;
    F[0] = F[1] = 1;
    while(cin >> n) {
        cout << (n == 0 ? 0 : f(n-1)) << endl;
    }
    // Time Complexity -> O(log n * log log n)
}


