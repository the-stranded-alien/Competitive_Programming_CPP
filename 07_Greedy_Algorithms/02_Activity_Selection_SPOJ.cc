#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// BUSYMAN - I AM VERY BUSY (SPOJ)
// You are actually very busy man. You have a big schedule of activities.
// Your aim is to do as much as activities as possible.

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return (p1.second < p2.second);
}

int main() {
    int t;
    cin >> t;
    int n;
    int s;
    int e;
    vector<pair<int, int> > v;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> s >> e;
            v.push_back(make_pair(s, e));
        }
        // Activity Selection Algorithm
        sort(v.begin(), v.end(), compare); // Sort
        // Start Picking Activities (Always Pick 1st Activity)
        int res = 1;
        int fin = v[0].second;
        for(int i = 1; i < n; i++) {
            if(v[i].first >= fin) {
                fin = v[i].second;
                res++;
            }
        }
        cout << res << endl;
        v.clear();
    }
    return 0;
}