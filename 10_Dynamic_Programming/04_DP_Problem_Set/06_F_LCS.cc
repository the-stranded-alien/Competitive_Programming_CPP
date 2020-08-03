#include<iostream>
#include<cstring>
using namespace std;

#define MAX 3000

int dp[MAX + 1][MAX + 1];

string getLCS(string &s, string &t, int len) {
    string LCS;
    int i = 0, j = 0;
    while(len > 0) {
        if(s[i] == t[j]) {
            LCS.push_back(s[i]);
            i++;
            j++;
            len--;
        }
        else {
            if(dp[i][j + 1] > dp[i + 1][j]) j++;
            else i++;
        }
    }
    return LCS;
}

// Top Down Approach
int lengthLCS(string &s, string &t, int i, int j) {
    if((i >= s.length()) || (j >= t.length())) return 0; // Base Case
    if(dp[i][j] != -1) return dp[i][j]; // Look Up
    // Recursive Case
    if(s[i] == t[j]) return (dp[i][j] = (1 + lengthLCS(s, t, (i + 1), (j + 1))));
    else return (dp[i][j] = max(lengthLCS(s, t, i, (j + 1)), lengthLCS(s, t, (i + 1), j)));
}

string LCS(string s, string t) {
    memset(dp, -1, sizeof(dp));
    int len = lengthLCS(s, t, 0, 0);
    return getLCS(s, t, len);
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << LCS(s, t) << endl;
    return 0;
}