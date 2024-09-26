/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-07-20 16:17:43
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
    vector<int> color(n, -1);
    for (int s = 0; s < n; ++s) {
        if (color[s] != -1) continue;
        vector<int> que = {s};
        color[s] = 0;
        for (int i = 0; i < (int) que.size(); ++i) {
            int u = que[i];
            for (int v : g[u]) {
                if (color[v] != -1) {
                    if (color[v] == color[u]) {
                        cout << "IMPOSSIBLE" << '\n';
                        return 0;
                    }
                }
                else {
                    color[v] = !color[u];
                    que.emplace_back(v);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << color[i] + 1 << " \n"[i == n - 1];
    }
    
    return 0;
}
