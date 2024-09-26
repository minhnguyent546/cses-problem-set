/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-31 15:06:01
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
    int n, q;
    cin >> n >> q;
    vector<int> target(n);
    for (int i = 0; i < n; ++i) {
        cin >> target[i];
        --target[i];
    }
    const int LOG = 21;
    vector<vector<int>> next(LOG, vector<int>(n));
    next[0] = target;
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            next[j][i] = next[j - 1][next[j - 1][i]];
        }
    }
    vector<bool> in_cycle(n);
    vector<int> color(n);
    vector<int> cycle_id(n, -1);
    vector<int> index_in_cycle(n, -1);
    vector<int> cycle_size;
    int cycle_cnt = 0;
    auto dfs = [&](auto &&self, int u) -> void {
        color[u] = 1;
        int v = target[u];
        if (color[v] == 1) {
            int cur = v;
            int index = 0;
            while (true) {
                in_cycle[cur] = true;
                cycle_id[cur] = cycle_cnt;
                index_in_cycle[cur] = index++;
                if (cur == u) break;
                cur = target[cur];
            }
            ++cycle_cnt;
            cycle_size.emplace_back(index);
        }
        else if (color[v] == 0) {
            self(self, v);
        }
        color[u] = 2;
    };
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) dfs(dfs, i);
    }

    auto jump_to_cycle = [&](int u) -> pair<int, int> {
        if (in_cycle[u]) return {u, 0};
        int dist = 0;
        for (int i = LOG - 1; i >= 0; --i) {
            int par = next[i][u];
            if (!in_cycle[par]) {
                u = par;
                dist += (1 << i);
            }
        }
        assert(in_cycle[next[0][u]]);
        return {next[0][u], dist + 1};
    };
    auto in_cycle_dist = [&](int u, int v) -> int {
        assert(in_cycle[u]);
        assert(in_cycle[v]);
        if (index_in_cycle[u] <= index_in_cycle[v]) {
            return index_in_cycle[v] - index_in_cycle[u];
        }
        else {
            int sz = cycle_size[cycle_id[u]];
            return sz - (index_in_cycle[u] - index_in_cycle[v]);
        }
    };

    for (int w = 0; w < q; ++w) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (cycle_id[next[LOG - 1][u]] != cycle_id[next[LOG - 1][v]]) {
            // u and v are not in the same component
            cout << -1 << '\n';
        }
        else if (in_cycle[u] && in_cycle[v]) {
            cout << in_cycle_dist(u, v) << '\n';
        }
        else if (in_cycle[u]) {
            cout << -1 << '\n';
        }
        else if (in_cycle[v]) {
            auto [par_u, dist_u] = jump_to_cycle(u);
            cout << dist_u + in_cycle_dist(par_u, v) << '\n';
        }
        else {
            // u and v are in branch
            auto [par_u, dist_u] = jump_to_cycle(u);
            auto [par_v, dist_v] = jump_to_cycle(v);
            if (dist_u < dist_v) {
                cout << -1 << '\n';
            }
            else {
                int diff = dist_u - dist_v;
                for (int i = 0; i < LOG; ++i) {
                    if (diff & (1 << i)) {
                        u = next[i][u];
                    }
                }
                cout << (u == v ? diff : -1) << '\n';
            }
        }
    } 
    
    return 0;
}
