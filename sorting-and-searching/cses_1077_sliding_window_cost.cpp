/**            
 * author      minhnguyent546
 * created_at  Sun, 2024-07-21 16:06:16
 **/           
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename key_type>
using ordered_multiset = tree<key_type, null_type, less_equal<key_type>, rb_tree_tag,
    tree_order_statistics_node_update>;

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
    Fenwick() {}
    Fenwick(int _n): n(_n), tree(_n) {}
    void add(int i, T value) {
        while (i < n) {
            tree[i] += value;
            i |= (i + 1);
        }
    }
    T prefix(int i) {
        T res = 0;
        while (i >= 0) {
            res += tree[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    T query(int l, int r) {
        if (l > r) return 0;
        return prefix(r) - prefix(l - 1);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> all = arr;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    vector<int> index(n);
    for (int i = 0; i < n; ++i) {
        index[i] = (int) (lower_bound(all.begin(), all.end(), arr[i]) - all.begin());
    }
    ordered_multiset<int> s;
    Fenwick<int> tree_cnt(n);
    Fenwick<long long> tree_value(n);
    for (int i = 0; i < n; ++i) {
        s.insert(arr[i]);
        tree_cnt.add(index[i], 1);
        tree_value.add(index[i], arr[i]);
        if (i + 1 >= k) {
            int median = *s.find_by_order((k - 1) / 2);
            int median_index = (int) (lower_bound(all.begin(), all.end(), median) - all.begin());
            // debug(i, median, median_index);
            int gt = tree_cnt.query(median_index + 1, n - 1);
            int lt = tree_cnt.query(0, median_index - 1);
            long long sum_gt = tree_value.query(median_index + 1, n - 1);
            long long sum_lt = tree_value.query(0, median_index - 1);
            long long cost = sum_gt - 1LL * gt * median + 1LL * lt * median - sum_lt;
            cout << cost << ' ';
            s.erase(s.upper_bound(arr[i + 1 - k]));
            tree_cnt.add(index[i + 1 - k], -1);
            tree_value.add(index[i + 1 - k], -arr[i + 1 - k]);
        }
    }
    cout << '\n';
    
    return 0;
}
