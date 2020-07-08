#include<iostream>
using namespace std;

// Count Binary Strings of Length 'N', Which Have No Consecutive Ones.

int binaryStrings(int n) {
    // Base Case
    if(n == 0) return 0;
    if(n == 1) return 2;
    if(n == 2) return 3;
    // Recursive Case
    return (binaryStrings(n - 1) + binaryStrings(n - 2));
}

// int countStrings(int n, int last) {
//     if(n == 0) return 0;
//     if(n == 1) {
//         if(last) return 1;
//         else return 2;
//     }
//     if(last == 0) return (countStrings(n - 1, 0) + countStrings(n - 1, 1));
//     else return countStrings(n - 1, 0);
// }

int main() {
    int n;
    cin >> n;
    cout << binaryStrings(n) << endl;
    // cout << countStrings(n, 0) << endl;
    return 0;
}