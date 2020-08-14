#include<iostream>
#include<cstring>
#include<set>
#include<map>
using namespace std;
long long int a[300000];
long long int BIT[300000] = {0};

void update(int i, int val, int N) {
    while(i <= N) {
        BIT[i] += val;
        i += (i & (-i));
    }
}

int query(int i) {
    long long int ans = 0;
    while(i > 0) {
        ans += BIT[i];
        i -= (i & (-i));
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(BIT, 0, sizeof(BIT));
        cin.ignore();
        int n;
        cin >> n;
        // Coordinate Compression
        set<int> s;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        map<int, int> m;
        int x = 1;
        for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
            m[(*it)] = x;
            x++; 
        }
        for(int i = 1; i <= n; i++) {
            a[i] = m[a[i]];
        }
        // Inversion Counts
        long long int ans = 0;
        for(int i = n; i >= 1; i--) {
            ans += query(a[i] - 1);
            update(a[i], 1, n);
        }
        cout << ans << endl;
    }
    return 0;
}