#include<iostream>
#include<vector>
using namespace std;

// Prime Factorization Using Optimized Trial Divisions. [(O(sqrt(N))) - Time]

void printFactors(int n) {
    
    vector<pair<int, int> > factors;
    int cnt;

    for(int i = 2; (i * i) <= n; i++) {
        if(n % i == 0) {
            // Keep On Dividing It By 'i' Till It Is Divisible
            cnt = 0;
            while(n % i == 0) {
                cnt++;
                n = (n / i);
            }
            factors.push_back(make_pair(i, cnt));
        }
    }
    if(n != 1) {
        // Whatever Is Left Is A Prime Factor In Itself
        factors.push_back(make_pair(n, 1));
    }
    // Print The Factors
    for(auto p : factors) cout << p.first << "^" << p.second << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    printFactors(n);
    return 0;
}