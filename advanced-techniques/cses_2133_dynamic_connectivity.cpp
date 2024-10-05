/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-10-05 13:58:03
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

struct DsuWithRollback {
    int n, comp;
    vector<int> par, rank;
    vector<tuple<int, int, int, int>> history;
    DsuWithRollback() {}
    DsuWithRollback(int _n): n(_n), comp(n), par(n), rank(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int v) {
        while (v != par[v]) {
            v = par[v];
        }
        return v;
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        --comp;
        if (rank[u] < rank[v]) swap(u, v);
        history.emplace_back(u, rank[u], v, rank[v]);
        par[v] = u;
        if (rank[u] == rank[v]) ++rank[u];
        return true;
    }
    int snapshot() { return history.size(); }
    void rollback(int until) {
        while (snapshot() > until) {
            auto [u, rank_u, v, rank_v] = history.back();
            history.pop_back();
            ++comp;
            par[u] = u;
            par[v] = v;
            rank[u] = rank_u;
            rank[v] = rank_v;
        }
    }
};

struct Query {
    int u, v;
    Query() {}
    Query(int _u, int _v): u(_u), v(_v) {}
};

struct QueryTree {
    int q;
    vector<vector<Query>> tree;
    DsuWithRollback dsu;
    QueryTree() {}
    QueryTree(int _n, int _q): q(_q), dsu(_n) {
        int p = 1;
        while (p < q) p *= 2;
        tree.resize(p * 2);
    }
    void add_query(int x, int l, int r, int u, int v, const Query &query) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            tree[x].emplace_back(query);
            return;
        }
        int mid = l + (r - l) / 2;
        add_query(x * 2, l, mid, u, v, query);
        add_query(x * 2 + 1, mid + 1, r, u, v, query);
    }
    void add_query(int u, int v, const Query &query) {
        add_query(1, 0, q - 1, u, v, query);
    }
    void dfs(int x, int l, int r, vector<int> &ans) {
        int snapshot = dsu.snapshot();
        for (const Query &query : tree[x]) {
            dsu.unite(query.u, query.v);
        }
        if (l == r) {
            ans[l] = dsu.comp;
        } else {
            int mid = l + (r - l) / 2;
            dfs(x * 2, l, mid, ans);
            dfs(x * 2 + 1, mid + 1, r, ans);
        }
        dsu.rollback(snapshot);
    }
    vector<int> solve() {
        vector<int> ans(q);
        dfs(1, 0, q - 1, ans);
        return ans;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, m, q;
    cin >> n >> m >> q;
    map<pair<int, int>, int> added_index;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (u > v) swap(u, v);
        added_index[{u, v}] = 0;
    }
    QueryTree tree(n, q + 2);
    for (int w = 1; w <= q; ++w) {
        int t, u, v;
        cin >> t >> u >> v;
        --u; --v;
        if (u > v) swap(u, v);
        if (t == 1) {
            added_index[{u, v}] = w;
        } else if (t == 2) {
            tree.add_query(added_index[{u, v}], w - 1, Query(u, v));
            added_index[{u, v}] = -1;
        } else assert(false);
    }

    // add all remaining edges
    for (auto [edge, idx] : added_index) {
        if (idx != -1) {
            tree.add_query(idx, q + 1, Query(edge.first, edge.second));
        }
    }
    vector<int> ans = tree.solve();
    for (int i = 0; i < (int) ans.size() - 1; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
