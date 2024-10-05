/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-09-28 21:18:48
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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<vector<long long>> pref(n + 1, vector<long long>(n + 1));
    vector<vector<long long>> suf(n + 1, vector<long long>(n + 2));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            pref[i + 1][j + 1] = pref[i + 1][j] + arr[j];
        }
        for (int j = i; j < n; ++j) {
            pref[i + 1][j + 1] += pref[i + 1][j];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
            suf[i + 1][j + 1] = suf[i + 1][j + 2] + arr[j];
        }
        for (int j = i - 1; j >= 0; --j) {
            suf[i + 1][j + 1] += suf[i + 1][j + 2];
        }
    }

    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<vector<long long>> cost(n, vector<long long>(n));
    auto dnc_cost = [&](auto &&self, int i, int l, int r, int opt_l, int opt_r) -> void {
        if (l > r) return;
        int mid = l + (r - l) / 2;
        long long best = INF;
        int opt = l;
        for (int j = opt_l; j <= min(opt_r, mid); ++j) {
            // pref: [i, j - 1]
            // suf: [j + 1, mid]
            long long cur_cost = pref[i + 1][j] + suf[mid + 1][j + 2];
            if (cur_cost < best) {
                best = cur_cost;
                opt = j;
            }
        }
        cost[i][mid] = best;
        self(self, i, l, mid - 1, opt_l, opt);
        self(self, i, mid + 1, r, opt, opt_r);
    };
    for (int i = 0; i < n; ++i) {
        dnc_cost(dnc_cost, i, i, n - 1, i, n - 1);
    }

    vector<long long> dp(n + 1, INF);
    vector<long long> ndp(n + 1, INF);
    dp[0] = 0;
    auto dnc = [&](auto &&self, int l, int r, int opt_l, int opt_r) -> void {
        if (l > r) return;
        int mid = l + (r - l) / 2;
        long long best = INF;
        int opt = l;
        for (int j = opt_l; j <= min(mid, opt_r); ++j) {
            long long cur_cost = cost[j - 1][mid - 1] + dp[j - 1];
            if (best > cur_cost) {
                best = cur_cost;
                opt = j;
            }
        }
        ndp[mid] = best;
        self(self, l, mid - 1, opt_l, opt);
        self(self, mid + 1, r, opt, opt_r);
    };
    for (int i = 1; i <= k; ++i) {
        dnc(dnc, 1, n, 1, n);
        dp.swap(ndp);
    }
    cout << dp[n] << '\n';
    
    
    return 0;
}
