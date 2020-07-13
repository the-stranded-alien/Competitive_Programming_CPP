#include<iostream>
#include<cstring>
using namespace std;

// Remove Consecutive Duplicate Characters From A String
void removeConsecutiveDuplicate(char a[]) {
    int len = strlen(a);
    if(len == 0 or len == 1) return;
    int prev = 0;
    for(int current = 1; current < len; current++) {
        if(a[current] != a[prev]) {
            prev++;
            a[prev] = a[current];
        }
    }
    a[prev + 1] = '\0';
    return;
}

int main() {
    char a[1000];
    cin.getline(a, 1000);
    removeConsecutiveDuplicate(a);
    cout << a << endl;
    return 0;
}