#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

// Problem : Sort all the strings ( lexicographically ) but if a string is present
// completely as a prefix in another string, then string with longer length should come first.
// Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman
// - then sorted order should have - Batman, bat.

bool compare(string a, string b){
    int len1 = a.length();
    int len2 = b.length();
    if(len1 > len2){
        string sub = a.substr(0,len2);
        if(sub.compare(b)==0) return (a.length() > b.length());
    }
    if(len2 > len1){
        string sub = b.substr(0,len1);
        if(sub.compare(a)==0) return (a.length() > b.length());
    }
    return a < b;
}

int main() {
    int n;
    cin >> n;
    cin.get();

    vector<string> sv;
    for(int i=0; i<n; i++){
        string s;
        getline(cin, s);
        sv.push_back(s);
    }
    sort(sv.begin(), sv.end(), compare);
    for(auto s:sv){
        cout << s << endl;
    }

    return 0;
}