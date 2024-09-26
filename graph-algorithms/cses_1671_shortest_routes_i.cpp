/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-07-20 16:42:28
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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].emplace_back(v, w);
    }
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<long long> dist(n, INF);
    int s = 0;
    dist[s] = 0;
    using node = pair<long long, int>;
    priority_queue<node, vector<node>, greater<>> pq;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}

/*
Time complexity: O(mlog(n))
 */
