#include<iostream>
using namespace std;

const int N = 100005; 

int a[N];
int prime_count[N];
int mobius[N];

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
    for(int i = 1; i < 30; i++) cout << mobius[i] << " ";
    return 0;
}