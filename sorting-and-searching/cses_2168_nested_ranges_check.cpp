/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-07-16 15:39:36
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
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
        int res = 0;
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> segments;
    vector<int> all;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        segments.emplace_back(a, b);
        all.emplace_back(a);
        all.emplace_back(b);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 0; i < n; ++i) {
        segments[i].first = (int) (lower_bound(all.begin(), all.end(), segments[i].first) - all.begin());
        segments[i].second = (int) (lower_bound(all.begin(), all.end(), segments[i].second) - all.begin());
    }
    Fenwick tree = Fenwick(n * 2);
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&segments](int i, int j) {
        if (segments[i].second == segments[j].second) {
            return segments[i].first > segments[j].first;
        }
        return segments[i].second < segments[j].second;
    });
    for (int i = 0; i < n; ++i) {
    }
    vector<int> num_contains(n), num_covered(n);
    for (int i = 0; i < n; ++i) {
        auto [l, r] = segments[order[i]];
        int cnt = tree.query(l, 2 * n - 1);
        num_contains[order[i]] = cnt;
        tree.add(l, 1);
    }

    tree = Fenwick(n * 2);
    for (int i = n - 1; i >= 0; --i) {
        auto [l, r] = segments[order[i]];
        int cnt = tree.query(0, l);
        num_covered[order[i]] = cnt;
        tree.add(l, 1);
    }

    for (int i = 0; i < n; ++i) {
        cout << (num_contains[i] > 0) << ' ';
    }
    cout << '\n';

    for (int i = 0; i < n; ++i) {
        cout << (num_covered[i] > 0) << ' ';
    }
    cout << '\n';

    
    return 0;
}
