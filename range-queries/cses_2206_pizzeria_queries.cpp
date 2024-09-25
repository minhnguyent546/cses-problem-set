/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 10:40:43
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
    T DUMMY = numeric_limits<T>::max();
    SegTree(int _n): n(_n) {
        int p = 1;
        while (p < n) p *= 2;
        tree.resize(p * 2, DUMMY);
    }
    T merge(const T &lhs, const T &rhs) { return min(lhs, rhs); }
    void pull(int x) { tree[x] = merge(tree[x * 2], tree[x * 2 + 1]); }
    void set(int x, int l, int r, int pos, T val) {
        if (l == r) {
            tree[x] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) set(x * 2, l, mid, pos, val);
        else set(x * 2 + 1, mid + 1, r, pos, val);
        pull(x);
    }
    void set(int pos, T val) {
        set(1, 0, n - 1, pos, val);
    }
    T query(int x, int l, int r, int u, int v) {
        if (r < u || l > v) return DUMMY;
        if (u <= l && r <= v) {
            return tree[x];
        }
        int mid = l + (r - l) / 2;
        auto lhs = query(x * 2, l, mid, u, v);
        auto rhs = query(x * 2 + 1, mid + 1, r, u, v);
        return merge(lhs, rhs);
    }
    T query(int u, int v) {
        return query(1, 0, n - 1, u, v);
    }

    void print(int x, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            print(x * 2, l, mid);
            print(x * 2, mid + 1, r);
        }
    }
    void print() {
        print(1, 0, n - 1);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    SegTree<int> tree1(n), tree2(n);
    for (int i = 0; i < n; ++i) {
        tree1.set(i, prices[i] - i);
        tree2.set(i, prices[i] + i);
    }
    for (int w = 0; w < q; ++w) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos, val;
            cin >> pos >> val;
            --pos;
            tree1.set(pos, val - pos);
            tree2.set(pos, val + pos);
        }
        else if (t == 2) {
            int pos;
            cin >> pos;
            --pos;
            int ans = INF;
            ans = min(ans, tree1.query(0, pos) + pos);
            ans = min(ans, tree2.query(pos, n - 1) - pos);
            cout << ans << '\n';
        }
        else assert(false);
    }
    
    return 0;
}
