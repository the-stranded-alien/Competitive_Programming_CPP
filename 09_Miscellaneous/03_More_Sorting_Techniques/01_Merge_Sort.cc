#include<iostream>
using namespace std;

void merge(int *a, int s, int e) {
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];

    while(i <= mid && j <= e) {
        if(a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= e) temp[k++] = a[j++];

    // Copy All Elements To Original Array
    for(int i = s; i <= e; i++) a[i] = temp[i];

    return;
}

void mergeSort(int a[], int s, int e) {
    // Base Case => 1 Or 0 Elements
    if(s >= e) return;
    // Recursive Case
    // Recursively Divide The Array -- (s, mid) & (mid + 1, e)
    int mid = (s + e) / 2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    // Merge The Two Parts
    merge(a, s, e);
    return;
}

int main() {
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}