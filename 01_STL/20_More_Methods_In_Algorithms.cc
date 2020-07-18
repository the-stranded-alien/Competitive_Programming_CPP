#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(int);
    // Rotate
    rotate(arr, arr + 2, arr + n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // Apply Same On Vector
    vector<int> v = {10, 20, 30, 40, 50};
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    rotate(v.begin(), v.begin() + 3, v.end());
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    // Next Permutation
    next_permutation(v.begin(), v.end());
    next_permutation(v.begin(), v.end());
    for(auto x : v) cout << x << " ";
    cout << endl;

    // Swap
    int a = 10;
    int b = 20;
    swap(a, b);
    cout << a << " and " << b << endl;

    // Max & Min
    cout << max(a, b) << endl;
    cout << min(a, b) << endl;

    // Reverse
    int c[] = {1,2,3,4,5,6,7};
    int x = sizeof(arr) / sizeof(int);
    reverse(c, c + 4);
    for(int i = 0; i < x; i++) cout << c[i] << " ";
    cout << endl;
    return 0;
}