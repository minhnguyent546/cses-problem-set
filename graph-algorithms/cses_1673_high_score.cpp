/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-07-20 17:10:45
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
 
struct Edge {
    int u, v;
    int w;
    Edge(int _u = -1, int _v = -1, int _w = 0): u(_u), v(_v), w(_w) {}
};
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].emplace_back(v, w);
        edges.emplace_back(u, v, -w);
    }
 
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<long long> dist(n, INF);
    int s = 0, t = n - 1;
    dist[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < INF && dist[v] > dist[u] + w) {
                dist[v] = max(-INF, dist[u] + w);
            }
        }
    }
    vector<int> que;
    vector<bool> vis(n);
    for (auto [u, v, w] : edges) {
        if (dist[u] < INF && dist[v] > dist[u] + w) {
            que.emplace_back(v);
            vis[v] = true;
            dist[v] = max(-INF, dist[u] + w);
        }
    }
    for (int i = 0; i < (int) que.size(); ++i) {
        int u = que[i];
        if (u == t) {
            cout << -1 << '\n';
            return 0;
        }
        for (auto [v, w] : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                que.emplace_back(v);
            }
        }
    }
    assert(-INF < dist[t] && dist[t] < INF);
 
    cout << -dist[t] << '\n';
    return 0;
}
