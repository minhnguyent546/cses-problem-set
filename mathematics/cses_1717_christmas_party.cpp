/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-24 21:58:42
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
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = (1LL * i * dp[i - 1] + (i & 1 ? -1 : 1)) % MOD;
        if (dp[i] < 0) dp[i] += MOD;
    }
    cout << dp[n] << '\n';
    
    return 0;
}
