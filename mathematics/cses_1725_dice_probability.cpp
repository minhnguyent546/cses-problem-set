/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-08-05 23:01:57
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
    int n, a, b;
    cin >> n >> a >> b;
    vector<long double> dp(n * 6 + 1);
    dp[0] = 1.0;
    for (int i = 1; i <= n; ++i) {
        vector<long double> next_dp(n * 6 + 1);
        for (int j = 1; j <= n * 6; ++j) {
            for (int k = 1; k <= 6 && k <= j; ++k) {
                next_dp[j] += dp[j - k];
            }
            next_dp[j] /= 6;
        }
        dp.swap(next_dp);
    }
    long double ans = accumulate(dp.begin() + a, dp.begin() + b + 1, (long double) 0.0);
    cout.precision(6);
    cout << fixed << ans << '\n';
    return 0;
}
