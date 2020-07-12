#include<iostream>
using namespace std;

int main() {
    int n, key;
    cin >> n;
    int a[10000];
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << "Enter Key : ";
    cin >> key;
    // Find Out The Index Of The Element By Traversing The Array
    // Linear Search
    int i;
    for(i = 0; i <= (n - 1); i++) {
        if(a[i] == key) {
            cout << key << " Found At : " << i << " Index." << endl;
            break;
        }
    }
    if(i == n) cout << key <<" Is Not Found.\n";
    return 0;
}