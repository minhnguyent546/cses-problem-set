/**            
 * author      minhnguyent546
 * created_at  Fri, 2024-08-09 01:06:59
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
    auto dfs = [&](auto &&self, int u, int par = -1) -> void {
        sz[u] = 1;
        for (int v : g[u]) {
            if (v != par) {
                self(self, v, u);
                sz[u] += sz[v];
            }
        }
    };

    auto find_centroid = [&](auto &&self, int u, int par = -1) -> int {
        for (int v : g[u]) {
            if (v != par) {
                if (sz[v] * 2 > n) {
                    return self(self, v, u);
                }
            }
        }
        return u;
    };
    dfs(dfs, 0);
    cout << find_centroid(find_centroid, 0) + 1 << '\n';
    
    return 0;
}
