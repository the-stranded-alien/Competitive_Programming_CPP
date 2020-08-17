#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

class Graph {
private:
    int V;
    list<int> *l;
public:
    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }
    void addEdge(int x, int y, bool directed = false) {
        l[x].pb(y);
        if(!directed) l[y].pb(x);
    }
    bool cycle_helper(int node, bool *visited, int parent) {
        visited[node] = true;
        for(auto nbr : l[node]) {
            // Two Cases
            if(!visited[nbr]) {
                // Go And Recursively Visit The Neighbour
                bool cycle_found = cycle_helper(nbr, visited, node);
                if(cycle_found) return true;
            }
            // Neighbour Is Visited But Neighbour Should Not Be Equal To Parent
            else if(nbr != parent) return true;
        }
        return false;
    }
    bool contains_cycle() {
        // Check For Cycle In Undirected Graph
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++) visited[i] = false;
        return cycle_helper(0, visited, -1);
    }
};

int main() {
    FIO;
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    if(g.contains_cycle()) cout << "Yes, Undirected Graph Contains Cycle !\n";
    else cout << "Cycle Doesn't Exist !\n";
    return 0;
}