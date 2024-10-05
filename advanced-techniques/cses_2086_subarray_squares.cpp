/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-09-28 16:42:20
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
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + arr[i];
    }

    const long long INF = 0x3f3f3f3f3f3f3f3f;
    #ifdef LOCAL
    {
        // brute force
        vector dp(k + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int z = 1; z <= j; ++z) {
                    int s = pref[j] - pref[z - 1];
                    long long cost = 1LL * s * s;
                    dp[i][j] = min(dp[i][j], dp[i - 1][z - 1] + cost);
                }
            }
        }
        cout << dp[k][n] << '\n';
    }
    #endif

    {
        vector dp(k + 1, vector<long long>(n + 1, INF));
        auto dnc = [&](auto &&self, int k, int l, int r, int opt_l, int opt_r) -> void {
            if (l > r) return;
            int mid = l + (r - l) / 2;
            long long best = INF;
            int opt_point = l;
            for (int i = opt_l; i <= min(mid, opt_r); ++i) {
                int s = pref[mid] - pref[i - 1];
                long long cost = 1LL * s * s;
                if (best > dp[k - 1][i - 1] + cost) {
                    best = dp[k - 1][i - 1] + cost;
                    opt_point = i;
                }
            }
            assert(opt_point != -1);
            dp[k][mid] = best;
            self(self, k, l, mid - 1, opt_l, opt_point);
            self(self, k, mid + 1, r, opt_point, opt_r);
        };

        dp[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            dnc(dnc, i, 1, n, 1, n);
        }
        cout << dp[k][n] << '\n';
    }

    return 0;
}

/*
dp[k][n] = min cost to divide the first n elements into k sub-arrays
dp[i][j] = min{dp[i - 1][z - 1] + cost(z, j)} for 0 < z <= j
*/
