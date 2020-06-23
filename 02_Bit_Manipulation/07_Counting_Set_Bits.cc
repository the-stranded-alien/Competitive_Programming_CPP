#include<iostream>
using namespace std;

// First Method
int countBits(int n) {
    int ans = 0;
    while(n > 0) {
        ans += (n & 1);
        n = (n >> 1);
    }
    return ans;
}

// Second Method
int countBitsFast(int n) {
    int ans = 0;
    while(n > 0) {
        n = (n & (n - 1));
        ans++;
    }
    return ans;
}

// Given a Number N, Find Number of Set Bits 
// In Binary Representation of it.

int main() {

    int n;
    cout << "Enter N : ";
    cin >> n;

    cout << "Count Of Set Bits (Method 1) : " << countBits(n) << endl;
    cout << "Count Of Set Bits (Method 2) : " << countBitsFast(n) << endl;
    cout << "Count Of Set Bits (Built-In) : " << __builtin_popcount(n) << endl;
    
    return 0;
}