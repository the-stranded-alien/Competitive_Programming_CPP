#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

// Weighted Graph (Adjacency List)
class Graph {
    int V;
    list<pair<int, int> > *l;
public:
    Graph(int v) {
        V = v;
        l = new list<pair<int, int> >[V];
    }
    void addEdge(int u, int v, int cost) {
        l[u].push_back(make_pair(v, cost));
        l[v].push_back(make_pair(u, cost));
    }

    int dfsHelper(int node, bool *visited, int *count, int &ans) {
        // Mark Node As Visited
        visited[node] = true;
        count[node] = 1;
        for(auto nbr_pair : l[node]) {
            int nbr = nbr_pair.first;
            int wt = nbr_pair.second;
            if(!visited[nbr]) {
                count[node] += dfsHelper(nbr, visited, count, ans);
                int nx = count[nbr];
                int ny = V - nx;
                ans += (2 * min(nx, ny) * wt);
            }
        }
        // Just Before Leaving The Node, Return Count To Parent
        return count[node];
    }

    int dfs() {
        bool *visited = new bool[V]{0};
        int *count = new int[V]{0};
        // for(int i = 0; i < V; i++) { visited[i] = false; count[i] = 0; }
        int ans = 0;
        dfsHelper(0, visited, count, ans);
        return ans;
    }
};

int main() {
    FIO;
    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 2);
    cout << g.dfs() << endl;
    return 0;
}