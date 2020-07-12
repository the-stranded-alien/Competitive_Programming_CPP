#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1000];
    int max_sum = 0;
    int left = -1;
    int right = -1;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int cur_sum = 0;
            for(int k = i; k <= j; k++) {
                cur_sum += a[k];
            }
            if(cur_sum > max_sum) {
                max_sum = cur_sum;
                left = i;
                right = j;
            }
        }
    }
    cout << "Max Is : "  << max_sum << endl;
    // Printing The Subarray With Max Sum
    for(int x = left; x <= right; x++) cout << a[x] << " ";
    return 0;
}