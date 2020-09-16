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
    float prob; cin >> prob;
    int people = 0;
    float total_days = 365;
    float days = 365;
    float pr = 1.0;
    if(prob == 1.0){
        cout << 366 << endl;
        return 0;
    }
    while(pr > 1 - prob) {
        pr *= (days--) / total_days; 
		people++;
    }
	cout << people << endl;
    return 0;
}