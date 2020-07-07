#include<iostream>
using namespace std;

int merge(int *a, int s, int e) {
    int mid = (s + e) / 2;
    int i = s;
    int j = (mid + 1);
    int k = s;
    int temp[10000];
    int cnt = 0; // Cross Inversions
    while(i <= mid && j <= e) {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    // Fill The Array If Some Elements Are Left In One Of The Arrays
    while(i <= mid) temp[k++] = a[i++];
    while(j <= e) temp[k++] = a[j++];

    // Copy All Elements Back To Array
    for(int i = s; i <= e; i++) a[i] = temp[i];

    return cnt;
}

// Inversion Count
int inversion_count(int a[], int s, int e) {
    // Base Case
    if(s >= e) return 0;
    // Recursive Case - Like Merge Sort
    int mid = (s + e) / 2;
    int x = inversion_count(a, s, mid);
    int y = inversion_count(a, mid + 1, e);
    int z = merge(a, s, e); // Cross Inversions
    return (x + y + z);
}

int main() {
    int arr[] = {1, 5, 2, 6, 3, 0};
    int n = sizeof(arr) / sizeof(int);
    cout << inversion_count(arr, 0, n - 1) << endl;
    return 0;
}