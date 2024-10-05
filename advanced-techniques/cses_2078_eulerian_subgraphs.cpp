/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-09-03 18:14:51
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<bool> vis(n);
    int num_edge = 0, num_ver = 0;
    auto dfs = [&](auto &&self, int u, int par = -1) -> void {
        vis[u] = true;
        ++num_ver;
        num_edge += (int) g[u].size();
        for (int v : g[u]) {
            if (v == par) continue;
            if (!vis[v]) {
                self(self, v, u);
            }
        }
    };
    vector<int> pw(m + 3);
    pw[0] = 1;
    const int MOD = (int) 1e9 + 7;
    for (int i = 1; i < m + 3; ++i) {
        pw[i] = 2 * pw[i - 1];
        if (pw[i] >= MOD) pw[i] -= MOD;
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            num_edge = 0;
            num_ver = 0;
            dfs(dfs, i);
            assert(num_edge % 2 == 0);
            num_edge /= 2;
            int cur_ans = pw[num_edge - num_ver + 1];
            ans = 1LL * ans * cur_ans % MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}

/**
The number of Eulerian subgraphs of a connected graph is 2^(m - n + 1) 
*/
