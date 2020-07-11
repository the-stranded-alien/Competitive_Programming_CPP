#include<iostream>
using namespace std;

// First And Last Occurence Of A Key In A Sorted Array

int first_occurence(int a[], int n, int key) {
    int s = 0;
    int e = n - 1;
    int ans = -1;
    // Update In A Direction That Answer Value Gets Lower & Lower
    while(s <= e) {
        int mid = (s + e) / 2;
        if(a[mid] == key) {
            ans = mid;
            // Do Not Stop But Explore The Left Part Of The Array
            e = mid - 1;
        }
        else if(a[mid] > key) { e = mid - 1; }
        else { s = mid + 1; }
    }
    return ans;
}

int last_occurence(int a[], int n, int key) {
    int s = 0;
    int e = n - 1;
    int ans = -1;
    // Update In A Direction That Answer Value Gets Higher & Higher
    while(s <= e) {
        int mid = (s + e) / 2;
        if(a[mid] == key) {
            ans = mid;
            // Do Not Stop But Explore The Right Part Of The Array
            s = mid + 1;
        }
        else if(a[mid] > key) { e = mid - 1; }
        else { s = mid + 1; }
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10, 12, 15, 20};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    cout << first_occurence(arr, n, key) << endl;
    cout << last_occurence(arr, n, key) << endl; 
    return 0;
}