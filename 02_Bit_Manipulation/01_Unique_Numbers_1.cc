#include<iostream>
using namespace std;

// Problem - Unique Numbers 2N + 1
// Given a List of Numbers Where Every Number Occurs
// Twice Except One, Find That Unique Number

int main() {
    
    int n;
    cin >> n;
    
    int no;    
    int ans = 0;

    // Bitwise XOR Operator To Solve,
    // No Need To Take Any Storage Space.

    for(int i=0; i<n; i++){
        cin >> no;
        ans = ans ^ no;
    }

    cout << "Unique Number : " << ans << endl;

    return 0;
}