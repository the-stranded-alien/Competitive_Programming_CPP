#include<iostream>
using namespace std;

void dnf_sort(int a[], int n) {
    // Sort Arrays of 0s, 1s, 2s.
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while(mid <= high) {
        if(a[mid] == 0) swap(a[mid++], a[low++]);
        if(a[mid] == 1) mid++;
        if(a[mid] == 2) swap(a[mid], a[high--]);
    }
    return;
}

int main() {
    int a[] = {2, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 2, 0};
    int n = sizeof(a) / sizeof(int);
    dnf_sort(a, n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}