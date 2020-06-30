#include<iostream>
#include<queue>
using namespace std;

// Dean of MAIT is going to visit Hostels of MAIT. As you know that he is a very
// busy person so he decided to visit only first "K" nearest Hostels.
// Hostels are situated in 2D plane. You are given the coordinates of
// hostels and you have to answer the Rocket distance of Kth nearest
// hostel from origin ( Dean's place ) .

// First line of input contains Q Total no. of queries and K There are two types of queries:
// first type : 1 x y For query of 1st type, you came to know about the co-ordinates ( x , y )
// of newly constructed hostel. second type : 2 For query of 2nd type, you have to output
// the Rocket distance of Kth nearest hostel till now.
// The Dean will always stay at his place ( origin ). It is gauranted that there will be
// atleast k queries of type 1 before first query of type 2. Rocket distance between
// two points ( x2 , y2 ) and ( x1 , y1 ) is defined as (x2 - x1)^2 + (y2 - y1)^2

int main() {
    int Q;
    int K;
    cin >> Q >> K;
    priority_queue<long long int> pq_max;
    for(int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if(type == 1){
            long long int x;
            long long int y;
            cin >> x >> y;
            // Using Max Priority Queue To Store Distances
            long long int rocket_dist = (x * x) + (y * y);
            pq_max.push(rocket_dist);
            // Remove The Top Element If Size > K.
            if(pq_max.size() > K){
                pq_max.pop();
            }
        } 
        else if(type == 2) {
            // Show The Topmost Element Which Is Kth Element
            cout << pq_max.top() << endl;
        } else continue;
    }
    return 0;
}