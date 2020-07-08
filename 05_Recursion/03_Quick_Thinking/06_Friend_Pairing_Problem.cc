#include<iostream>
using namespace std;

int pairFriends(int n) {
    // Base Cases
    if(n == 0) return 1;
    if(n == 1 || n == 2) return n;
    return (pairFriends(n - 1) + ((n - 1) * pairFriends(n - 2)));

}

int main() {
    int n;
    cin >> n;
    cout << pairFriends(n) << endl;
    return 0;
}