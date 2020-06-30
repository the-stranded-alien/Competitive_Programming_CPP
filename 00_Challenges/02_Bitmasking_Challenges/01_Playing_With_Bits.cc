#include<iostream>
using namespace std;

// Task is as follows - Prateek Bhayia gives Q queries each query containing
// two integers a and b. Your task is to count the no of set-bits in for all
// numbers between a and b (both inclusive).

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n1, n2;
        cin >> n1 >> n2;
        int bits = 0;
        for(int i = n1; i <= n2; i++) {
            bits += __builtin_popcount(i);
        }
        cout << bits << endl;
    }
    return 0;
}