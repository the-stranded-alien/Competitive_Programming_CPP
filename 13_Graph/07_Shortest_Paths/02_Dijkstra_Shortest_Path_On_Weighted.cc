#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define pb push_back
#define F first
#define S second
#define P pair<int, int>
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Dijkstra's Algorithm For Single Source Shortest Path
// Used For Weighted Graphs

template<typename T>
class Graph {
    unordered_map<T, list<pair<T, int> > > m;
public:
    void addEdge(T u, T v, int dist, bool bidir = true) {
        m[u].pb(make_pair(v, dist));
        if(bidir) m[v].pb(make_pair(u, dist));
    }
    void printAdj() {
        // Print The Adjacency List
        // Iterate Over All The Key-Value Pairs In The Map
        for(auto j : m) {
            cout << j.F << " --> ";
            // Iterate Over The List Of Cities
            for(auto l : j.S) cout << "(" << l.F << ", " << l.S << "), ";
            cout << endl;
        }
    }
    void dijkstraSSSP(T src) {
        unordered_map<T, int> dist;
        // Set All Distances To Infinity.
        for(auto j : m) dist[j.F] = INT_MAX;
        // Make A Set To Find Out A Node With The Minimum Distance.
        set<pair<int, T> > s; // Sorting According To First Parameter Of Pair.
        dist[src] = 0;
        s.insert(make_pair(0, src));
        while(!s.empty()) {
            // Find The Pair At The Front.
            auto p = *(s.begin());
            T node = p.S;
            int nodeDist = p.F;
            s.erase(s.begin());
            // Iterate Over The Neighbours / Children Of The Current Node.
            for(auto childPair : m[node]) {
                if((nodeDist + childPair.S) < dist[childPair.F]) {
                    // In The Set Updation Of A Particular Node Is Not Possible
                    // So, We Have To Remove The Old Pair, And Insert The New Pair
                    // To Stimulate Updation.
                    T dest = childPair.F;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f != s.end()) s.erase(f); // Delete Old Pair
                    // Insert New Pair
                    dist[dest] = nodeDist + childPair.S;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        // Lets Print Distance To All Other Nodes From Src
        for(auto d : dist) {
            cout << d.F << " Is Located At Distance Of " << d.S << " From The Source\n";
        }
    }
};

int main() {
    FIO;
    // Graph<int> g;
    // g.addEdge(1, 2, 1);
    // g.addEdge(1, 3, 4);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 2);
    // g.addEdge(1, 4, 7);
    // g.printAdj();
    // g.dijkstraSSSP(1);
    Graph<string> India;
    India.addEdge("Amritsar", "Delhi", 1);
    India.addEdge("Amritsar", "Jaipur", 4);
    India.addEdge("Jaipur", "Delhi", 2);
    India.addEdge("Jaipur", "Mumbai", 8);
    India.addEdge("Bhopal", "Agra", 2);
    India.addEdge("Mumbai", "Bhopal", 3);
    India.addEdge("Agra", "Delhi", 1);
    // India.printAdj();
    India.dijkstraSSSP("Amritsar");
    return 0;
}