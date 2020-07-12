#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10000];
    for(int i = 0; i < n; i++) cin >> a[i];
    // Algorithm To Find The Largest And The Smallest Number
    int largest = INT_MIN;
    int smallest = INT_MAX;
    for(int i = 0; i < n; i++) {
        largest = max(largest, a[i]);
        smallest = min(smallest, a[i]);
        // if(a[i] > largest) largest = a[i];
        // if(a[i] < smallest) smallest = a[i];
    }
    cout << "Smallest : " << smallest << endl;
    cout << "Largest  : " << largest << endl;
    return 0;
}