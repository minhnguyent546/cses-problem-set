/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-08-04 20:52:07
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
    SegTree() {}
    SegTree(int _n): n(_n), tree(_n * 2) {}
    void pull(int x) {
        tree[x] = min(tree[x * 2], tree[x * 2 + 1]);
    }
    void set(int i, int val) {
        tree[i += n] = val;
        for (i /= 2; i > 0; i /= 2) {
            pull(i);
        }
    }
    int query(int l, int r) {
        int res = INF;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) res = min(res, tree[l++]);
            if (r & 1) res = min(res, tree[--r]);
        }
        return res;
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
    for (int i = 0; i < n; ++i) tree.set(i, arr[i]);
    for (int w = 0; w < q; ++w) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            --pos;
            tree.set(pos, val);
        }
        else if (type == 2) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            cout << tree.query(l, r) << '\n';
        }
        else assert(false);
    }
    
    return 0;
}
