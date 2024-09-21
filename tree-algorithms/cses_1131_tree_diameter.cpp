/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 07:13:03
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
    int max_d = -1, max_d_u = -1;
    auto dfs = [&](auto &&self, int u, int d, int par = -1) -> void {
        if (d > max_d) {
            max_d = d;
            max_d_u = u;
        }
        for (int v : g[u]) {
            if (v == par) continue;
            self(self, v, d + 1, u);
        }
    };
    dfs(dfs, 0, 0);
    max_d = -1;
    dfs(dfs, max_d_u, 0);
    cout << max_d << '\n';
    
    return 0;
}
