/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-09-03 17:47:44
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

struct Dsu {
    int n;
    vector<int> par, sz;
    Dsu(int _n) : n(_n), par(n), sz(n) { init(); }
    void init() {
        for (int i = 0; i < n; ++i) {
            par[i] = i, sz[i] = 1;
        }
    }
    int find(int v) {
        while (v != par[v]) {
            v = par[v] = par[par[v]];
        }
        return v;
    }
    bool unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
    bool same(int u, int v) { return find(u) == find(v); }
    vector<vector<int>> groups() {
        // returns the list of the "list of the vertices in a connected component".
        vector<int> leader(n);
        for (int i = 0; i < n; ++i) {
            leader[i] = find(i);
        }
        vector<int> id(n, -1);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (id[leader[i]] == -1) {
                id[leader[i]] = count++;
            }
        }
        vector<vector<int>> result(count);
        for (int i = 0; i < n; ++i) {
            result[id[leader[i]]].emplace_back(i);
        }
        return result;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges.emplace_back(u, v);
    }

    vector<pair<int, int>> qs;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        qs.emplace_back(u, v);
    }

    vector<int> left(q, 0), right(q, m + 1);
    Dsu dsu(n);
    vector<vector<int>> cand(m + 1);
    while (true) {
        bool any = false;
        for (int i = 0; i < q; ++i) {
            if (left[i] < right[i]) {
                int mid = left[i] + (right[i] - left[i]) / 2;
                cand[mid].emplace_back(i);
                any = true;
            }
        }
        if (!any) break;
        for (int mid = 0; mid <= m; ++mid) {
            if (mid > 0) dsu.unite(edges[mid - 1].first, edges[mid - 1].second);
            for (int idx : cand[mid]) {
                if (dsu.same(qs[idx].first, qs[idx].second)) {
                    right[idx] = mid;
                } else {
                    left[idx] = mid + 1;
                }
            }
            cand[mid].clear();
        }
        dsu.init();
    }
    for (int i = 0; i < q; ++i) {
        cout << (left[i] <= m ? left[i] : -1) << '\n';
    }
    return 0;
}
