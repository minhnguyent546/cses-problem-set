/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 07:06:05
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
    for (int i = 1; i < n; ++i) {
        int par;
        cin >> par;
        --par;
        g[par].emplace_back(i);
    }
    vector<int> sz(n);
    auto dfs = [&](auto &&self, int u) -> void {
        sz[u] = 1;
        for (int v : g[u]) {
            self(self, v);
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0);
    for (int i = 0; i < n; ++i) {
        cout << sz[i] - 1 << ' ';
    }
    cout << '\n';
    
    return 0;
}
