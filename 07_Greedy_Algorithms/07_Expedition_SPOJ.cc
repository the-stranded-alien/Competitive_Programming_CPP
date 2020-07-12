#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

// EXPEDI - Expedition (SPOJ)
// A group of cows grabbed a truck and ventured on an expedition deep into the jungle.
// Being rather poor drivers, the cows unfortunately managed to run over a rock and
// puncture the truck's fuel tank. The truck now leaks one unit of fuel every unit of
// distance it travels. To repair the truck, the cows need to drive to the nearest town
// (no more than 1,000,000 units distant) down a long, winding road. On this road, between
// the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops
// where the cows can stop to acquire additional fuel (1..100 units at each stop).
// The jungle is a dangerous place for humans and is especially dangerous for cows.
// Therefore, the cows want to make the minimum possible number of stops for fuel on the way
// to the town. Fortunately, the capacity of the fuel tank on their truck is so large that
// there is effectively no limit to the amount of fuel it can hold. The truck is currently L
// units away from the town and has P units of fuel (1 <= P <= 1,000,000).
// Determine the minimum number of stops needed to reach the town, or if the cows cannot
// reach the town at all.

bool compare(pair<int, int> p1, pair<int, int> p2) {
    // Distance w.r.t To Town, i.e. Reverse Sorting For The Town (So Greater Than Sign)
    return p1.first > p2.first;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int flag = 0;
        int ans = 0;
        vector<pair<int, int> > v;
        priority_queue<int> pq;
        int n, d, f;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> d >> f;
            v.push_back(make_pair(d, f));
        }
        // Sort The Fuel Stations According To Their Location
        sort(v.begin(), v.end(), compare);
        int D, F; // F -> Fuel In Truck
        cin >> D >> F;
        // Update The Distance Of The Fuel Station From The Truck
        for(int i = 0; i < n; i++) v[i].first = D - v[i].first;
        // 'prev' Denotes The Previous Fuel Station We Have Visited
        int prev = 0;
        // Current Fuel Station
        int x = 0;
        while(x < n) {
            // If We Have Enough Fuel To Go The Next Fuel Station
            if(F >= (v[x].first - prev)) {
                F = F - (v[x].first - prev);
                pq.push(v[x].second);
                prev = v[x].first;
            } 
            else {
                // Check If You Have Some Fuelling Station Visited In The Priority Queue
                if(pq.empty()) {
                    flag = 1;
                    break;
                }
                // Otherwise Refuel The Truck With Fuel Station With Higher Capacity
                F += pq.top();
                // Remove The Used Fuel Station From Priority Queue
                pq.pop();
                ans = ans + 1;
                continue; // Checks Again If Fuel Is Enough To Go The Next Fuel Station
            }
            x++; // Increment Fuel Station Visited
        }    
        // Actually Travelled Through 'n' Fuel Stations
        // What Is Left You Have To Reach The Town From The Last Fuel Station
        if(flag == 1) {
            cout << -1 << endl;
            continue;
        }
        // Otherwise
        D = D - v[n - 1].first;
        if(F >= D) {
            cout << ans << endl;
            continue;
        }
        // Otherwise
        while(F < D) {
            if(pq.empty()) {
                flag = 1;
                break;
            }
            F += pq.top();
            pq.pop();
            ans += 1;
        }
        if(flag == 1) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}