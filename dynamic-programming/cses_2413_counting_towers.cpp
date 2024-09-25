/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-09-25 18:20:45
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif

const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 3;
int dp[2][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    dp[0][1] = dp[1][1] = 1;
    for (int i = 2; i < N; ++i) {
        dp[0][i] = (2LL * dp[0][i - 1] + dp[1][i - 1]) % MOD;
        dp[1][i] = (4LL * dp[1][i - 1] + dp[0][i - 1]) % MOD;
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int ans = dp[0][n] + dp[1][n];
        if (ans >= MOD) ans -= MOD;
        cout << ans << '\n';
    }
    
    return 0;
}

/*
Consider the grid of size 2 x n 
dp[n][0] = number of ways to build a tower such that the tile used at the i-th column is 2x1
dp[n][0] = number of ways to build a tower such that the tiles used at the i-th column are 1x1
*/
