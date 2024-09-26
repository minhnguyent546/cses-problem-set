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
    int n;
    cin >> n;
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
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        int u = i;
        if (!in_cycle[u]) {
            auto [par, dist] = jump_to_cycle(u);
            ans += dist;
            u = par;
        }
        assert(in_cycle[u]);
        ans += cycle_size[cycle_id[u]];
        cout << ans << ' ';
    }
    cout << '\n';
    return 0;
}
