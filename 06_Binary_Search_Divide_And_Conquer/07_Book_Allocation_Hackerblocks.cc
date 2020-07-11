#include<iostream>
#include<climits>
using namespace std;

// You are given number of pages in n different books and m students. The books are arranged
// in ascending order of number of pages. Every student is assigned to read some consecutive
// books. The task is to assign books in such a way that the maximum number of pages assigned
// to a student is minimum. 

bool isPossible(int arr[], int n, int m, int curr_min) {
    int studentUsed = 1;
    int pages_reading = 0;
    for(int i = 0; i < n; i++) {
        if(pages_reading + arr[i] > curr_min) {
            studentUsed++;
            pages_reading = arr[i];
            if(studentUsed > m) return false;
        } else {
            pages_reading += arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    if(n < m) return -1;
    // Count The Number Of Pages
    
    int s = arr[n - 1];
    int e = sum;   
    int ans = INT_MAX;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(isPossible(arr, n, m, mid)) {
            ans = min(ans, mid);
            e = mid - 1;
        } else { // Not Possible To Divide At 'X' Pages, Increase No. Of Pages
            s = mid + 1;
        }
    } 
    return ans;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        int arr[1000];
        for(int j = 0; j < n; j++) cin >> arr[j];
        cout << findPages(arr, n, m) << endl;
    }
    return 0;
}