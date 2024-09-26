/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-07-20 16:07:22
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
    int s = 0, t = n - 1;
    vector<int> par(n, -1);
    vector<int> que;
    que.emplace_back(s);
    par[s] = s;
    for (int i = 0; i < (int) que.size(); ++i) {
        int u = que[i];
        for (int v : g[u]) {
            if (par[v] == -1) {
                par[v] = u;
                que.emplace_back(v);
            }
        }
    }
    if (par[t] == -1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    vector<int> vers;
    int cur = t;
    while (cur != s) {
        assert(cur != -1);
        vers.emplace_back(cur);
        cur = par[cur];
    }
    vers.emplace_back(s);
    reverse(vers.begin(), vers.end());
    cout << vers.size() << '\n';
    for (int v : vers) {
        cout << v + 1 << ' ';
    }
    cout << '\n';
    
    return 0;
}
