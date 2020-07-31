#include<iostream>
#include<climits>
using namespace std;

// Mixtures - SPOJ
// Harry Potter has n mixtures in front of him, arranged in a row.
// Each mixture has one of 100 different colors (colors have numbers from 0 to 99).
// He wants to mix all these mixtures together. At each step, he is
// going to take two mixtures that stand next to each other and mix them together,
// and put the resulting mixture in their place.
// When mixing two mixtures of colors a and b, the resulting mixture
// will have the color (a+b) mod 100.
// Also, there will be some smoke in the process. The amount of smoke generated
// when mixing two mixtures of colors a and b is a*b.
// Find out what is the minimum amount of smoke that Harry can get
// when mixing all the mixtures together.

int arr[1000];
long long int dp[1000][1000];

long long int sum(int s, int e) {
    long long ans = 0;
    for(int i = s; i <= e; i++) {
        ans += arr[i];
        ans %= 100;
    }
    return ans;
}

long long int solveMixtures(int i, int j) {
    // Base Case
    if(i >= j) return 0;
    // If The Answer Is Already Calculated
    if(dp[i][j] != -1) return dp[i][j];
    // We Need To Break The Expression At Every Possible 'k'
    dp[i][j] = INT_MAX;
    for(int k = i; k <= j; k++) {
        dp[i][j] = min(dp[i][j],
         (solveMixtures(i, k) + solveMixtures((k + 1), j) + (sum(i, k) * sum((k + 1), j))));
    }
    return dp[i][j];
}

int main() {
    int n;
    while((scanf("%d", &n)) != EOF) {
        // Read N Integers
        for(int i = 0; i < n; i++) cin >> arr[i];
        // Init. DP With -1
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) dp[i][j] = -1;
        }
        cout << solveMixtures(0, n - 1) << endl;
    }
    return 0;
}