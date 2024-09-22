/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 12:19:20
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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    if (arr[0] == 0) {
        for (int i = 1; i <= m; ++i) dp[1][i] = 1;
    }
    else {
        dp[1][arr[0]] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        int l = 1, r = m;
        if (arr[i - 1] != 0) {
            l = r = arr[i - 1];
        }
        for (int j = l; j <= r; ++j) {
            for (int d = -1; d <= 1; ++d) {
                int nj = j + d;
                if (0 < nj && nj <= m) {
                    dp[i][j] += dp[i - 1][nj];
                    if (dp[i][j] >= MOD) dp[i][j] -= MOD;
                }
            }
        }
    }

    int ans = 0;
    int l = 1, r = m;
    if (arr[n - 1] != 0) {
        l = r = arr[n - 1];
    }
    for (int i = l; i <= r; ++i) {
        ans += dp[n][i];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
    return 0;
}
