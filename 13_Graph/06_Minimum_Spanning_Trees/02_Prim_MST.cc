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

class Graph { // Adjacency List Representation
    int V;
    vector<pair<int, int> > *l; // X -> (Y, Weights)
public:
    Graph(int n) {
        this->V = n;
        l = new vector<pair<int, int> >[n];
    }
    void addEdge(int x, int y, int w) {
        l[x].pb({y, w});
        l[y].pb({x, w});
    }
    int prim_mst() {
        // Min Priority Queue / Heap
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q; // Stores (w, y)
        // Visited Array That Denotes Whether A Node Has Been Included In MST Or Not.
        bool *vis = new bool[V]{0};
        // Begin From Source Node
        Q.push({0, 0}); // (Weight, Node)
        int ans = 0;
        while(!Q.empty()) {
            // Pick Out The Edge With Min Weight
            auto best = Q.top();
            Q.pop();
            int to = best.S;
            int weight = best.F;
            if(vis[to]) continue; // Discard The Edge, And Continue
            // Otherwise Take The Current Edge
            ans += weight;
            vis[to] = 1;
            // Add The New Edges In The Queue
            for(auto x : l[to]) {
                if(vis[x.F] == 0) Q.push({x.S, x.F});
            }
        }
        return ans;
    }
};

int main() {
    FIO;
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge((x - 1), (y - 1), w); // 0 Based Indexing 
    }
    cout << g.prim_mst() << endl;
    return 0;
}