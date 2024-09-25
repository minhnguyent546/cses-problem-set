/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-08-06 09:53:32
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

long long sum(int n) {
    if (n <= 0) return 0;
    return 1LL * n * (n + 1) / 2;
}

template<typename T>
struct SegTree {
    int n;
    vector<T> tree;
    vector<T> lazy;
    bool add_by_index;
    T DUMMY = 0;
    SegTree(int _n, bool _add_by_index = false): n(_n), add_by_index(_add_by_index) {
        int p = 1; while (p < n) p *= 2;
        tree.resize(p * 2, DUMMY);
        lazy.resize(p * 2);
    }
    T merge(const T &lhs, const T &rhs) { return lhs + rhs; }
    void pull(int x) { tree[x] = merge(tree[x * 2], tree[x * 2 + 1]); }
    void push(int x, int l, int r) {
        if (lazy[x] == 0) return;
        int mid = l + (r - l) / 2;
        if (add_by_index) {
            tree[x * 2] += (sum(mid) - sum(l - 1)) * lazy[x];
            tree[x * 2 + 1] += (sum(r) - sum(mid)) * lazy[x];
        } 
        else {
            tree[x * 2] += (mid - l + 1) * lazy[x];
            tree[x * 2 + 1] += (r - mid) * lazy[x];
        }
        lazy[x * 2] += lazy[x];
        lazy[x * 2 + 1] += lazy[x];

        lazy[x] = 0;
    }
    void add(int x, int l, int r, int u, int v, T amt) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            if (add_by_index) {
                tree[x] += sum(r) - sum(l - 1);
                lazy[x]++;
            }
            else {
                tree[x] += (r - l + 1) * amt;
                lazy[x] += amt;
            }
            return;
        }
        int mid = l + (r - l) / 2;
        push(x, l, r);
        add(x * 2, l, mid, u, v, amt);
        add(x * 2 + 1, mid + 1, r, u, v, amt);
        pull(x);
    }
    void add(int u, int v, int amt = 0) {
        add(1, 0, n - 1, u, v, amt);
    }
    T query(int x, int l, int r, int u, int v) {
        if (r < u || l > v) return DUMMY;
        if (u <= l && r <= v) return tree[x];
        int mid = l + (r - l) / 2;
        push(x, l, r);
        auto lhs = query(x * 2, l, mid, u, v);
        auto rhs = query(x * 2 + 1, mid + 1, r, u, v);
        return merge(lhs, rhs);
    }
    T query(int u, int v) {
        return query(1, 0, n - 1, u, v);
    }

};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    SegTree<long long> tree1(n), tree2(n, true);
    for (int i = 0; i < n; ++i) {
        tree1.add(i, i, arr[i]);
    }
    for (int w = 0; w < q; ++w) {
        int t, l, r;
        cin >> t >> l >> r;
        --l; --r;
        if (t == 1) {
            tree1.add(l, r, 1 - l);
            tree2.add(l, r);
        } else if (t == 2) {
            long long ans1 = tree1.query(l, r);
            long long ans2 = tree2.query(l, r);
            cout << ans1 + ans2 << '\n';
        } else assert(false);
    }
    
    return 0;
}
