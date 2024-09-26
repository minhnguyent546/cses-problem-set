/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-09-25 10:45:58
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

struct Edge {
    int u, v;
    int w;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges[i] = {u, v, w};
    }


    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<long long> dist(n, INF);
    vector<int> par(n, -1);
    for (int k = 0; k < n - 1; ++k) {
        for (auto [u, v, w] : edges) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }
    
    int x = -1;
    for (auto [u, v, w] : edges) {
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            par[v] = u;
            x = v;
            break;
        }
    }

    if (x == -1) {
        cout << "NO" << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        assert(x != -1);
        x = par[x];
    }

    vector<int> vers;
    int cur = x;
    while (true) {
        assert(cur != -1);
        vers.emplace_back(cur);
        cur = par[cur];
        if (cur == x) break;
    }
    vers.emplace_back(x);
    reverse(vers.begin(), vers.end());
    cout << "YES" << '\n';
    for (int v : vers) {
        cout << v + 1 << ' ';
    }
    cout << '\n';
    return 0;
}
