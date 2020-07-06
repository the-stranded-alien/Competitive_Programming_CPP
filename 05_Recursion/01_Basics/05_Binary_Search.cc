#include<iostream>
using namespace std;

int binary_search(int a[], int start, int end, int key) {
    if(end >= start) {
        int mid = ((end + start) / 2);
        if(a[mid] == key) return mid;
        if(a[mid] > key) return binary_search(a, start, mid - 1, key);
        return binary_search(a, mid + 1, end, key);
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = (sizeof(arr) / sizeof(int));
    int key = 5;
    cout << binary_search(arr, 0, n - 1, key) << endl;
    return 0;
}