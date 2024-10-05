/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-12 00:24:28
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

const int N = (int) 5e4;
using Bit = bitset<N>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
    }

    vector<int> low(n), num(n), scc_id(n), stack;
    vector<bool> used(n);
    int timer = 0, scc_cnt = 0;
    auto Tarjan = [&](auto &&self, int u) -> void {
        low[u] = num[u] = ++timer;
        stack.emplace_back(u);
        for (int v : g[u]) {
            if (used[v]) continue;
            if (num[v]) {
                low[u] = min(low[u], num[v]);
            }
            else {
                self(self, v);
                low[u] = min(low[u], low[v]);
            }
        }
        if (low[u] == num[u]) {
            int v;
            do {
                v = stack.back(); stack.pop_back();
                used[v] = true;
                scc_id[v] = scc_cnt;
            } while (v != u);
            ++scc_cnt;
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!num[i]) {
            Tarjan(Tarjan, i);
        }
    }
    vector<vector<int>> h(scc_cnt);
    vector<int> in(scc_cnt);
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            if (scc_id[u] == scc_id[v]) continue;
            h[scc_id[u]].emplace_back(scc_id[v]);
            in[scc_id[v]]++;
        }
    }
    vector<Bit> reachabilites(scc_cnt);
    for (int i = 0; i < scc_cnt; ++i) {
        reachabilites[i].set(i);
    }
    vector<int> que;
    for (int i = 0; i < scc_cnt; ++i) {
        if (in[i] == 0) {
            que.emplace_back(i);
        }
    }
    for (int i = 0; i < (int) que.size(); ++i) {
        int u = que[i];
        for (int v : h[u]) {
            reachabilites[v] |= reachabilites[u];
            if (--in[v] == 0) {
                que.emplace_back(v);
            }
        }
    }
    for (int w = 0; w < q; ++w) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        u = scc_id[u], v = scc_id[v];
        cout << (reachabilites[v][u] ? "YES" : "NO") << '\n';
    }
    return 0;

}
