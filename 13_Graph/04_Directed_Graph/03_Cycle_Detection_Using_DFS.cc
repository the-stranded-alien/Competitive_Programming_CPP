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

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y, bool directed = true) {
        l[x].pb(y);
        if(!directed) l[y].pb(x);
    }
    bool cycle_helper(int node, bool *visited, bool *stack) {
        // Visit A Node
        visited[node] = true;
        stack[node] = true;
        // If Current Node Leads To A Cycle
        for(int nbr : l[node]) {
            // Two Cases
            // 1. If Neighbour Is Present In Current Path
            if(stack[nbr] == true) return true;
            // 2. Neighbour Is Not Visited Yet
            else if(visited[nbr] == false) {
                bool cycle_found = cycle_helper(nbr, visited, stack);
                if(cycle_found == true) return true;
            }
        }
        // Leave A Node
        stack[node] = false;
        return false;
    }
    bool contain_cycle() {
        // Check For Cycle In Directed Graph
        bool *visited = new bool[V];
        bool *stack = new bool[V];
        for(int i = 0; i < V; i++) visited[i] = stack[i] = false;
        return cycle_helper(0, visited, stack);
    }
};

int main() {
    FIO;
    Graph G(7);
    G.addEdge(0, 1);
    G.addEdge(1, 2);   
    G.addEdge(2, 3);   
    G.addEdge(3, 4);   
    G.addEdge(4, 5);   
    G.addEdge(1, 5);   
    G.addEdge(5, 6);   
    G.addEdge(4, 2); // Back-Edge   
    if(G.contain_cycle()) cout << "Graph Contains A Cycle\n";
    else cout << "Graph Doesn't Contains A Cycle\n";
    return 0;
}