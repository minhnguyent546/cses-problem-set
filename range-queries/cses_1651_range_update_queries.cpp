/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-08-04 20:57:40
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
struct Fenwick {
    int n;
    vector<T> tree;
    Fenwick(int _n): n(_n), tree(_n) {}
    void _add(int i, T val) {
        while (i < n) {
            tree[i] += val;
            i |= (i + 1);
        }
    }
    T get(int i) {
        T res{};
        while (i >= 0) {
            res += tree[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    void add(int l, int r, T val) {
        _add(l, val);
        _add(r + 1, -val);
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
    Fenwick<long long> tree(n);
    for (int i = 0; i < n; ++i) {
        int val = arr[i] - (i > 0 ? arr[i - 1] : 0);
        tree._add(i, val);
    }
    for (int w = 0; w < q; ++w) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, amt;
            cin >> l >> r >> amt;
            --l; --r;
            tree.add(l, r, amt);
        }
        else if (t == 2) {
            int pos;
            cin >> pos;
            --pos;
            cout << tree.get(pos) << '\n';
        }
        else assert(false);
    }
    
    return 0;
}
