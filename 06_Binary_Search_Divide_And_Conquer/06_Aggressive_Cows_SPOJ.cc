#include<iostream>
#include<algorithm>
using namespace std;

// Aggressive Cows (AGGRCOW) - SPOJ
// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
// The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other
// once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the
// cows to the stalls, such that the minimum distance between any two of them is as large
// as possible. What is the largest minimum distance?

bool canPlaceCows(int stalls[], int n, int c, int min_sep) {
    int last_cow = stalls[0];
    // Place The First Cow In The First Stall
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(stalls[i] - last_cow >= min_sep) {
            last_cow = stalls[i];
            cnt++;
            if(cnt == c) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        // Binary Search
        int n;
        int cows;
        cin >> n >> cows;
        int stalls[100000];
        for(int i = 0; i < n; i++) cin >> stalls[i];
        sort(stalls, stalls + n);
        int s = 0;
        int e = stalls[n - 1] - stalls[0];
        int ans = 0;
        while(s <= e) {
            int mid = (s + e) / 2;
            bool canPlace = canPlaceCows(stalls, n, cows, mid);
            if(canPlace) {
                ans = mid;
                s = mid + 1;
            } else e = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}