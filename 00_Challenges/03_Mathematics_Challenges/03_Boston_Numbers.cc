#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define pb push_back
#define F first
#define S second
#define P pair<int, int>
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// A Boston number is a composite number, the sum of whose digits is the sum of the digits
// of its prime factors obtained as a result of prime factorization (excluding 1 ). The
// first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 . For example,
// 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7.
// Write a program to check whether a given integer is a Boston number.

bool isPrime(int n) {
    bool flag = true;
    for(int i = 2; (i * i) <= n; i++) {
        if(n % i == 0) flag = 0;
    }
    return flag;
}

void primeFactorization(int n, vector<int> &factors) {
    for(int i = 2; (i * i) <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                factors.pb(i);
                n = (n / i);
            }
        }
    }
    if(n != 1) factors.pb(n);
}

int sumDigitsFromVec(vector<int> vec) {
    int sumOfDigits = 0;
    for(auto num : vec) {
        while(num > 0) {
            int dig = num % 10;
            sumOfDigits += dig;
            num = (num / 10);
        }
    }
    return sumOfDigits;
}

int sumDigits(int n) {
    int sumDig = 0;
    while(n > 0) {
        int dig = (n % 10);
        sumDig += dig;
        n = (n / 10);
    }
    return sumDig;
}

int main() {
    FIO;
    int n; cin >> n;
    if(isPrime(n) == false) {
        vector<int> prime_factors;
        primeFactorization(n, prime_factors);
        int sumPrimeFactors = sumDigitsFromVec(prime_factors);
        int sumNum = sumDigits(n);
        if(sumNum == sumPrimeFactors) cout << 1 << endl;
        else cout << 0 << endl;
    } else cout << 0 << endl;   
    return 0;
}