/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 08:52:14
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

template<typename T>
struct Fenwick {
    int n;
    vector<T> tree;
    Fenwick(int _n): n(_n), tree(_n) {}
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
    T query(int l, int r) { return pref(r) - pref(l - 1); }    
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<long long> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> tin(n), tout(n);
    int timer = 0;
    vector<int> who(n);
    vector<long long> dist_to_root = vals;
    auto dfs = [&](auto &&self, int u, int par = -1) -> void {
        tin[u] = timer;
        who[timer] = u; ++timer;
        for (int v : g[u]) {
            if (v != par) {
                dist_to_root[v] += dist_to_root[u];
                self(self, v, u);
            }
        }
        tout[u] = timer - 1;
    };
    int root = 0;
    dfs(dfs, root);

    Fenwick<long long> tree(n);
    for (int i = 0; i < n; ++i) {
        int prev = (tin[i] > 0 ? who[tin[i] - 1] : -1);
        long long diff = dist_to_root[i] - (prev >= 0 ? dist_to_root[prev] : 0);
        tree.add(tin[i], diff);
    }

    for (int w = 0; w < q; ++w) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, new_val;
            cin >> u >> new_val;
            --u;
            long long delta = new_val - vals[u];
            vals[u] = new_val;
            tree.add(tin[u], delta);
            tree.add(tout[u] + 1, -delta);
        } else if (t == 2) {
            int u;
            cin >> u;
            --u;
            cout << tree.pref(tin[u]) << '\n';
        } else assert(false);
    }
    return 0;
}
