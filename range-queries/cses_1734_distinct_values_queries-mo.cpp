/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 11:22:06
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


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    auto all = arr;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    int sz = (int) all.size();
    for (int i = 0; i < n; ++i) {
        arr[i] = (int) (lower_bound(all.begin(), all.end(), arr[i]) - all.begin());
    }
    const int B = 750;
    vector<pair<int, int>> qs(q);
    for (int i = 0; i < q; ++i) {
        cin >> qs[i].first >> qs[i].second;
        --qs[i].first, --qs[i].second;
    }
    vector<int> order(q);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&qs](int i, int j) {
        auto lhs = qs[i];
        auto rhs = qs[j];
        if (lhs.first / B == rhs.first / B) {
            return lhs.second < rhs.second;
        }
        return lhs.first / B < rhs.first / B;
    });

    vector<int> freq(sz);
    vector<int> ans(q);
    int cur_ans = 0, cur_l = 0, cur_r = -1;
    auto Add = [&](int i) -> void {
        ++freq[arr[i]];
        if (freq[arr[i]] == 1) ++cur_ans;
    };
    auto Remove = [&](int i) -> void {
        --freq[arr[i]];
        if (freq[arr[i]] == 0) --cur_ans;
    };
    for (int oi = 0; oi < q; ++oi) {
        int i = order[oi];
        auto [l, r] = qs[i];
        while (cur_l > l) Add(--cur_l);
        while (cur_r < r) Add(++cur_r);
        while (cur_l < l) Remove(cur_l++);
        while (cur_r > r) Remove(cur_r--);
        ans[i] = cur_ans;
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
