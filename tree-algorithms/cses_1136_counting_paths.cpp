/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 08:52:14
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


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    const int LOG = 21;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<vector<int>> anc(LOG, vector<int>(n, -1));
    vector<int> dist(n);
    auto dfs = [&](auto &&self, int u, int par = -1) -> void {
        anc[0][u] = par;
        for (int v : g[u]) {
            if (v != par) {
                dist[v] = dist[u] + 1;
                self(self, v, u);
            }
        }
    };
    int root = 0;
    dfs(dfs, root);
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            anc[j][i] = (anc[j - 1][i] != -1 ? anc[j - 1][anc[j - 1][i]] : -1);
        }
    }

    auto get_lca = [&](int u, int v) -> int {
        if (dist[u] < dist[v]) swap(u, v);
        int diff = dist[u] - dist[v];
        for (int i = 0; i < LOG; ++i) {
            if ((diff >> i) & 1) {
                u = anc[i][u];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            int par_u = anc[i][u], par_v = anc[i][v];
            if (par_u != par_v) {
                u = par_u, v = par_v;
            }
        }
        assert(anc[0][u] == anc[0][v]);
        return anc[0][u];
    };

    vector<int> ans(n);
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        int lca = get_lca(u, v);
        ans[u]++;
        ans[v]++;
        ans[lca]--;
        if (anc[0][lca] != -1) {
            ans[anc[0][lca]]--;
        }
    }

    auto dfs2 = [&](auto &&self, int u, int par = -1) -> void {
        for (int v : g[u]) {
            if (v != par) {
                self(self, v, u);
                ans[u] += ans[v];
            }
        }
    };
    dfs2(dfs2, root);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}
