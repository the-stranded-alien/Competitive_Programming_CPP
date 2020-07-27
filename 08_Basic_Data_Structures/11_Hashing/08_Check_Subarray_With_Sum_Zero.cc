#include<iostream>
#include<unordered_set>
using namespace std;

bool checkSum(int arr[], int n) {
    unordered_set<int> s;
    int pre = 0;
    for(int i = 0; i < n; i++) {
        pre += arr[i];
        // Check If The Sum Was Already Present In The Set
        if(pre == 0 or s.find(pre) != s.end()) {
            return true;
        }
        s.insert(pre);
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(checkSum(arr, n)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}