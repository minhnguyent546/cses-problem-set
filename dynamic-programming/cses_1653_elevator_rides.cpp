/**            
 * author      minhnguyent546
 * created_at  Mon, 2024-07-22 01:12:18
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
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    int m = (1 << n);
    vector<pair<int, int>> dp(m, {INF, INF});
    dp[0] = {1, 0};
    for (int mask = 1; mask < m; ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                int nmask = mask ^ (1 << i);
                if (dp[nmask].second + weights[i] > x) {
                    dp[mask] = min(dp[mask], {dp[nmask].first + 1, min(dp[nmask].second, weights[i])});
                }
                else {
                    dp[mask] = min(dp[mask], {dp[nmask].first, dp[nmask].second + weights[i]});
                }
            }
        }
    }
    cout << dp[m - 1].first << '\n';
    
    return 0;
}
