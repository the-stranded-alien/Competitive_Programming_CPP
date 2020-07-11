#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

// BAISED - Biased Standings (SPOJ)

// Usually, results of competitions are based on the scores of participants.
// However, we are planning a change for the next year of IPSC. During the
// registration each team will be able to enter a single positive integer :
// their preferred place in the ranklist. We would take all these preferences
// into account, and at the end of the competition we will simply announce a
// ranklist that would please all of you.
// But wait... How would that ranklist look like if it won't be possible to
// satisfy all the requests?
// Suppose that we already have a ranklist. For each team, compute the distance
// between their preferred place and their place in the ranklist. The sum of
// these distances will be called the badness of this ranklist.

int main() {
    long long int arr[100005] = {0};
    long long int t;
    cin >> t;
    while(t--) {
        memset(arr, 0, sizeof arr);
        string name;
        long long int n, rank;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> name >> rank;
            arr[rank]++;
        }
        // Greedy Approach - Assign The Team Nearest Rank Available
        long long int actual_rank = 1;
        long long int sum = 0;
        for(long long int i = 1; i <= n; i++) {
            while(arr[i]) {
                sum += abs(actual_rank - i);
                arr[i]--;
                actual_rank++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}