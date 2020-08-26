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

// DSU Data Structure
// Path Compression + Union By Rank Optimization
class DSU {
    int *parent;
    int *rank;
public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        // Parent = -1, Rank = 1
        for(int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    // Find Function
    int find(int i) {
        // Base Case
        if(parent[i] == -1) return i;
        // Otherwise
        return (parent[i] = find(parent[i]));
    }
    // Unite (Union) Function
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if(s1 != s2) {
            // Union By Rank
            if(rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    vector<vector<int> > edgeList;
    int V;
public:
    Graph(int V) {
        this->V = V;
    }
    void addEdge(int x, int y, int w) {
        edgeList.pb({w, x, y});
    }
    int kruskal_mst() {
        // 1. Sort All The Edges Based Upon Weight
        sort(edgeList.begin(), edgeList.end());
        // Init a DSU
        DSU s(V);
        int ans = 0;
        for(auto edge : edgeList) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            // Take That Edge In MST If It Doesn't Form A Cycle
            if(s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
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
    cout << g.kruskal_mst() << endl;
    return 0;
}