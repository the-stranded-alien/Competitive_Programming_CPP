#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

// Alyona And Strings (Codeforces 682-D)
// After returned from forest, Alyona started reading a book. She noticed strings s and t,
// lengths of which are n and m respectively. As usual, reading bored Alyona and she decided
// to pay her attention to strings s and t, which she considered very similar.
// Alyona has her favourite positive integer k and because she is too small, k does not
// exceed 10. The girl wants now to choose k disjoint non-empty substrings of string s such
// that these strings appear as disjoint substrings of string t and in the same order as
// they do in string s. She is also interested in that their length is maximum possible
// among all variants. Formally, Alyona wants to find a sequence of k non-empty strings
// p 1, p 2, p 3, ..., p k satisfying following conditions:
// s can be represented as concatenation a 1 p 1 a 2 p 2... a k p k a k + 1, where
// a 1, a 2, ..., a k + 1 is a sequence of arbitrary strings (some of them may be possibly empty);
// t can be represented as concatenation b 1 p 1 b 2 p 2... b k p k b k + 1, where
// b 1, b 2, ..., b k + 1 is a sequence of arbitrary strings (some of them may be possibly empty);
// sum of the lengths of strings in sequence is maximum possible.
// Please help Alyona solve this complicated problem and find at least the sum of the
// lengths of the strings in a desired sequence. A substring of a string is a
// subsequence of consecutive characters of the string.

int n, m, k;
string s, t;
int dp[1005][1005][12][2];

int solve(int is, int it, int rem, int cont) {
    if(is == n || it == m) return((rem == 0) ? 0 : INT_MIN);
    if(rem == 0) return 0;
    if(dp[is][it][rem][cont] != -1) return dp[is][it][rem][cont];
    int ret = INT_MIN;
    ret = max(ret, solve((is + 1), it, (rem - cont), 0));
    ret = max(ret, solve(is, (it + 1), (rem - cont), 0));
    if(s[is] == t[it]) {
        ret = max(ret, (1 + solve((is + 1), (it + 1), rem, 1)));
        ret = max(ret, (1 + solve((is + 1), (it + 1), (rem - 1), 0)));
    }
    return (dp[is][it][rem][cont] = ret);
}

int main() {
    cin >> n >> m >> k;
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, k, 0);
    return 0;
}