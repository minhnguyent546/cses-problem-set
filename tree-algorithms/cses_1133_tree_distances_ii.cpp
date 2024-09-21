/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 08:43:18
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
    vector<int> sz(n);
    vector<long long> subtree_dist(n);
    auto dfs = [&](auto &&self, int u, int par = -1) -> void {
        sz[u] = 1;
        for (int v : g[u]) {
            if (v != par) {
                self(self, v, u);
                sz[u] += sz[v];
                subtree_dist[u] += subtree_dist[v] + sz[v];
            }
        }
    };
    int root = 0;
    dfs(dfs, root);

    vector<long long> sum_dist(n);
    sum_dist[root] = subtree_dist[root];
    auto dfs2 = [&](auto &&self, int u, int par = -1) -> void {
        for (int v : g[u]) {
            if (v != par) {
                sum_dist[v] = sum_dist[u] + n - 2 * sz[v];
                self(self, v, u);
            }
        }
    };
    dfs2(dfs2, root);
    for (int i = 0; i < n; ++i) {
        cout << sum_dist[i] << " \n"[i == n - 1];
    }
    
    return 0;
}
