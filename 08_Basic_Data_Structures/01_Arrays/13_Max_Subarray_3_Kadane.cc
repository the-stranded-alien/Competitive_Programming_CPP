#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1000];
    int max_sum = 0;
    int cur_sum = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    // Kadane's Algorithm For Maximum Subarray Sum
    for(int i = 0; i < n; i++) {
        cur_sum = cur_sum + a[i];
        if(cur_sum < 0) cur_sum = 0;
        max_sum = max(cur_sum, max_sum); 
    }
    cout << "Max Is : "  << max_sum << endl;
    return 0;
}