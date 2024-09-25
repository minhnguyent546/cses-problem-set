/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 13:56:57
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
struct SegTree {
    int n;
    vector<T> tree;
    vector<T> lazy_add;
    vector<T> lazy_set;
    T DUMMY{};
    SegTree() {}
    SegTree(int _n): n(_n) {
        int p = 1; while (p < n) p *= 2;
        tree.resize(p * 2, DUMMY);
        lazy_add.resize(p * 2);
        lazy_set.resize(p * 2);
    }
    T merge(const T &lhs, const T &rhs) { return lhs + rhs; }
    void pull(int x) { tree[x] = merge(tree[x * 2], tree[x * 2 + 1]); }
    void push(int x, int l, int r) {
        if (lazy_add[x] == 0 && lazy_set[x] == 0) return;
        int mid = l + (r - l) / 2;
        if (lazy_set[x] > 0) {
            tree[x * 2] = (mid - l + 1) * lazy_set[x]; 
            lazy_set[x * 2] = lazy_set[x];
            lazy_add[x * 2] = 0;

            tree[x * 2 + 1] = (r - mid) * lazy_set[x]; 
            lazy_set[x * 2 + 1] = lazy_set[x];
            lazy_add[x * 2 + 1] = 0;
        }
        if (lazy_add[x] > 0) {
            tree[x * 2] += (mid - l + 1) * lazy_add[x];
            lazy_add[x * 2] += lazy_add[x];

            tree[x * 2 + 1] += (r - mid) * lazy_add[x];
            lazy_add[x * 2 + 1] += lazy_add[x];
        }

        lazy_set[x] = lazy_add[x] = 0;
    }
    void add(int x, int l, int r, int u, int v, T amt) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            tree[x] += (r - l + 1) * amt;
            lazy_add[x] += amt;
            return;
        }
        int mid = l + (r - l) / 2;
        push(x, l, r);
        add(x * 2, l, mid, u, v, amt);
        add(x * 2 + 1, mid + 1, r, u, v, amt);
        pull(x);
    }
    void add(int u, int v, T amt) {
        add(1, 0, n - 1, u, v, amt);
    }
    void set(int x, int l, int r, int u, int v, T val) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            tree[x] = (r - l + 1) * val;
            lazy_set[x] = val;
            lazy_add[x] = 0;
            return;
        }
        int mid = l + (r - l) / 2;
        push(x, l, r);
        set(x * 2, l, mid, u, v, val);
        set(x * 2 + 1, mid + 1, r, u, v, val);
        pull(x);
    }
    void set(int u, int v, T val) {
        set(1, 0, n - 1, u, v, val);
    }
    T query(int x, int l, int r, int u, int v) {
        if (r < u || l > v) return DUMMY;
        if (u <= l && r <= v) {
            return tree[x];
        }
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
    SegTree<long long> tree(n);
    for (int i = 0; i < n; ++i) {
        tree.add(i, i, arr[i]);
    }
    for (int w = 0; w < q; ++w) {
        int t, l, r;
        cin >> t >> l >> r;
        --l; --r;
        if (t == 1) {
            int x;
            cin >> x;
            tree.add(l, r, x);
        }
        else if (t == 2) {
            int x;
            cin >> x;
            tree.set(l, r, x);
        }
        else if (t == 3) {
            cout << tree.query(l, r) << '\n';
        }
        else assert(false);
    }
    
    return 0;
}
