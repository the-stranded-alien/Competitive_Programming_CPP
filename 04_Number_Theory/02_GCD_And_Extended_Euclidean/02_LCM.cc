#include<iostream>
using namespace std;

// LCM Of Two Numbers

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    cout << ((n1 * n2) / gcd(n1, n2)) << endl;
    return 0;
}