#include<iostream>
#include<stack>
using namespace std;

// Stock Span Problem
void stockSpan(int prices[], int n, int span[]) {
    stack<int> stk; // Indices Of The Days
    stk.push(0);
    span[0] = 1;
    // Loop For Rest Of The Days
    for(int i = 1; i <= (n - 1); i++) {
        int currentPrice = prices[i];
        // Topmost Element That Is Higher Then Current Price
        while(!stk.empty() and prices[stk.top()] <= currentPrice) stk.pop();
        if(!stk.empty()) {
            int prev_highest = stk.top();
            span[i] = i - prev_highest;
        } else {
            span[i] = i + 1;
        }
        // Push This Element Into The Stack
        stk.push(i);
    }
    return;
}

int main() {
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(int);
    int span[10000] = {0};
    stockSpan(prices, n, span);
    for(int i = 0; i < n; i++) cout << span[i] << " ";
    return 0;
}