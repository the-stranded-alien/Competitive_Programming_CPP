#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Given Locations Of Some Cabs {(x1, y1), (x2, y2), (x3, y3), ....... }.
// Tell There Location In Sorted Order From The Origin.

bool compare(pair<int, int> cab1, pair<int, int> cab2) {
    int d1 = ((cab1.first * cab1.first) + (cab1.second * cab1.second));
    int d2 = ((cab2.first * cab2.first) + (cab2.second * cab2.second)); 
    if(d1 == d2) return (cab1.first < cab2.first); // If Two Cabs Have Same Distance Compare 'x' Cordinate
    return d1 < d2;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), compare);
    for(auto p : v) cout << "Cab : " << p.first << ", " << p.second << endl;
    return 0;
}