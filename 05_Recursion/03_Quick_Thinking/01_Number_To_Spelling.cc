#include<iostream>
using namespace std;

// Number To Spellings
// 2048 -> two zero four eight

char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printSpellings(int n) {
    // Base Case
    if(n == 0) return;
    // Recursive Case
    // First Print The Spellings Of (204)
    printSpellings(n / 10);
    // Work Done After The Function Call
    int digit = (n % 10);
    cout << words[digit] << " ";
    return;
}

int main() {
    int n;
    cin >> n;
    printSpellings(n);
    return 0;
}