#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Problem : We are given two sorted arrays of same size n.
// Find the median of an array formed after merging these two sorted arrays.

int main() {
    
    int n;
    cin >> n;
    vector<int> v;

    for(int i=0; i<(n*2); i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    // As The Merged Vector Will Always Have Even Number
    // Of Elements, Median Element Will Be At 'n-1' th 
    // Index After Sorting.
    cout << v[n-1];

    return 0;
}