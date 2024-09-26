/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-31 20:18:52
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
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }
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

    vector<long long> scc_vals(scc_cnt);
    for (int i = 0; i < n; ++i) {
        scc_vals[scc_id[i]] += vals[i];
    }

    vector<vector<int>> h(scc_cnt);
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            if (scc_id[v] == scc_id[u]) continue;
            h[scc_id[u]].emplace_back(scc_id[v]);
        }
    }
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    vector<long long> dp(n, -INF_LL);
    vector<int> in(scc_cnt);
    for (int i = 0; i < scc_cnt; ++i) {
        for (int v : h[i]) in[v]++;
    }
    vector<int> que;
    for (int i = 0; i < scc_cnt; ++i) {
        if (in[i] == 0) {
            que.emplace_back(i);
            dp[i] = scc_vals[i];
        }
    }
    for (int i = 0; i < (int) que.size(); ++i) {
        int u = que[i];
        for (int v : h[u]) {
            if (dp[v] < dp[u] + scc_vals[v]) {
                dp[v] = dp[u] + scc_vals[v];
            }
            if (--in[v] == 0) {
                que.emplace_back(v);
            }
        }
    }
    long long ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
    return 0;
}
