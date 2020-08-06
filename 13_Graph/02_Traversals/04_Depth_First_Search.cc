#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

// Depth First Search -> Recursive Way

template<typename T>
class Graph {
    map<T, list<T> > l;
public:
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool> &visited) {
        // Recursive Function That Will Traverse The Graph
        cout << src << " ";
        visited[src] = true;
        // Go To All Neighbours Of That Node That Are Not Visited !
        for(T nbr : l[src]) {
            if(!visited[nbr]) dfs_helper(nbr, visited);
        }
        return;
    }

    void dfs(T src) {
        map<T, bool> visited;
        // Mark All Nodes As Not Visited In The Beginning.
        for(auto p : l) {
            T node = p.first;
            visited[node] = false;
        }
        // Call The Helper Function
        dfs_helper(src, visited);
        return;
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.dfs(0);
    return 0;
}