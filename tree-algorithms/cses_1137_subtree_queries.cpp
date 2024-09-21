/**            
 * author      minhnguyent546
 * created_at  Thu, 2024-08-08 12:17:45
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
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> tin(n), tout(n);
    int timer = 0;
    int root = 0;
    auto dfs = [&](auto &&self, int u, int par = -1) -> void {
        tin[u] = timer++;
        for (int v : g[u]) {
            if (v != par) {
                self(self, v, u);
            }
        }
        tout[u] = timer - 1;
    };  
    dfs(dfs, root);
    Fenwick<long long> tree(n);
    for (int i = 0; i < n; ++i) {
        tree.add(tin[i], vals[i]);
    }
    for (int w = 0; w < q; ++w) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, val;
            cin >> u >> val;
            --u;
            tree.add(tin[u], val - vals[u]);
            vals[u] = val;
        }
        else if (t == 2) {
            int u;
            cin >> u;
            --u;
            cout << tree.query(tin[u], tout[u]) << '\n';
        }
        else assert(false);
    }
    
    return 0;
}
