/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-31 20:08:56
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

struct TwoSat {
    int n;
    vector<vector<int>> g, tg;
    vector<int> comp, order;
    vector<bool> visited, vals;
    TwoSat(int _n): n(_n), g(n * 2), tg(n * 2), comp(n * 2), visited(n * 2), vals(n) {}
    void either(int u, int v) {
        u = max(2 * u, -2 * u - 1);
        v = max(2 * v, -2 * v - 1);
        g[u ^ 1].emplace_back(v);
        g[v ^ 1].emplace_back(u);
        tg[v].emplace_back(u ^ 1);
        tg[u].emplace_back(v ^ 1);
    }
    void set(int u) { either(u, u); }
    void dfs1(int u) {
        visited[u] = true;
        for (int v : g[u]) {
            if (!visited[v]) dfs1(v);
        }
        order.push_back(u);
    }
    void dfs2(int u, int scc_id) {
        comp[u] = scc_id;
        for (int v : tg[u]) {
            if (comp[v] == -1) dfs2(v, scc_id);
        }
    }
    bool solve() {
        for (int i = 0; i < 2 * n; ++i) {
            if (!visited[i]) dfs1(i);
        }
        fill(comp.begin(), comp.end(), -1);
        for (int i = 2 * n - 1, scc_id = 0; i >= 0; --i) {
            int u = order[i];
            if (comp[u] == -1) dfs2(u, scc_id++);
        }
        for (int i = 0; i < n; ++i) {
            int u = i * 2, nu = i * 2 + 1;
            if (comp[u] == comp[nu]) {
                return false;
            }
            vals[i] = comp[u] > comp[nu];
        }
        return true;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    TwoSat two_sat(m);
    for (int i = 0; i < n; ++i) {
        char tx, ty;
        int x, y;
        cin >> tx >> x >> ty >> y;
        --x; --y;
        if (tx == '-') x = ~x;
        if (ty == '-') y = ~y;
        two_sat.either(x, y);
    }
    if (!two_sat.solve()) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        cout << (two_sat.vals[i] ? '+' : '-') << ' ';
    }
    cout << '\n';
    
    return 0;
}
