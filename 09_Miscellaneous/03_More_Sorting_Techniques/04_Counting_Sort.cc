#include<iostream>
using namespace std;

void counting_sort(int *arr, int n) {
    // Largest Element In The Array
    int largest = -1;
    for(int i = 0; i < n; i++) largest = max(largest, arr[i]);
    // Frequency Array
    int *freq = new int[largest + 1]{0};
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    // Put Elements Back Into The Array By Reading Frequency Array
    int j = 0;
    for(int i = 0; i <= largest; i++) {
        while(freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }
    return;
}

int main() {
    int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
    int n = sizeof(arr) / sizeof(int);
    counting_sort(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}