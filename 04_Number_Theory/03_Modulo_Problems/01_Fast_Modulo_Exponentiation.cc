#include<iostream>
using namespace std;

#define ll long long

ll fastModExp(ll a, ll b, ll m) {
    ll res = 1;
    while(b > 0) {
        if(b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}

int main() {
    cout << fastModExp(5, 3, 100) << endl;
    return 0;
}