#include<iostream>
#include<algorithm>
using namespace std;

bool compare(string a, string b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main() {
    int n;
    cin >> n;
    cin.get();

    string s[100];

    cout << "Input Strings - " << endl;
    for(int i=0; i<n; i++){
        getline(cin, s[i]);
    }

    sort(s,s+n);
    cout << "Lexographically Sorted Strings - " << endl;
    for(int i=0; i<n; i++){
        cout << s[i] << endl;
    }

    sort(s,s+n,compare);
    cout << "Sorted Strings According To Length - " << endl;
    for(int i=0; i<n; i++){
        cout << s[i] << endl;
    }

}