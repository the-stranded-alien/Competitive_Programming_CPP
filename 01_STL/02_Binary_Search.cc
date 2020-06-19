#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int arr[] = {20, 30, 40, 40, 40, 50, 100, 1100};
    int n = sizeof(arr) / sizeof(int);

    // Search In A Sorted Way
    int key;
    cout << "Enter Key : ";
    cin >> key;

    bool present = binary_search(arr, arr + n, key);

    if (present){
        
        cout << "Present" << endl;

        // Get The Index Of The Elements
        // lower_bound(s,e,key) and upper_bound(s,e,key)

        // lower_bound -> returns address of
        // first element that is >= key
        auto lb = lower_bound(arr, arr + n, key);
        cout << "Lower Bound Of " << key << " : " << (lb - arr) << endl;

        // upper_bound -> returns address of
        // first element that is > key
        auto ub = upper_bound(arr, arr + n, key);
        cout << "Upper Bound Of " << key << " : " << (ub - arr) << endl;

        cout << "Occurence Frequency Of " << key << " Is : " << (ub - lb) << endl;

    } else {
        cout << "Absent" << endl;
    }

    return 0;
}