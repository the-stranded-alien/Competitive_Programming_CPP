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

template<typename T>
class Graph {
private:
    map<T, list<T> > l;
public:
    void addEdge(T x, T y) {
        l[x].pb(y); // Directed Graph
    }
    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering) {
        // Recursive Function That Will Traverse The Graph
        visited[src] = true;
        // Go To All Neighbours Of The Current Node That Are Not Visited
        for(T nbr : l[src]) {
            if(!visited[nbr]) dfs_helper(nbr, visited, ordering);
        }
        // Push The Current Node At The Front
        ordering.push_front(src);
        return;
    }
    void dfs() {
        map<T, bool> visited;
        list<T> ordering;
        // Mark All Nodes As Not Visited In The Beginning
        for(auto p : l) {
            T node = p.F;
            visited[node] = false;
        }
        // Call Helper Function
        for(auto p : l) {
            T node = p.F;
            if(!visited[node]) dfs_helper(node, visited, ordering);
        }
        // Finally Print The Ordering List
        for(auto node : ordering) cout << node << " --> ";
        return;
    }
};

int main() {
    FIO;
    Graph<string> G;
    G.addEdge("Python", "Preprocessing");
    G.addEdge("Python", "PyTorch");
    G.addEdge("Python", "ML");
    G.addEdge("Preprocessing", "ML");
    G.addEdge("PyTorch", "DL");
    G.addEdge("ML", "DL");
    G.addEdge("DL", "FaceReco");
    G.addEdge("Dataset", "FaceReco");
    G.dfs();
    return 0;
}