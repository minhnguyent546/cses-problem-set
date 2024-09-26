/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-07-25 23:44:37
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
    int s = 0, t = n - 1;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    vector<long long> dist(n, INF_LL);
    vector<long long> sum(n, 0);
    vector<int> min_num(n, INF);
    vector<int> max_num(n, -INF);
    dist[s] = 0;
    sum[s] = 1;
    min_num[s] = 0;
    max_num[s] = 0;
    using Node = pair<long long, int>;
    vector<bool> vis(n);
    priority_queue<Node, vector<Node>, greater<>> pq;
    set<Node> st;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                sum[v] = sum[u];
                min_num[v] = min_num[u] + 1;
                max_num[v] = max_num[u] + 1;
                pq.emplace(dist[v], v);
            }
            else if (dist[v] == d + w) {
                sum[v] += sum[u];
                if (sum[v] >= MOD) sum[v] -= MOD;
                min_num[v] = min(min_num[v], min_num[u] + 1);
                max_num[v] = max(max_num[v], max_num[u] + 1);
                pq.emplace(dist[v], v);
            }
        }
    }
    assert(dist[t] < INF_LL);
    // assert(sum[t] > 0);
    assert(min_num[t] < INF);
    assert(max_num[t] > -INF);
    cout << dist[t] << ' ' << sum[t] % MOD << ' ' << min_num[t] << ' ' << max_num[t] << '\n';
    return 0;
}

/*
1. min cost
2. number of such min cost
3. min flights in such min cost
4. max flights in such min cost
 */
