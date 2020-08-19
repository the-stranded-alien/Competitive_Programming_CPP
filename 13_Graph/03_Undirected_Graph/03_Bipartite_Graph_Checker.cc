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

const int N = 1000005;
vector<int> graph[N];

int vis[N]; // 0 -> Not Visited, 1 -> Color 1, 2 -> Color 2
bool odd_cycle = 0;
void dfs(int cur, int parent, int col) {
    vis[cur] = col;
    for(auto child : graph[cur]) {
        if(vis[child] == 0) {
            dfs(child, cur, (3 - col)); // Change Color 1 <-> 2
        }
        else if((child != parent) && (col == vis[child])) {
            // Backedge And Odd Length Cycle
            odd_cycle = 1;
        }
    }
    return;
}

void check_bipartite() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    dfs(1, 0, 1);
    if(odd_cycle) cout << "Not A Bipartite Graph\n";
    else cout << "A Bipartite Graph\n";
    return;
}

int main() {
    FIO;
    check_bipartite();
    return 0;
}