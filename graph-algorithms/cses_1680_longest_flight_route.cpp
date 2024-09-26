/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-07-25 23:32:45
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
    }
    vector<int> order;
    vector<bool> vis(n);
    auto dfs = [&](auto &&self, int u) -> void {
        vis[u] = true;
        for (int v : g[u]) {
            if (!vis[v]) {
                self(self, v);
            }
        }
        order.emplace_back(u);
    }; 
    int s = 0, t = n - 1;
    dfs(dfs, s);
    reverse(order.begin(), order.end());
    vector<int> dp(n, -INF), trace(n, -1);
    dp[s] = 1;
    for (int u : order) {
        if (dp[u] == -INF) continue;
        for (int v : g[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                trace[v] = u;
            }
        }
    }
    if (dp[t] == -INF) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    cout << dp[t] << '\n';
    vector<int> path;
    int cur = t;
    while (true) {
        assert(cur != -1);
        path.emplace_back(cur);
        if (cur == s) break;
        cur = trace[cur]; 
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v + 1 << ' ';
    }
    cout << '\n';   
    return 0;
}
