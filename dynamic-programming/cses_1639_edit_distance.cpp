/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 16:57:13
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
    string A, B;
    cin >> A >> B;
    int n = (int) A.length(), m = (int) B.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    for (int j = 0; j <= m; ++j) dp[0][j] = j;
    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }
    cout << dp[n][m] << '\n';
    
    return 0;
}


/*
+ A[i] = B[j]
    dp[i][j] = dp[i - 1][j - 1]
+ A[i] != B[j]:
    + add to B:
        dp[i][j] = dp[i - 1][j] + 1
    + remove from B:
        dp[i][j] = dp[i][j - 1] + 1
    + replace B[j] with A[i]:
        dp[i][j] = dp[i - 1][j - 1] + 1
 */
