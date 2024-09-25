/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 10:23:49
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

struct Node {
    long long pref;
    long long sum;
    Node(long long _pref = 0, long long _sum = 0): pref(_pref), sum(_sum) {}
    Node operator+(const Node &other) const {
        if (sum + other.pref > pref) {
            return Node(sum + other.pref, sum + other.sum);
        }
        return Node(pref, sum + other.sum);
    }
};

struct SegTree {
    int n;
    vector<Node> tree;
    Node DUMMY = Node(0, 0);
    SegTree(int _n): n(_n) {
        int p = 1;
        while (p < n) p *= 2;
        tree.resize(p * 2);
    }
    void pull(int x) { tree[x] = tree[x * 2] + tree[x * 2 + 1]; }
    void set(int x, int l, int r, int pos, int val) {
        if (l == r) {
            tree[x] = Node(max(val, 0), val);
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) set(x * 2, l, mid, pos, val);
        else set(x * 2 + 1, mid + 1, r, pos, val);
        pull(x);
    }
    void set(int pos, int val) {
        set(1, 0, n - 1, pos, val);
    }
    Node query(int x, int l, int r, int u, int v) {
        if (r < u || l > v) return DUMMY;
        if (u <= l && r <= v) {
            return tree[x];
        }
        int mid = l + (r - l) / 2;
        return query(x * 2, l, mid, u, v) + query(x * 2 + 1, mid + 1, r, u, v);
    }
    long long query(int u, int v) {
        Node ans = query(1, 0, n - 1, u, v);
        return ans.pref;
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
    SegTree tree(n);
    for (int i = 0; i < n; ++i) {
        tree.set(i, arr[i]);
    }
    for (int w = 0; w < q; ++w) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            --a;
            tree.set(a, b);
        }
        else if (t == 2) {
            --a; --b;
            cout << tree.query(a, b) << '\n';
        }
        else assert(false);
    }
    
    return 0;
}
