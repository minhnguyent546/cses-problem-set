/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 19:28:32
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
    int n;
    cin >> n;
    int s = n * (n + 1) / 2;
    if (s & 1) {
        cout << 0 << '\n';
        return 0;
    }
    int half = s / 2;
    vector<vector<int>> dp(n + 1, vector<int>(half + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= half; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (i <= j) {
                dp[i][j] += dp[i - 1][j - i];
                if (dp[i][j] >= MOD) dp[i][j] -= MOD;
            }
        }
    }    
    cout << dp[n][half] << '\n';
    return 0;
}

/*
dp[i][j]: the number of ways to create sum equal to j for the first i numbers (1..i)

 */
