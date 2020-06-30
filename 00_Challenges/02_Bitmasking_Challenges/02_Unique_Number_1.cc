#include<iostream>
using namespace std;

// We are given an array containg n numbers. All the numbers are present twice
// except for one number which is only present once. Find the unique number
// without taking any extra spaces and in linear time.

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        ans = ans ^ num;
    }
    cout << ans << endl;
}