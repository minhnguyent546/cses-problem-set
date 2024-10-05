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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> in(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[v].emplace_back(u);
        in[u]++;
    }

    vector<Bit> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i].set(i);
    }
    vector<int> que;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            que.emplace_back(i);
        }
    }
    for (int i = 0; i < (int) que.size(); ++i) {
        int u = que[i];
        for (int v : g[u]) {
            ans[v] |= ans[u];
            if (--in[v] == 0) {
                que.emplace_back(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i].count() << " \n"[i == n - 1];
    }
    return 0;

    // Time: O(n^2 / w) where w = 32 or 64
}
