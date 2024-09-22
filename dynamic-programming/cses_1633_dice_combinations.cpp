/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 11:48:25
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
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j < 0) break;
            dp[i] += dp[i - j];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }
    cout << dp[n] << '\n';
    
    return 0;
}
