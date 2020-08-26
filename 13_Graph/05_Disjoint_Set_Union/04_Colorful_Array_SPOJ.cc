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

// CLFLARR - COLORFUL ARRAY (SPOJ)
// You have been given an array of n unpainted elements. By unpainted, we mean that
// each element initially has a value of 0. You have to process q queries of the form
// l r c, in which you paint all the elements of the array from index l to index r with
// color c. Assume that, each new color currently being applied to an element overrides
// its previous color. Output the color of each element after all the queries have been
// processed.

struct dsu {
    vector<int> par;
    void init(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    // Gives Super-Parent Of 'x'
    int get(int x) {
        return (x == par[x] ? x : (par[x] = get(par[x])));
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(x != y) {
            par[x] = max(par[x], par[y]);
            par[y] = max(par[x], par[y]);
        }
    }
};

int main() {
    FIO;
    int n, q;
    cin >> n >> q;
    int l[q], r[q], c[q];
    for(int i = 0; i < q; i++) cin >> l[i] >> r[i] >> c[i];
    dsu G;
    G.init(n + 2);
    int res[n + 2] = {};
    for(int i = (q - 1); i >= 0; i--) {
        // Index -> Right Most Non Colored Index
        int index = G.get(l[i]);
        while(index <= r[i]) {
            res[index] = c[i];
            G.unite(index, (index + 1));
            // Switch To Right Most Place Which Is Not Colored.
            index = G.get(index);
        }
    }
    for(int i = 1; i <= n; i++) cout << res[i] << '\n';
    return 0;
}
