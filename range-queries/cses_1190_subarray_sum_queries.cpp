/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 10:58:20
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
    long long prefix;
    long long suffix;
    long long sum;
    long long best;
    Node(long long val) {
        long long nval = max(0LL, val);
        prefix = suffix = best = nval;
        sum = val;
    }
    Node(long long _prefix = 0, long long _suffix = 0, long long _sum = 0, long long _best = 0): 
        prefix(_prefix), suffix(_suffix), sum(_sum), best(_best) {}
    Node operator+(const Node &other) const {
        Node ans;
        ans.sum = sum + other.sum;
        ans.prefix = max(prefix, sum + other.prefix);
        ans.suffix = max(other.suffix, suffix + other.sum);
        ans.best = max({best, other.best, suffix + other.prefix});
        return ans;
    }
};

struct SegTree {
    int n;
    vector<Node> tree;
    Node DUMMY = Node(0, 0, 0, 0);
    SegTree(int _n): n(_n) {
        int p = 1;
        while (p < n) p *= 2;
        tree.resize(p * 2, DUMMY);
    }
    void pull(int x) { tree[x] = tree[x * 2] + tree[x * 2 + 1]; }
    void set(int x, int l, int r, int pos, int val) {
        if (l == r) {
            auto nval = max(0, val);
            tree[x] = Node(nval, nval, val, nval);
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
        auto lhs = query(x * 2, l, mid, u, v);
        auto rhs = query(x * 2 + 1, mid + 1, r, u, v);
        return lhs + rhs;
    }
    long long query(int u, int v) {
        return query(1, 0, n - 1, u, v).best;
    }

    long long query_all() {
        return tree[1].best;
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
        int pos, val;
        cin >> pos >> val;
        --pos;
        tree.set(pos, val);
        cout << tree.query_all() << '\n';
    }
    
    return 0;
}
