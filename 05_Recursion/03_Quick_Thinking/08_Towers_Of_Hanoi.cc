#include<iostream>
using namespace std;

void move(int n, char src, char helper, char dest) {
    // Base Case
    if(n == 0) return;
    // Recursive Case
    // Move '(n - 1)' Disk From Source To Helper
    move(n - 1, src, dest, helper);
    cout << "Shift Disk " << n << " From " << src << " To " << dest << " Using " << helper << endl;
    // Move '(n - 1)' Disk From Helper To Destination
    move(n - 1, helper, dest, src);
    return;  
}

int main() {
    int n;
    cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}