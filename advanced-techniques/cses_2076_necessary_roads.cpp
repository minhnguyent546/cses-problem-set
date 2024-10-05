/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-08-10 21:00:20
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
    vector<int> num(n), low(n);
    vector<bool> joint(n);
    vector<pair<int, int>> bridges;
    int timer = 0;
    auto dfs = [&](auto &&self, int u, int prev = -1) -> void {
        num[u] = low[u] = ++timer;
        int child_cnt = 0;
        for (int v : g[u]) {
            if (v == prev) continue;
            if (num[v]) {
                low[u] = min(low[u], num[v]);
            } else {
                self(self, v, u);
                ++child_cnt;
                low[u] = min(low[u], low[v]);
                if (low[v] == num[v]) {
                    bridges.emplace_back(u, v);
                }

                if (prev != -1 && low[v] >= num[u]) {
                    joint[u] = true;
                }
            }
        }
        if (prev == -1 && child_cnt > 1) {
            joint[u] = true;
        }
    };      
    dfs(dfs, 0);
    cout << bridges.size() << '\n';
    for (auto [u, v] : bridges) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
    return 0;
}
