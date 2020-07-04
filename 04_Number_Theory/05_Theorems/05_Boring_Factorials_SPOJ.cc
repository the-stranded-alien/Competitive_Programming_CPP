#include<iostream>
using namespace std;

// Boring Factorial (SPOJ) -- Wilson's Theorem
// Sameer and Arpit want to overcome their fear of Maths and so they have been recently
// practicing Maths problems a lot. Aman, their friend has been helping them out. But as
// it goes, Sameer and Arpit have got bored of problems involving factorials. Reason being,
// the factorials are too easy to calculate in problems as they only require the residue
// modulo some prime and that is easy to calculate in linear time. So to make things
// interesting for them, Aman - The Mathemagician, gives them an interesting task. He gives
// them a prime number P and an integer N close to P, and asks them to find N! modulo P.
// He asks T such queries. 1 < P <= 2*10^9, 1 <= N <= 2*10^9, Abs(N-P) <= 1000
#define ll long long

// Fast Modulo Exponentiation
ll fastModExp(ll a, ll b, ll m) {
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}

ll solve(ll n, ll p) {
    ll ans = -1;
    for(ll i = (n + 1); i <= (p - 1); i++) {
        ll temp = fastModExp(i, p - 2, p);
        ans = (ans * temp) % p;
    }
    return ans + p;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        ll p;
        cin >> n >> p;
        if(n >= p) cout << 0 << endl;
        else cout << solve(n, p) << endl;
    }
    return 0;
}