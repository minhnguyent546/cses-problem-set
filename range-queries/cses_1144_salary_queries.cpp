/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 01:02:45
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
    SegTree(int _n): n(_n) {
        int p = 1;
        while (p < n) p *= 2;
        tree.resize(p * 2);
    }
    void pull(int x) { tree[x] = tree[x * 2] + tree[x * 2 + 1]; }
    void add(int x, int l, int r, int pos, int val) {
        if (l == r) {
            tree[x] += val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) add(x * 2, l, mid, pos, val);
        else add(x * 2 + 1, mid + 1, r, pos, val);
        pull(x);
    }
    void add(int pos, int val) {
        add(1, 0, n - 1, pos, val);
    }
    int query(int x, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) {
            return tree[x];
        }
        int mid = l + (r - l) / 2;
        return query(x * 2, l, mid, u, v) + query(x * 2 + 1, mid + 1, r, u, v);
    }
    int query(int u, int v) {
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
    vector<int> all = arr;
    vector<array<int, 3>> qs(q);
    for (int w = 0; w < q; ++w) {
        char t;
        cin >> t;
        if (t == '!') {
            int pos, val;
            cin >> pos >> val;
            --pos;
            qs[w] = {0, pos, val};
            all.emplace_back(val);
        }
        else if (t == '?') {
            int l, r;
            cin >> l >> r;
            qs[w] = {1, l, r};
        }
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    int m = (int) all.size();
    SegTree tree(m);
    auto get_lower = [&](int val) -> int {
        return (int) (lower_bound(all.begin(), all.end(), val) - all.begin());
    };
    for (int i = 0; i < n; ++i) {
        tree.add(get_lower(arr[i]), 1);
    }
    for (int w = 0; w < q; ++w) {
        int type = qs[w][0];
        if (type == 0) {
            int pos = qs[w][1], val = qs[w][2];
            tree.add(get_lower(arr[pos]), -1);
            tree.add(get_lower(val), 1);
            arr[pos] = val;
        }
        else if (type == 1) {
            int l = qs[w][1], r = qs[w][2];
            int x = get_lower(l);
            int y = get_lower(r + 1) - 1;
            cout << tree.query(x, y) << '\n';
        }
        else assert(false);
    }
    return 0;
}
