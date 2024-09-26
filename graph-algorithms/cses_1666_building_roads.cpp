/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-07-20 16:03:00
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
    vector<bool> visited(n);
    auto dfs = [&](auto &&self, int u) -> void {
        visited[u] = true;
        for (int v : g[u]) {
            if (!visited[v]) {
                self(self, v);
            }
        }
    };
    vector<int> roots;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            roots.emplace_back(i);
            dfs(dfs, i);
        }
    }
    cout << roots.size() - 1 << '\n';
    for (int i = 1; i < (int) roots.size(); ++i) {
        cout << roots[0] + 1 << ' ' << roots[i] + 1 << '\n';
    }
    
    return 0;
}
