/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 13:48:40
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

struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick() {}
    Fenwick(int _n): n(_n), tree(_n) {}
    void add(int i, int val) {
        while (i < n) {
            tree[i] += val;
            i |= (i + 1);
        }
    }
    int pref(int i) {
        int res{};
        while (i >= 0) {
            res += tree[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    int query(int l, int r) {
        return pref(r) - pref(l - 1);
    }
};  

struct Fenwick2D {
    int n, m;
    vector<Fenwick> tree;
    Fenwick2D() {}
    Fenwick2D(int _n, int _m): n(_n), m(_m) {
        tree.resize(n, Fenwick(m));
    }
    void add(int i, int j, int val) {
        while (i < n) {
            tree[i].add(j, val);
            i |= (i + 1);
        }
    }
    int pref(int i, int j) {
        int res{};
        while (i >= 0) {
            res += tree[i].pref(j);
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    int query(int r, int c, int rr, int cc) {
        return pref(rr, cc) - pref(r - 1, cc) - pref(rr, c - 1) + pref(r - 1, c - 1);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    Fenwick2D tree(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') {
                tree.add(i, j, 1);
            }
        }
    }
    for (int w = 0; w < q; ++w) {
        int t;
        cin >> t;
        if (t == 1) {
            int r, c;
            cin >> r >> c;
            --r; --c;
            grid[r][c] ^= '*' ^ '.';
            tree.add(r, c, grid[r][c] == '*' ? 1 : -1);
        }
        else if (t == 2) {
            int r, c, rr, cc;
            cin >> r >> c >> rr >> cc;
            --r; --c; --rr; --cc;
            cout << tree.query(r, c, rr, cc) << '\n';
        }
        else assert(false);
    }
    
    return 0;
}
