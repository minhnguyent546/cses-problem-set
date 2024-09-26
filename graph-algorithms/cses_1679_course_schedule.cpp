/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-22 10:00:59
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
    vector<int> in(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        in[v]++;
        g[u].push_back(v);
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
            if (--in[v] == 0) {
                que.emplace_back(v);
            }
        }
    }
    if ((int) que.size() < n) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    for (int u : que) {
        cout << u + 1 << ' ';
    }
    cout << '\n';
    
    return 0;
}
