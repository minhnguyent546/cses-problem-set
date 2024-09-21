/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 07:08:51
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
    vector<bool> taken(n);
    int cnt = 0;
    auto dfs = [&](auto &&self, int u, int par) -> void {
        for (int v : g[u]) {
            if (v == par) continue;
            self(self, v, u);
        }
        for (int v : g[u]) {
            if (v == par) continue;
            if (!taken[v]) {
                taken[v] = true;
                taken[u] = true;
                ++cnt;
                break;
            }
        }
    };  
    int root = 0;
    dfs(dfs, root, -1);
    cout << cnt << '\n';
    
    return 0;
}
