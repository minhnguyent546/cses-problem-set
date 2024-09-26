/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-22 09:13:09
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].emplace_back(b, c);
    }
    using Node = pair<long long, int>;
    priority_queue<Node, vector<Node>, greater<>> pq;
    vector<vector<long long>> dist(n);
    int s = 0, t = n - 1;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if ((int) dist[u].size() == k) continue;
        dist[u].emplace_back(d);
        if (u == t && (int) dist[u].size() == k) {
            for (int i = 0; i < k; ++i) {
                cout << dist[u][i] << ' ';
            }
            cout << '\n';
            return 0;
        }
        for (auto [v, w] : g[u]) {
            if ((int) dist[v].size() < k) {
                pq.emplace(d + w, v);
            }
        }
    }
    assert(false);
    return 0;
}
