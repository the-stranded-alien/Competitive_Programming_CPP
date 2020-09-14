#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define pb push_back
#define F first
#define S second
#define P pair<int, int>
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;



int main() {
    FIO;
    int x; cin >> x;
    int y; cin >> y;
    
    // Naive Approach - O(N^2)
    // int maxVal = INT_MIN;
    // for(int i = x; i <= y; i++) {
    //     for(int j = x; j <= y; j++) {
    //         int cur = (i ^ j);
    //         if(cur > maxVal) maxVal = cur;
    //     }
    // }   

    // Optimal Approach - O(log N)
    int idx = 0;
    for(int i = 31; i >= 0; i--) {
        int x_i_bit = (x & (1 << i));
        int y_i_bit = (y & (1 << i));
        if(x_i_bit != y_i_bit) {
            idx = i;
            break;
        }
    }
    int maxVal = 0;
    for(int i = 0; i <= idx; i++) {
        maxVal = (maxVal | (1 << i));
    }
    cout << maxVal << endl;
    return 0;
}