/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-31 20:03:21
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
    vector<int> num(n), low(n), scc_id(n), stack;
    int timer = 0, scc_cnt = 0;
    vector<bool> used(n);
    auto tarjan = [&](auto &&self, int u) -> void {
        num[u] = low[u] = ++timer;
        stack.push_back(u);
        for (int v : g[u]) {
            if (used[v]) continue;
            if (num[v] > 0) {
                low[u] = min(low[u], num[v]);
            }
            else {
                self(self, v);
                low[u] = min(low[u], low[v]);
            }
        }
        if (num[u] == low[u]) {
            int v;
            do {
                v = stack.back(); stack.pop_back();
                scc_id[v] = scc_cnt;
                used[v] = true;
            } while (v != u);
            ++scc_cnt;
        }   
    };  
    for (int i = 0; i < n; ++i) {
        if (num[i] == 0) tarjan(tarjan, i);
    }
    cout << scc_cnt << '\n';
    for (int i = 0; i < n; ++i) {
        cout << scc_id[i] + 1 << ' ';
    }
    
    return 0;
}
