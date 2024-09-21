/**            
 * author      minhnguyent546
 * created_at  Fri, 2024-09-20 13:20:02
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

template<typename T>
struct Fenwick {
    int n;
    vector<T> tree;
    Fenwick() {}
    Fenwick(int _n): n(_n), tree(n) {}
    void add(int i, T val) {
        while (i < n) {
            tree[i] += val;
            i |= (i + 1);
        }
    }
    T pref(int i) {
        T res{};
        while (i >= 0) {
            res += tree[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    T query(int l, int r) {
        return pref(r) - pref(l - 1);
    }
    pair<int, T> lower_bound(T k) {
        int x = 0;
        T sum{};
        for (int i = 1 << __lg(n); i > 0; i /= 2) {
            if (x + i - 1 < n && sum + tree[x + i - 1] < k) {
                sum += tree[x + i - 1];
                x += i;
            }
        }
        return pair{x, sum};
    }
    int next(int i) {
        T cur_pref = pref(i);
        auto [pos, sum] = lower_bound(cur_pref + 1);
        if (pos == n) {
            auto [pos2, sum2] = lower_bound(1);
            return pos2;
        } else {
            return pos;
        }
    }
};

int main() {
    #ifdef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
    #endif
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
    k += 1;
    int sz = n;
    Fenwick<int> tree(n);
    for (int i = 0; i < n; ++i) {
        tree.add(i, 1);
    }
    for (int iter = 0, ptr = 0; iter < n; ++iter, --sz) {
        int kth = k % sz;
        if (kth == 0) kth = sz;
        int cur_pref = tree.pref(ptr);
        auto [pos, sum] = tree.lower_bound(cur_pref + kth - 1);
        if (pos == n) {
            auto [pos2, sum2] = tree.lower_bound(cur_pref + kth - 1 - sum);
            cout << pos2 + 1 << ' ';
            tree.add(pos2, -1);
            ptr = tree.next(pos2);
        } else {
            cout << pos + 1 << ' ';
            tree.add(pos, -1);
            ptr = tree.next(pos);
        }
    }
    cout << '\n';    
    return 0;
}
