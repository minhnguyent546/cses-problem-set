/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-22 08:23:29
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
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].emplace_back(b, c);
    }
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<array<long long, 2>> dist(n, {INF, INF});
    using Node = tuple<long long, int, int>;
    priority_queue<Node, vector<Node>, greater<>> pq;
    int s = 0, t = n - 1;
    dist[s][0] = dist[s][1] = 0;
    pq.emplace(dist[s][0], s, 0);
    while (!pq.empty()) {
        auto [d, u, used] = pq.top(); pq.pop();
        if (d > dist[u][used]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v][used] > dist[u][used] + w) {
                dist[v][used] = dist[u][used] + w;
                pq.emplace(dist[v][used], v, used);
            }
            if (used == 0 && dist[v][1] > dist[u][used] + w / 2) {
                dist[v][1] = dist[u][used] + w / 2;
                pq.emplace(dist[v][1], v, 1);
            }
        }
    }
    assert(dist[t][1] <= dist[t][1]);
    cout << dist[t][1] << '\n';

    return 0;
}
