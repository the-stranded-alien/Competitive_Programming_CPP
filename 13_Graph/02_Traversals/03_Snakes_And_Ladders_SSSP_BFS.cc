#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class Graph {
    map<T, list<T> > l;
public:
    void addEdge(int x, int y) {
        l[x].push_back(y);
    }
    // Snakes And Ladders
    T sssp(T src, T dest) {
        map<T, int> dist;
        map<T, T> parent;
        queue<T> q;

        // Except Source Node All Other Nodes Will Have INT_MAX
        for(auto node_pair : l) {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!q.empty()) {
            T node = q.front();
            q.pop();
            for(int nbr : l[node]) {
                if(dist[nbr] == INT_MAX) {
                    q.push(nbr);
                    // Mark That Neighbour Visited
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                }
            }
        }
        // Print The Distance To Dest Node
        // for(auto node_pair : l) {
            // cout << "Node : " << node_pair.first << " -> Is At Distance : " << dist[node_pair.first] << endl; 
        // }
        // Path From Dest To Src
        T temp = dest;
        cout << "Path Followed : ";
        while(temp != src) {
            cout << temp << " <-- ";
            temp = parent[temp];
        }
        cout << src << endl;

        return dist[dest];
    }
};

int main() {
    // Input    
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    // Add All Edges To The Graph 
    Graph<int> g;
    for(int i = 0; i <= 36; i++) {
        for(int dice = 1; dice <= 6; dice++) {
            int j = i + dice;
            j += board[j];
            if(j <= 36) g.addEdge(i, j);
        }
    }
    g.addEdge(36, 36);
    int d = g.sssp(0, 36);
    cout << "Minimum Dice Throws : " << d << endl;
    return 0;
}