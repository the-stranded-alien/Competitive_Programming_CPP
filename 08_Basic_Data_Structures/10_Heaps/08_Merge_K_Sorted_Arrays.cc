#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, pair<int, int> > node;
vector<int> mergeSortedArrays(vector<vector<int> > arr) {
    vector<int> result;
    priority_queue<node, vector<node>, greater<node> > pq; // Min Priority Queue
    // Insert The 0th Element Of Every Array In The 'pq'
    for(int i = 0; i < arr.size(); i++) pq.push({arr[i][0], {i, 0}}); // Curly Braces To Make Pair (C++11)
    // Remove The Elements One By One From The Min. Heap And Add To Result Vector.
    while(!pq.empty()) {
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first; // Row In Which Element Is Present
        int y = current.second.second; // Column In Which Element Is Present
        result.push_back(element);
        // Push The Next Element Of Current Array (x, y + 1) Into 'pq'
        if((y + 1) < arr[x].size()) pq.push({arr[x][y + 1], {x, (y + 1)}});
    }
    return result;
}

int main() {
    vector<vector<int> > arr{{2, 6, 12, 15}, {1, 3, 14, 20}, {3, 5, 8, 10}};
    vector<int> output = mergeSortedArrays(arr);
    for(auto x : output) cout << x << " ";
    cout << endl;
    return 0;
}