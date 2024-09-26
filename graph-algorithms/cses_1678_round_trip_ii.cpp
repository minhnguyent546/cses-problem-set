/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-22 09:35:37
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
    vector<int> state(n), par(n, -1);
    auto dfs = [&](auto &&self, int u) -> bool {
        state[u] = 1;
        for (int v : g[u]) {
            if (state[v] == 1) {
                vector<int> vers;
                int cur = u;
                vers.emplace_back(v);
                while (true) {
                    vers.emplace_back(cur);
                    if (cur == v) break;
                    if (cur == -1) {
                    }
                    assert(cur != -1);
                    cur = par[cur];
                }
                reverse(vers.begin(), vers.end());
                cout << vers.size() << '\n';
                for (int v : vers) {
                    cout << v + 1 << ' ';
                }
                cout << '\n';
                return true;
            }
            else if (state[v] == 0) {
                par[v] = u;
                if (self(self, v)) return true;
            }
        }
        state[u] = 2;
        return false;
    };
    bool has_cycle = false;
    for (int i = 0; i < n; ++i) {
        if (state[i] == 0) {
            if (dfs(dfs, i)) {
                has_cycle = true;
                break;
            }
        }
    }
    if (!has_cycle) {
        cout << "IMPOSSIBLE" << '\n';
    }
    
    return 0;
}
