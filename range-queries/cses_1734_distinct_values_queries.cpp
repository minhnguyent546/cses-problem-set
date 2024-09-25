/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 13:18:25
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
    T DUMMY = 0;
    SegTree(int _n): n(_n) {
        int p = 1;
        while (p < n) p *= 2;
        tree.resize(p * 2, DUMMY);
    }
    void pull(int x) { tree[x] = tree[x * 2] + tree[x * 2 + 1]; }
    void add(int x, int l, int r, int pos, T val) {
        if (l == r) {
            tree[x] += val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) add(x * 2, l, mid, pos, val);
        else add(x * 2 + 1, mid + 1, r, pos, val);
        pull(x);
    }
    void add(int pos, T val) {
        add(1, 0, n - 1, pos, val);
    }
    T query(int x, int l, int r, int u, int v) {
        if (r < u || l > v) return DUMMY;
        if (u <= l && r <= v) {
            return tree[x];
        }
        int mid = l + (r - l) / 2;
        auto lhs = query(x * 2, l, mid, u, v);
        auto rhs = query(x * 2 + 1, mid + 1, r, u, v);
        return lhs + rhs;
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
    vector<int> left(n, -1);
    map<int, int> latest;
    for (int i = 0; i < n; ++i) {
        if (latest.find(arr[i]) != latest.end()) {
            left[i] = latest[arr[i]];
        }
        latest[arr[i]] = i;
    }
    vector<array<int, 3>> qs(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        qs[i] = {l, r, i};
    }
    sort(qs.begin(), qs.end(), [](const auto &lhs, const auto &rhs) {
        return lhs[0] < rhs[0];
    });
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return left[i] < left[j];
    });
    SegTree<int> tree(n);
    vector<int> ans(q);
    for (int w = 0, ptr = 0; w < q; ++w) {
        auto [l, r, idx] = qs[w];
        while (ptr < n && left[order[ptr]] < l) {
            tree.add(order[ptr], 1);
            ++ptr;
        }
        ans[idx] = tree.query(l, r);
    }       
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
