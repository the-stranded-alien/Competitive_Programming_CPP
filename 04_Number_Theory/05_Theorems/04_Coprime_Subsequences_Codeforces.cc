#include<iostream>
using namespace std;

// Coprime Subsequences (Codeforces - 803F)
// Let's call a non-empty sequence of positive integers a 1, a 2... a k coprime
// if the greatest common divisor of all elements of this sequence is equal to 1.
// Given an array a consisting of n positive integers, find the number of its
// coprime subsequences. Since the answer may be very large, print it modulo 109 + 7.
// Note that two subsequences are considered different if chosen indices are different.
// For example, in the array [1, 1] there are 3 different subsequences: [1], [1] and [1, 1].

#define mod 1000000007
const int N = 100005; 


int a[N];
int prime_count[N];
int mobius[N];
int freq[N];
int p2[N];

int calculate_mobius() {
    int i, j;
    for(i = 1; i < N; i++) a[i] = 1;
    for(i = 2; i < N; i++) {
        if(prime_count[i]) continue;
        for(j = i; j < N; j += i) {
            prime_count[j]++;
            a[j] *= i;
        }
    }
    for(i = 1; i < N; i++) {
        if(a[i] == i) {
            // Square Free Number
            if(prime_count[i] % 2 == 1) mobius[i] = -1;
            else mobius[i] = 1;
        } else mobius[i] = 0;
    }
}

int main() {
    calculate_mobius();
    int n;
    cin >> n;
    int b[n];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        freq[b[i]]++;
    }
    p2[0] = 1;
    for(int i = 1; i < N; i++) {
        p2[i] = p2[i - 1] * 2;
        p2[i] %= mod;
    }
    for(int i = 1; i < N; i++) {
        int cnt = 0;
        for(int j = i; j < N; j +=i) {
            cnt += freq[j];
        }
        // How Many Numbers Are Divisible By 'i'.
        int total_subsequences = p2[cnt] - 1;
        ans += mobius[i] * total_subsequences;
        ans %= mod;
    }
    ans += mod;
    cout << ans % mod;
    
    return 0;
}