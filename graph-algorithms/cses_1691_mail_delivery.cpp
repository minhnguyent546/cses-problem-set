/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-31 20:35:59
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

struct Edge {
    int v;
    list<Edge>::iterator reverse_edge;
    Edge() {}
    Edge(int _v): v(_v) {}
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<list<Edge>> g(n);
    vector<int> deg(n);
    vector<int> par(n);
    for (int i = 0; i < n; ++i) par[i] = i;
    int comp = n;
    auto Find = [&](int v) -> int {
        while (v != par[v]) {
            v = par[v] = par[par[v]];
        }
        return v;
    };
    auto Unite = [&](int u, int v) -> bool {
        u = Find(u), v = Find(v);
        if (u == v) return false;
        par[v] = u;
        --comp;
        return true;
    };
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        ++deg[u];
        ++deg[v];
        g[u].emplace_front(v);
        g[v].emplace_front(u);
        Unite(u, v);

        g[u].front().reverse_edge = g[v].begin();
        g[v].front().reverse_edge = g[u].begin();
    }

    int post_office_root = Find(0);
    for (int i = 1; i < n; ++i) {
        int root = Find(i);
        if (root == post_office_root) continue;
        if (deg[root] > 0) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (deg[i] & 1) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }    
    }
    vector<int> vertices;
    auto find_path = [&](auto &&self, int u) -> void {
        while (!g[u].empty()) {
            int v = g[u].front().v;
            g[v].erase(g[u].front().reverse_edge);
            g[u].pop_front();
            self(self, v);
        }
        vertices.emplace_back(u);
    };
    find_path(find_path, 0);
    reverse(vertices.begin(), vertices.end());
    for (int u : vertices) {
        cout << u + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
