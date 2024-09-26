/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-07-20 16:33:10
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
    vector<int> par(n, -1);
    auto dfs = [&](auto &&self, int u) -> bool {
        vis[u] = true;
        for (int v : g[u]) {
            if (v == par[u]) continue;
            if (vis[v]) {
                vector<int> vers;
                int cur = u;
                vers.emplace_back(v);
                while (cur != v) {
                    assert(cur != -1);
                    vers.emplace_back(cur);
                    cur = par[cur];
                }
                vers.emplace_back(v);
                reverse(vers.begin(), vers.end());
                cout << vers.size() << '\n';
                for (int v : vers) {
                    cout << v + 1 << ' ';
                }
                cout << '\n';
                return true;
            }
            else {
                par[v] = u;
                if (self(self, v)) return true;
            }
        }
        return false;
    };
    bool has_cycle = false;
    for (int i = 0; i < n; ++i) {
        if (!vis[i] && dfs(dfs, i)) {
            has_cycle = true;
            break;
        }
    }

    if (!has_cycle) {
        cout << "IMPOSSIBLE" << '\n';
    }
    
    return 0;
}
