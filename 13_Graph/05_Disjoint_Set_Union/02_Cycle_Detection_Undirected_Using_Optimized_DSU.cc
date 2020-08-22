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

// Cycle Detection In A Undirected Graph Using DSU.

class Graph { // Edge List Representation
    int V;
    list<pair<int, int> > l;
public:
    Graph(int V) {
        this->V = V;
    }
    int addEdge(int u, int v) {
        l.push_back(make_pair(u, v));
    }

    // Find With Path Compression
    int findSet(int i, int parent[]) {
        // Base Case
        if(parent[i] == -1) return i;
        // Recursive Case
        return (parent[i] = findSet(parent[i], parent)); // Updation + Return
    }

    // Union With Union By Rank
    void unionSet(int x, int y, int parent[], int rank[]) {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if(s1 != s2) {
            if(rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
            
        }
        return;
    }

    bool contains_cycle() {
        // DSU Logic To Check If Graph Contains Cycle Or Not
        int *parent = new int[V];
        int *rank = new int[V];
        for(int i = 0; i < V; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
        // Iterate Over The Edge List
        for(auto edge : l) {
            int i = edge.F;
            int j = edge.S;
            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);
            if(s1 != s2) unionSet(s1, s2, parent, rank);
            else return true; // Loop Found
        }
        delete [] parent;
        delete [] rank;
        return false;
    }
};

int main() {
    FIO;
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    if(g.contains_cycle()) cout << "Contains Cycle\n";
    else cout << "Doesn't Contain Cycle\n";
    return 0;
}