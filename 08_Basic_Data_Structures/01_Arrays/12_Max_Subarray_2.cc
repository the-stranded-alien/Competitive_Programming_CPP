#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1000];
    int csum[1000] = {0};
    int max_sum = 0;
    int left = -1;
    int right = -1;
    cin >> a[0];
    csum[0] = a[0];
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        csum[i] = csum[i - 1] + a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int cur_sum = csum[j] - csum[i - 1];
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