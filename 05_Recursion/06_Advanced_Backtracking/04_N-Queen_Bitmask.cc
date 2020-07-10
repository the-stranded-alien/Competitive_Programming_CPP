#include<iostream>
using namespace std;

int n;
int ans = 0;
int DONE;

void solve(int rowMask, int leftDia, int rightDia) {
    // Base Case
    if(rowMask == DONE) { ans++; return; }
    // Recursive Case
    int safeMask = DONE & (~(rowMask | leftDia | rightDia));
    while(safeMask) {
        int pos = safeMask & (-safeMask);
        safeMask = safeMask - pos;
        solve((rowMask | pos), ((leftDia | pos) << 1), ((rightDia | pos) >> 1));
    }
    return;
}

int main() {
    cin >> n;
    DONE = ((1 << n) - 1);
    solve(0, 0, 0);
    cout << ans << endl;
    return 0;
}