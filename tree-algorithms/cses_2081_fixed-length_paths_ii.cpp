/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-08-21 22:21:01
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

template<typename T>
struct Fenwick {
    int n;
    vector<T> tree;
    Fenwick() {}
    Fenwick(int _n): n(_n), tree(n) {}
    void add(int i, T val) {
        while (i < n) {
            tree[i] += val;
            i |= (i + 1);
        }
    }
    T pref(int i) {
        T res{};
        while (i >= 0) {
            res += tree[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    T query(int l, int r) {
        return pref(r) - pref(l - 1);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int root = 0;
    vector<int> sz(n);
    vector<bool> vis(n);
    auto dfs_sz = [&](auto &&self, int u, int par = -1) -> void {
        sz[u] = 1;
        for (int v : g[u]) {
            if (v == par || vis[v]) continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
    };  
    auto find = [&](auto &&self, int u, int s, int par = -1) -> int {
        for (int v : g[u]) {
            if (v == par || vis[v]) continue;
            if (sz[v] * 2 > s) return self(self, v, s, u);
        }
        return u;
    };

    vector<int> dists, ndists;
    Fenwick<int> tree(n);
    auto dfs_dist = [&](auto &&self, int u, int d, int par = -1) -> void {
        if (d > k2) return;
        ndists.emplace_back(d);
        for (int v : g[u]) {
            if (v == par || vis[v]) continue;
            self(self, v, d + 1, u);
        }
    };

    long long ans = 0;
    auto solve = [&](auto &&self, int u) -> void {
        dfs_sz(dfs_sz, u);
        int c = find(find, u, sz[u]);
        vis[c] = true;

        dists.clear();
        tree.add(0, 1);
        dists.emplace_back(0);
        for (int v : g[c]) {
            if (vis[v]) continue;
            ndists.clear();
            dfs_dist(dfs_dist, v, 1);
            for (int d : ndists) {
                int l = max(0, k1 - d);
                int r = max(0, k2 - d);
                assert(0 <= l && l <= r && r < n);
                ans += tree.query(l, r);
            }
            for (int d : ndists) {
                dists.emplace_back(d);
                tree.add(d, 1);
            }
        }
        for (int d : dists) {
            tree.add(d, -1);
        }
        for (int v : g[c]) {
            if (vis[v]) continue;
            self(self, v);
        }
    };
    solve(solve, root);
    cout << ans << '\n';
    
    return 0;
}
