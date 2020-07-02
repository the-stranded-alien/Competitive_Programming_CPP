#include<iostream>
using namespace std;

int gcd(int a, int b) {
    // Base Case
    if(b == 0) return a;
    // Recursive Case
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return ((a * b) / gcd(a, b));
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
    // cout << cX << ", " << cY << endl;
    x = cX;
    y = cY; 
}

int main() {
    // (18.X + 30.Y = 6)
    extendedEuclidMethod(18, 30);
    cout << x << ", " << y << endl; 
    return 0;
}