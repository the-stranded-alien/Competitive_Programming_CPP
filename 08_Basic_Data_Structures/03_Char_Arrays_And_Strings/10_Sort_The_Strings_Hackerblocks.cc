#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

// Sort The Strings (Hackerblocks)
// Given a list of 'n' strings S0,S1,S2,……,Sn-1, each consisting of digits and spaces,
// the number of spaces is the same for each entry, the goal is to implement a variation
// of a sort command. None of the strings contains consecutive spaces. Also, no string starts
// with a space nor ends with it. Spaces are used to divide string into columns, which can be
// used as keys in comparisons. The program has to support the required parameters:
// key: integer denoting the column used as a key in comparisons.
// The left-most column is denoted by 1.
// reversed: boolean variable indicating whether to reverse the result of comparisons.
// comparison-type: either lexicographic or numeric. Lexicographic means that we use
// Lexicographical order where for example (122 < 13) . Numeric means that we compare the
// strings by their numerical values, so (13 < 122) . If the comparison type is 'numeric' and
// numeric values of keys of Si and Sj are equal for i < j , then Si is considered strictly
// smaller than Sj because it comes first.

string extractStringAtKey(string str, int key) {
    // Strtok() -> char* strtok(char *s, delim)
    // So We Need To Convert String Into Char *
    char *s = strtok((char *) str.c_str(), " ");
    while(key > 1) {
        s = strtok(NULL, " ");
        key--;
    }
    return (string) s;
}

int convertToInt(string str) {
    int ans = 0;
    int p = 1;
    for(int i = str.length() - 1; i >= 0; i--) {
        ans += ((str[i] - '0') * p);
        p = p * 10;
    }
    return ans;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
    string key1 = s1.second;
    string key2 = s2.second;
    return (convertToInt(key1) < convertToInt(key2));
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
    string key1 = s1.second;
    string key2 = s2.second;
    return (key1 < key2);
}

int main() {
    int n;
    cin >> n;
    cin.get();
    string a[100];
    for(int i = 0; i < n; i++) getline(cin, a[i]);
    int key;
    string reversal, ordering;
    cin >> key;
    cin >> reversal;
    cin >> ordering;
    // Extract And Store All Keys As Pairs With Their Strings
    pair<string, string> strPair[100];
    for(int i = 0; i < n; i++) {
        strPair[i].first = a[i];
        strPair[i].second = extractStringAtKey(a[i], key);
    }
    // Sort
    if(ordering == "numeric") {
        sort(strPair, strPair + n, numericCompare);
    }
    else {
        sort(strPair, strPair + n, lexicoCompare);
    }
    // Check For Reversal
    if(reversal == "true") {
        for(int i = 0; i < (n / 2); i++) {
            swap(strPair[i], strPair[n - i - 1]);
        }
    }
    // Print Output
    for(int i = 0; i < n; i++) {
        cout << strPair[i].first << endl;
    }

    return 0;
}