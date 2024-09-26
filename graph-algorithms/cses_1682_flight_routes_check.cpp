/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-31 16:30:28
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
    vector<vector<int>> g(n), h(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        h[v].emplace_back(u);
    }
    vector<bool> visited(n);
    auto dfs = [&](auto &&self, int u, const vector<vector<int>> &adj) -> void {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) self(self, v, adj);
        }
    };   
    dfs(dfs, 0, g);
    for (int i = 1; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO" << '\n';
            cout << 1 << ' ' << i + 1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) visited[i] = false;
    dfs(dfs, 0, h);
    for (int i = 1; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO" << '\n';
            cout << i + 1 << ' ' << 1 << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
