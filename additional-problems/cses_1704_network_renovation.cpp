/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-10-08 22:14:04
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        ++deg[u];
        ++deg[v];
    }

    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (deg[i] > 1) {
            root = i;
            break;
        }
    }
    assert(root != -1);
    vector<int> leaves;
    function<void(int, int)> dfs = [&](int u, int par = -1) {
        if ((int) g[u].size() == 1) {
            leaves.emplace_back(u);
            return;
        }
        for (int v : g[u]) {
            if (v == par) continue;
            dfs(v, u);
        }
    };
    dfs(root, -1);

    int sz = leaves.size();
    cout << (sz + 1) / 2 << '\n';
    if (sz & 1) {
        cout << leaves[sz - 2] + 1 << ' ' << leaves[sz - 1] + 1 << '\n';
        --sz;
        leaves.pop_back();
    }
    for (int i = 0; i < sz / 2; ++i) {
        cout << leaves[i] + 1 << ' ' << leaves[i + sz / 2] + 1 << '\n';
    }
    
    return 0;
}
