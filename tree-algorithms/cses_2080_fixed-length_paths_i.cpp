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


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
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

    vector<int> dists, ndists, cnt(n);
    auto dfs_dist = [&](auto &&self, int u, int d, int par = -1) -> void {
        if (d > k) return;
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
        cnt[0] = 1;
        dists.emplace_back(0);
        for (int v : g[c]) {
            if (vis[v]) continue;
            ndists.clear();
            dfs_dist(dfs_dist, v, 1);
            for (int d : ndists) {
                int rem = k - d;
                assert(0 <= rem && rem < n);
                ans += cnt[rem];
            }
            for (int d : ndists) {
                dists.emplace_back(d);
                ++cnt[d];
            }
        }
        for (int d : dists) {
            --cnt[d];
            assert(cnt[d] >= 0);
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
