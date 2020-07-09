#include<iostream>
using namespace std;

int profit(int N, int C, int *weights, int *prices) {
    // Base Case
    if(N == 0 || C == 0) return 0;
    // Recursive Case
    int ans = 0;
    int include = 0;
    int exclude = 0;

    // Include The Current Item
    if(weights[N - 1] <= C) include = prices[N - 1] + profit(N - 1, C - weights[N - 1], weights, prices);
    // Exclude The Current Item
    exclude = profit(N - 1, C, weights, prices);

    ans = max(include, exclude);
    return ans;
}


int main() {
    int weights[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100};
    int N = 4;
    int C = 7;
    cout << profit(N , C, weights, prices);
    return 0;
}