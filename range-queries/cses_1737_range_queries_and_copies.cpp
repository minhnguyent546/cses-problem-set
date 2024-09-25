/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-08-14 22:40:06
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

struct Node {
    int lc, rc;
    long long val;
    Node() {}
    Node(int _l, int _r, long long _val): lc(_l), rc(_r), val(_val) {}
};

struct Segtree {
    int n;
    vector<Node> tree;
    Segtree() {}
    Segtree(int _n): n(_n) {}
    int build(const vector<int> &arr) {
        return build(arr, 0, n - 1);
    }
    int build(const vector<int> &arr, int l, int r) {
        if (l == r) {
            tree.emplace_back(-1, -1, arr[l]);
            return tree.size() - 1;
        }
        int mid = l + (r - l) / 2;
        auto lc = build(arr, l, mid);
        auto rc = build(arr, mid + 1, r);
        tree.emplace_back(lc, rc, tree[lc].val + tree[rc].val);
        return tree.size() - 1;
    }
    int set(int x, int l, int r, int pos, int val) {
        if (l == r) {
            tree.emplace_back(-1, -1, val);
            return tree.size() - 1;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            int lc = set(tree[x].lc, l, mid, pos, val);
            tree.emplace_back(lc, tree[x].rc, tree[lc].val + tree[tree[x].rc].val);
        } else {
            int rc = set(tree[x].rc, mid + 1, r, pos, val);
            tree.emplace_back(tree[x].lc, rc, tree[tree[x].lc].val + tree[rc].val);
        }
        return tree.size() - 1; 
    }
    long long query(int x, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return tree[x].val;
        int mid = l + (r - l) / 2;
        auto lhs = query(tree[x].lc, l, mid, u, v);
        auto rhs = query(tree[x].rc, mid + 1, r, u, v);
        return lhs + rhs; 
    }
    
    int set(int x, int pos, int val) {
        return set(x, 0, n - 1, pos, val);
    }
    long long query(int x, int u, int v) {
        return query(x, 0, n - 1, u, v);
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

    Segtree tree(n);
    vector<int> roots;
    roots.emplace_back(tree.build(arr));
    for (int w = 0; w < q; ++w) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, pos, val;
            cin >> k >> pos >> val;
            --k; --pos;
            roots[k] = tree.set(roots[k], pos, val);
        } else if (t == 2) {
            int k, l, r;
            cin >> k >> l >> r;
            --k; --l; --r;
            cout << tree.query(roots[k], l, r) << '\n';
        } else if (t == 3) {
            int k;
            cin >> k;
            --k;
            roots.emplace_back(roots[k]);
        } else assert(false);
    }
    
    return 0;
}
