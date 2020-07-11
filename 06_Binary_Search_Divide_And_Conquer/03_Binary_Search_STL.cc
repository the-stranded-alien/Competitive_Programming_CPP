#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int arr[] = {20, 30, 40, 40, 40, 50, 100, 1100};
    int n = sizeof(arr) / sizeof(int);
    // Search In A Sorted Array
    int key;
    cin >> key;
    
    bool present = binary_search(arr, arr + n, key);
    if(present) cout << "Element Present" << endl;
    else cout << "Element Not Present" << endl;

    // Get The Index Of The Element !
    // 1. lower_bound (s, e, key) => Address of First Element >= key 
    // 2. upper_bound (s, e, key) => Address of First Element > key

    auto lwr = lower_bound(arr, arr + n, 40);
    cout << "Lower Bound Of 40 : " << (lwr - arr) << endl;

    auto upr = upper_bound(arr, arr + n, 40);
    cout << "Upper Bound Of 40 : " << (upr - arr) << endl;

    cout << "Occurence Frequency Of 40 : " << (upr - lwr) << endl;

    return 0;
}