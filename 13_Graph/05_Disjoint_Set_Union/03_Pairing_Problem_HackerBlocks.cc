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

// Pairing (HackerBlocks)
// There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there
// is no path from first city to second city. You are given information in the form of M
// pairs (X,Y) i.e there is an undirected road between city X and city Y.
// Find out the number of ways in which cities can be chosen.

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

    // Find (With Path Compression)
    int findSet(int i, int parent[]) {
        // Base Case
        if(parent[i] == -1) return i;
        // Recursive Case
        return (parent[i] = findSet(parent[i], parent)); // Updation + Return
    }

    // Union (With Union By Rank)
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

    int pairing() {
        // Init DSU Logic
        int *parent = new int[V];
        int *rank = new int[V];
        for(int i = 0; i < V; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
        // Code Logic
        for(auto edge : l) {
            int i = edge.F;
            int j = edge.S;
            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);
            unionSet(s1, s2, parent, rank);
        }
        // Go To All The Nodes
        int ans = 0;
        for(int i = 0; i < V; i++) {
            ans += V - rank[findSet(i, parent)];
        }
        delete [] parent;
        delete [] rank;
        return (ans / 2);
    }
};

int main() {
    FIO;
    int n, m;
    cin >> n >> m;
    Graph g(n);
    while(m--) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    cout << g.pairing() << endl;
    return 0;
}
