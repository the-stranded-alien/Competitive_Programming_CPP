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

// Single Source Shortest Path (SSSP) Using BFS [For Unweighted Graphs]

template<typename T>
class Graph {
    map<T, list<T> > l;
public:
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void sssp(T src) {
        map<T, int> dist;
        queue<T> q;

        // All Other Nodes Will Have INT_MAX Distance In The Beginning Except Source
        for(auto node_pair : l) {
            T node = node_pair.F;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;

        while(!q.empty()) {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for(int nbr : l[node]) {
                if(dist[nbr] == INT_MAX) {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        // Print The Distance To Every Node
        for(auto node_pair : l) {
            T node = node_pair.F;
            int d = dist[node];
            cout << "\nNode : " << node << " Distance From Source : " << d;
        }
    }
};

int main() {
    FIO;
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.sssp(0);
    return 0;
}