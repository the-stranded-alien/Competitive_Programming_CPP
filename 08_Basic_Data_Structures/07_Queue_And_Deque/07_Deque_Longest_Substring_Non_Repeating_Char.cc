#include<iostream>
#include<cstring>
using namespace std;

// Sliding Window / Deque

int main() {
    char a[] = "abccde";
    int n = strlen(a);
    int current_len = 1;
    int max_len = 1;
    int visited[256] = {-1}; // Each Char Is Not Visited Initially
    visited[a[0]] = 0;
    for(int i = 1; i < n; i++) {
        int last_occ = visited[a[i]];
        // Expansion
        if(last_occ == -1 || (i - current_len) > last_occ) current_len += 1;
        else { // Expansion + Contraction
            if(current_len > max_len) max_len = current_len; 
            current_len = i - last_occ;
        }
        visited[a[i]] = i;
    }
    if(current_len > max_len) max_len = current_len; 
    cout << max_len << endl;
    return 0;
}