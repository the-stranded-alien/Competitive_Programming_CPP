#include<iostream>
using namespace std;

int multiply(int a, int b) {
    // Base Case
    if(b == 1) return a;
    // Recursive Case
    return (a + multiply(a, b - 1));
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
    return 0;
}