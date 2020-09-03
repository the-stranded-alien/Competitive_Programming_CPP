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

vector<string> op;

void generateStrings(char *in, char *out, int i, int j) {
    // Base Case
    if(in[i] == '\0') {
        out[j] = '\0';
        // cout << out << " ";
        op.pb(out);
        return;
    }
    // Recursive Case
    // Case 1 : One Digit At A Time
    if(in[i] == '0') {
        generateStrings(in, out, (i + 1), j);
        return;
    }
    int digit = in[i] - '0';
    char ch = digit + 'a' - 1;
    out[j] = ch;
    generateStrings(in, out, (i + 1), (j + 1));
    // Case 2 : Two Digits At A Time
    if(in[i + 1] != '\0') {
        int secondDigit = in[i + 1] - '0';
        int num = (digit * 10) + secondDigit;
        if(num <= 26) {
            ch = num + 'a' - 1;
            out[j] = ch;
            generateStrings(in, out, (i + 2), (j + 1));
        }
    }
    return;
}

int main() {
    FIO;
    char inp[1000];
    cin >> inp;
    char out[1000];
    generateStrings(inp, out, 0, 0);
    cout << "[";
    int len = op.size();
    for(auto ele : op) {
        cout << ele;
        if(len > 1) {
            cout << ", ";
            len--;
        }
    }
    cout << "]";
    return 0;
}