#include<iostream>
#include<list>
using namespace std;

// HOLI - Holiday Accommodation (SPOJ)
// Nowadays, people have many ways to save money on accommodation when
// they are on vacation. One of these ways is exchanging houses with other people.
// Here is a group of N people who want to travel around the world.
// They live in different cities, so they can travel to some other people's
// city and use someone's house temporary. Now they want to make a plan
// that choose a destination for each person. There are two rules should be satisfied:
// 1. All the people should go to one of the other people's city.
// 2. Two of them never go to the same city, because they are not willing to share a house.
// They want to maximize the sum of all people's travel distance.
// The travel distance of a person is the distance between the city he lives in and the
// city he travels to. These N cities have N-1 highways connecting them.
// The travelers always choose the shortest path when traveling.
// Given the highways' information, it is your job to find the best plan,
// that maximum the total travel distance of all people.

class Graph{
    int V;
    list<pair<int, int> > *l;

public:
    Graph(int v) {
        V = v;
        l = new list<pair<int, int> > [V];
    }
    
    void addEdge(int u, int v, int cost) {
        l[u].push_back(make_pair(v, cost));
        l[v].push_back(make_pair(u, cost));
    }

    int dfs_helper(int node, bool *visited, int *count, int &ans) {
        // Mark The Node As Visited
        visited[node] = true;
        count[node] = 1;
        for(auto nbr_pair : l[node]) {
            int nbr = nbr_pair.first;
            int wt = nbr_pair.second;
            if(!visited[nbr]) {
                count[node] += dfs_helper(nbr, visited, count, ans);
                int nx = count[nbr]; 
                int ny = V - nx;
                ans += 2 * min(nx, ny) * wt; 
            }
        }
        // Just Before Leaving The Node Parent
        return count[node];
    }

    int dfs() {
        bool *visited = new bool[V];
        int *count = new int[V];

        for(int i = 0; i < V; i++) {
            visited[i] = false;
            count[i] = 0;
        }

        int ans = 0;
        dfs_helper(0, visited, count, ans);
        return ans;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 2);
    cout << g.dfs() << endl;
    return 0;
}