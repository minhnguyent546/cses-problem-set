/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-07-20 16:49:08
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
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> adj(n, vector<long long>(n, INF_LL));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u][v] = min(adj[u][v], (long long) w);
        adj[v][u] = min(adj[v][u], (long long) w);
    }
    for (int i = 0; i < n; ++i) adj[i][i] = 0;
    vector<vector<long long>> dist = adj;
    for (int k = 0; k < n; ++k) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (dist[u][v] > dist[u][k] + dist[k][v]) {
                    dist[u][v] = dist[u][k] + dist[k][v];
                }
            }
        }
    }
    for (int w = 0; w < q; ++w) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        cout << (dist[u][v] < INF_LL ? dist[u][v] : -1) << '\n';
    }
    return 0;
}
