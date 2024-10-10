/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-10-08 21:32:56
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> arr(n);
    int max_v = -1;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        --arr[i].second;
        max_v = max(max_v, arr[i].second);
    }

    vector<int> next_at(max_v + 1, n);
    set<pair<int, int>> st;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return arr[i].first > arr[j].first;
    });

    for (int x = max_v, ptr = 0; x >= 0; --x) {
        while (ptr < n && arr[order[ptr]].first > x) {
            st.emplace(arr[order[ptr]].second, order[ptr]);
            ++ptr;
        }
        next_at[x] = (st.empty() ? n : st.begin()->second);
    }
    vector<int> next(n, n);
    for (int i = 0; i < n; ++i) {
        next[i] = next_at[arr[i].second];
    }

    int max_log = 32 - __builtin_clz(n);
    vector<vector<int>> table(max_log, vector<int>(n));
    table[0] = next;
    for (int j = 1; j < max_log; ++j) {
        for (int i = 0; i < n; ++i) {
            table[j][i] = (table[j - 1][i] < n ? table[j - 1][table[j - 1][i]] : n);
        }
    }

    st.clear();
    vector<tuple<int, int, int>> qs(q);
    vector<int> ans(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --r;
        qs[i] = {l, r, i};
    }
    sort(qs.begin(), qs.end(), [](const auto &lhs, const auto &rhs) {
        return get<0>(lhs) > get<0>(rhs);
    });

    for (int w = 0, ptr = 0; w < q; ++w) {
        auto [l, r, idx] = qs[w];
        while (ptr < n && arr[order[ptr]].first >= l) {
            st.emplace(arr[order[ptr]].second, order[ptr]);
            ++ptr;
        }
        if (st.empty() || st.begin()->first > r) {
            ans[idx] = 0;
            continue;
        }
        int cur_pos = st.begin()->second;
        int cur_ans = 1;
        for (int i = max_log - 1; i >= 0; --i) {
            int next_pos = table[i][cur_pos];
            if (next_pos < n && arr[next_pos].second <= r) {
                cur_pos = next_pos;
                cur_ans += (1 << i);
            }
        }
        ans[idx] = cur_ans;
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }   
    return 0;
}
