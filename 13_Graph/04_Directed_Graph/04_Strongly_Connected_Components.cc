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

// Kosaraju's Algorithm
const int N = 100005;
vector<int> graph[N];
vector<int> graphRev[N]; // Reverse Graph
vector<int> Order;
int vis[N];
int comp[N];
vector<int> in_comp[N]; // Store Component Info

void dfs(int cur) {
    vis[cur] = 1;
    for(auto x : graph[cur]) {
        if(!vis[x]) dfs(x);
    }
    Order.pb(cur);
    return;
}

void dfs_reverse(int cur, int col) {
    comp[cur] = col;
    in_comp[col].pb(cur);
    vis[cur] = 1;
    for(auto x : graphRev[cur]) {
        if(!vis[x]) dfs_reverse(x, col);
    }
    return;
}

void stronglyConnected() {
    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graphRev[y].pb(x);
    }
    // Call DFS
    for(int i = 1; i <= V; i++) {
        if(!vis[i]) dfs(i);
    }
    // Start From Back Side Of The Order Vector
    // And Perform DFS On The Reverse Graph
    memset(vis, 0, sizeof(vis));
    int color = 1;
    for(int i = V; i >= 1; i--) {
        if(!vis[Order[i]]) {
            dfs_reverse(Order[i], color);
            color++; // Add Another Color For Another Strongly Connected Components
        }
    }
    // Print Component Of Every Node
    for(int i = 1; i <= V; i++) {
        cout << i << " --> " << comp[i] << "\n";
    }
    return;
}

int main() {
    FIO;
    stronglyConnected();
    return 0;
}