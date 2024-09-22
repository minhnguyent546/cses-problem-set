/**            
 * author      minhnguyent546
 * created_at  Sat, 2024-09-14 20:36:56
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    vector dp(n + 1, vector<int>(m + 1, INF));
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= m; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                if (j <= n) dp[j][i] = 0;
                continue;
            }

            for (int ni = 1; ni < i; ++ni) {
                dp[i][j] = min(dp[i][j], dp[ni][j] + dp[i - ni][j] + 1);
            }
            for (int nj = 1; nj < j; ++nj) {
                dp[i][j] = min(dp[i][j], dp[i][nj] + dp[i][j - nj] + 1);
            }
            if (j <= n) dp[j][i] = dp[i][j];
        }
    }
    cout << dp[n][m] << '\n';
    
    return 0;
}
