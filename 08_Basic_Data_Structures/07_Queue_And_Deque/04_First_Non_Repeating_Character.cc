#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<char> q;
    int freq[27] = {0};
    // Running Stream Of Input Until A '.' 
    char ch;
    cin >> ch;
    while(ch != '.') {
        // Insert In The Queue 'q' And Frequency Table 'freq'.
        q.push(ch);
        freq[ch - 'a']++;
        // Query
        while(!q.empty()) {
            int idx = q.front() - 'a';
            if(freq[idx] > 1) {
                q.pop();
            }
            else {
                cout << q.front() << endl;
                break;
            }
        }
        // If Queue Is Empty
        if(q.empty()) cout << "-1" << endl;
        cin >> ch;
    }
    return 0;
}