/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 20:35:07
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
 
struct SegTree {
    int n;
    vector<int> tree;
    SegTree() {}
    SegTree(int _n): n(_n), tree(n * 2) {}
    int merge(const int &lhs, const int &rhs) { return max(lhs, rhs); }
    void pull(int x) { tree[x] = merge(tree[x * 2], tree[x * 2 + 1]); }
    void set(int i, int val) {
        tree[i += n] = val;
        for (i /= 2; i; i /= 2) {
            pull(i);
        }
    }
    int query(int l, int r) {
        assert(l <= r);
        int res = -INF;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) res = merge(res, tree[l++]);
            if (r & 1) res = merge(res, tree[--r]);
        }
        return res;
    }
};
 
struct HLD {
    int n;
    vector<vector<int>> g;
    vector<int> par, depth, top, sz, id;
    SegTree segtree;
    int timer = 0;
    int root = 0;
    HLD() {}
    HLD(int _n): n(_n), g(n), par(n), depth(n), top(n), sz(n), id(n), segtree(n) {}
    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    void build() {
        dfs_sz(root);
        dfs_hld(root);
    }
    void dfs_sz(int u) {
        sz[u] = 1;
        for (int &v : g[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            g[v].erase(find(g[v].begin(), g[v].end(), u));
            dfs_sz(v);
            sz[u] += sz[v];
            if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
        }  
    }
    void dfs_hld(int u) {
        id[u] = timer++;
        for (int v : g[u]) {
            top[v] = (v == g[u][0] ? top[u] : v);
            dfs_hld(v);
        }
    }
    void set_vertex(int u, int val) {
        segtree.set(id[u], val);
    }
    int query_max(int u, int v) {
        int res = -INF;
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]]) swap(u, v);
            int cur = segtree.query(id[top[u]], id[u]);
            res = max(res, cur);
            u = par[top[u]];
        }
        if (depth[u] < depth[v]) swap(u, v);
        int cur = segtree.query(id[v], id[u]);
        res = max(res, cur);
        return res;
    }   
};
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    HLD hld(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        hld.add_edge(u, v);
    }
    hld.build();
    for (int i = 0; i < n; ++i) {
        hld.set_vertex(i, vals[i]);
    } 
    for (int w = 0; w < q; ++w) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, val;
            cin >> u >> val;
            --u;
            hld.set_vertex(u, val);
        } else if (t == 2) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            cout << hld.query_max(u, v) << ' ';
        } else assert(false);
    }
    cout << '\n';
    
    return 0;
}
