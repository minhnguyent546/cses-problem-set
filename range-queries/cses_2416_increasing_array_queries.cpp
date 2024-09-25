/**            
 * author      minhnguyent546
 * created_at  Tue, 2024-08-06 23:54:48
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


vector<int> closest_upper_rigth(const vector<int> &arr) {
    int n = (int) arr.size();
    vector<int> right(n), stk;
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && arr[stk.back()] <= arr[i]) stk.pop_back();
        right[i] = (stk.empty() ? n : stk.back());
        stk.emplace_back(i);
    }
    return right;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + arr[i];
    }
    auto get_sum = [&](int l, int r) {
        assert(0 <= l && l <= r && r < n);
        return pref[r + 1] - pref[l];
    };

    auto upper_right = closest_upper_rigth(arr);
    const int LOG = 32 - __builtin_clz(n);
    vector nxt(LOG, vector<int>(n));
    vector cost(LOG, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        nxt[0][i] = upper_right[i];
        cost[0][i] = 1LL * (upper_right[i] - i) * arr[i] - get_sum(i, upper_right[i] - 1);
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            nxt[j][i] = (nxt[j - 1][i] < n ? nxt[j - 1][nxt[j - 1][i]] : n);
            if (nxt[j - 1][i] < n) {
                cost[j][i] = cost[j - 1][i] + cost[j - 1][nxt[j - 1][i]];
            }
        }   
    }
    
    for (int w = 0; w < q; ++w) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        int x = l;
        long long ans = 0;
        for (int j = LOG - 1; j >= 0; --j) {
            int par = nxt[j][x];
            if (par <= r) {
                ans += cost[j][x];
                x = par;
            }
        }
        assert(upper_right[x] > r);
        ans += 1LL * (r - x + 1) * arr[x] - get_sum(x, r);
        cout << ans << '\n';
    }
    return 0;
}
