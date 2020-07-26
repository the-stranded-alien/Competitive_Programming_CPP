#include<iostream>
#include<queue>
using namespace std;

// Problem Statement -> Given 'N' Ropes of Different Sizes, We Have To Join The Ropes
// Together. The Cost of Joining 2 Ropes of Different Sizes A & B is (A + B). Find The
// Minimum Cost to Join All The Ropes Together.

int join_ropes(int ropes[], int n) {
    int cost = 0;
    priority_queue<int, vector<int>, greater<int> > pq(ropes, ropes + n);
    while(pq.size() > 1) {
        int rope1 = pq.top();
        pq.pop();
        int rope2 = pq.top();
        pq.pop();
        int new_rope = (rope1 + rope2);
        cost += new_rope;
        pq.push(new_rope);
    }
    return cost;
}

int main() {
    int ropes[] = {4, 3, 2, 6};
    int n = 4;
    cout << join_ropes(ropes, n) << endl;
    return 0;
}