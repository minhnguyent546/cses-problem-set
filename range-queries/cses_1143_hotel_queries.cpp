/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-08-04 21:17:10
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
    void pull(int x) { tree[x] = max(tree[x * 2], tree[x * 2 + 1]); }
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
    int lower_bound(int x, int l, int r, int target) {
        if (l == r) {
            assert(tree[x] >= target);
            return l;
        }
        int mid = l + (r - l) / 2;
        if (tree[x * 2] >= target) return lower_bound(x * 2, l, mid, target);
        return lower_bound(x * 2 + 1, mid + 1, r, target);
    }
    int lower_bound(int target) {
        return lower_bound(1, 0, n - 1, target);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;    
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    SegTree tree(n + 1);
    for (int i = 0; i < n; ++i) {
        tree.add(i, h[i]);
    }
    tree.add(n, INF);
    for (int i = 0; i < m; ++i) {
        int target;
        cin >> target;
        int pos = tree.lower_bound(target);
        if (pos == n) cout << 0 << ' ';
        else {
            cout << pos + 1 << ' ';
            tree.add(pos, -target);
        }
    }
    cout << '\n';
    
    return 0;
}
