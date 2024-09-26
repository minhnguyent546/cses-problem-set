/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-31 16:21:33
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct Dsu {
    int n;
    vector<int> par, sz;
    int comp, largest;
    Dsu(int _n): n(_n), par(_n), sz(_n) {
        init();
    }
    void init() {
        comp = n;
        largest = 1;
        for (int i = 0; i < n; ++i) {
            par[i] = i, sz[i] = 1;
        }
    }
    int find(int v) {
        while (v != par[v]) {
            v = par[v] = par[par[v]];
        }
        return v;
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        par[v] = u;
        sz[u] += sz[v];
        --comp;
        largest = max(largest, sz[u]);
        return true;
    }
};

struct Edge {
    int u, v;
    int w;

    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};  

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    Dsu dsu(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        dsu.unite(u, v);
        cout << dsu.comp << ' ' << dsu.largest << '\n';
    }

    return 0;
}
