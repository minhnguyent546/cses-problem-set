/**            
 * author      minhnguyent546
 * created_at  Wed, 2024-07-17 12:04:58
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
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int num = 1; num <= n; ++num) {
        int cur = num;
        while (cur > 0) {
            int d = cur % 10;
            cur /= 10;
            assert(num - d >= 0);
            dp[num] = min(dp[num], dp[num - d] + 1);
        }
    }
    cout << dp[n] << '\n';
    
    return 0;
}
