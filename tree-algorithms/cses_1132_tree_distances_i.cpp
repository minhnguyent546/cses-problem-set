/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 07:30:55
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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> dist(n), h(n);
    auto dfs = [&](auto &&self, int u, int par = -1) -> void {
        for (int v : g[u]) {
            if (v == par) continue;
            self(self, v, u);
            dist[u] = max(dist[u], dist[v] + 1);
        }
    };
    auto dfs2 = [&](auto &&self, int u, int par = -1) -> void {
        int k = (int) g[u].size();
        vector<int> left(k + 3);
        left[0] = h[u];
        for (int i = 0; i < k; ++i) {
            int v = g[u][i];
            if (v == par) continue;
            left[i + 1] = dist[v] + 1;
        }
        auto right = left;
        for (int i = 1; i < (int) left.size(); ++i) {
            left[i] = max(left[i], left[i - 1]);
        }
        for (int i = (int) right.size() - 2; i >= 0; --i) {
            right[i] = max(right[i], right[i + 1]);
        }
        for (int i = 0; i < k; ++i) {
            int v = g[u][i];
            if (v == par) continue;
            h[v] = max(left[i], right[i + 2]) + 1;
        }

        for (int v : g[u]) {
            if (v == par) continue;
            self(self, v, u);
        }
    };
    dfs(dfs, 0);
    dfs2(dfs2, 0);
    for (int i = 0; i < n; ++i) {
        cout << max(h[i], dist[i]) << " \n"[i == n - 1];
    }

    return 0;
}
