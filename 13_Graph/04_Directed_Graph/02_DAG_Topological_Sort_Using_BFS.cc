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
    list<int> *l;
    int V;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y) {
        l[x].pb(y); // Directed Graph
    }
    void topologicalSort() {
        // Indegree
        int *indegree = new int[V];
        for(int i = 0; i < V; i++) indegree[i] = 0;
        // Update Indegree By Traversing Edges x->y : indegree[y]++
        for(int i = 0; i < V; i++) {
            for(auto y : l[i]) indegree[y]++;
        }
        // BFS
        queue<int> Q;
        // 1. Find Nodes With 0 Indegree
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) Q.push(i);
        }
        // 2. Start Removing Elements From The Queue
        while(!Q.empty()) {
            int node = Q.front();
            cout << node << " ";
            Q.pop();
            // 3. Iterate Over Neighbours Of That Node And Reduce Their Indegree By 1
            for(auto nbr : l[node]) {
                indegree[nbr]--;
                // 4. If Indegree Of Any Neighbour Becomes 0, Push It Into The Queue
                if(indegree[nbr] == 0) Q.push(nbr);
            }
        }
        return;
    }
};

int main() {
    FIO;
    Graph G(6);
    G.addEdge(0, 2);
    G.addEdge(1, 2);
    G.addEdge(1, 4);
    G.addEdge(2, 3);
    G.addEdge(2, 5);
    G.addEdge(3, 5);
    G.addEdge(4, 5);
    G.topologicalSort();
    return 0;
}