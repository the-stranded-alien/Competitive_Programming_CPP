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

vector<int> graph[1000];

void bfs(int src, int n, int &ans) {
    vector<int> dist((n + 1), INT_MAX);
    queue<int> Q;
    Q.push(src);
    dist[src] = 0;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(auto nbr : graph[cur]) {
            if(dist[nbr] == INT_MAX) {
                // Neighbour Is Not Visited
                dist[nbr] = dist[cur] + 1;
                Q.push(nbr);
            }
            else if(dist[nbr] >= dist[cur]) { // Edge Is Not Pointing To Parent
                // Backedge Is Encountered
                ans = min(ans, (dist[nbr] + dist[cur] + 1));
            }
        }
    }
    return;
}

void shortestCycle() {
    int m, n;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    int ans = (n + 1);
    for(int j = 1; j <= n; j++) {
        bfs(j, n, ans);
    }
    if(ans == (n + 1)) cout << "No Cycle Present\n";
    else cout << "Shortest Cycle Is Of Length : " << ans << endl;
    return;
}

int main() {
    FIO;
    shortestCycle();
    return 0;
}