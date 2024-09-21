/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 21:11:02
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
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> ans(n);
    vector<set<int>> distinct_vals(n);
    auto dfs = [&](auto &&self, int u, int par = -1) -> void {
        distinct_vals[u].emplace(vals[u]);
        for (int v : g[u]) {
            if (v == par) continue;
            self(self, v, u);
            if (distinct_vals[v].size() > distinct_vals[u].size()) distinct_vals[u].swap(distinct_vals[v]);
            for (const int &value : distinct_vals[v]) {
                distinct_vals[u].emplace(value);
            }
        }
        ans[u] = (int) distinct_vals[u].size();
    };
    dfs(dfs, 0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}
