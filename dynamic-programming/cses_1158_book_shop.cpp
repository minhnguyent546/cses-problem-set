/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 12:14:21
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
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (prices[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            }
            debug(i, j, dp[i][j]);
        }
    }
    cout << dp[n][x] << '\n';
    
    return 0;
}
