#include<iostream>
using namespace std;

// Calculating Multiplicative Modulo Inverse Using Extended Euclid's Method

int gcd(int a, int b) {
    // Base Case
    if(b == 0) return a;
    // Recursive Case
    return gcd(b, a % b);
}

int x, y, GCD;

void extendedEuclidMethod(int a, int b) {
    // Base Case
    if(b == 0) {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }
    // Recursive Case
    extendedEuclidMethod(b, a % b);
    int cX = y;
    int cY = x - (a / b) * y;
    x = cX;
    y = cY; 
}

int inverseModulo(int a, int m) {
    if(gcd(a, m) == 1){
        extendedEuclidMethod(a, m);
        return ((x + m) % m); // Making Positive
    }
    else return -1;
}

int main() {
    cout << inverseModulo(18, 7) << endl;
    return 0;
}