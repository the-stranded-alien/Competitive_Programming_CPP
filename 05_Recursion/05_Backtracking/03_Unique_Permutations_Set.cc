#include<iostream>
#include<set>
#include<string>
using namespace std;

// Unique Permutations & Lexicographically Sorted.
// Using SET Data Structure.

void permute(char *in, int i, set<string> &s) {
    // Base Case
    if(in[i] == '\0') {
        string t(in);
        s.insert(t);
        return;
    }
    // Recursive Case
    for(int j = i; in[j] != '\0'; j++) {
        swap(in[i], in[j]);
        permute(in, i + 1, s);
        // Backtracking
        swap(in[i], in[j]);
    }
    return;
}

int main() {
    char in[100];
    cin >> in;
    set<string> s;
    permute(in, 0, s);
    // Loop Over The Set
    for(auto str : s) cout << str << " ";
    return 0;
}