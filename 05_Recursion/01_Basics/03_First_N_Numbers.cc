#include<iostream>
using namespace std;

// First N Numbers In Decreasing Order
void decreasing(int n) {
    // Base Case
    if(n == 0) return;
    // Recursive Case
    cout << n << " ";
    decreasing(n - 1);
    return;
}

// First N Numbers In Increasing Order
void increasing(int n) {
    // Base Case
    if(n == 0) return;
    increasing(n - 1);
    cout << n << " ";
    return;
}

int main() {
    int n;
    cin >> n;
    decreasing(n);
    cout << endl;
    increasing(n);
    return 0;
}